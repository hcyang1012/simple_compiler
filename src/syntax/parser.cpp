#include "parser.hpp"

#include <vector>

#include "assignment_expression_syntax.hpp"
#include "binary_expression_syntax.hpp"
#include "close_parenthesis_syntax.hpp"
#include "diagnostics/diagnostics_bag.hpp"
#include "identifier_syntax.hpp"
#include "lexer.hpp"
#include "literal_expression_syntax.hpp"
#include "name_expression_syntax.hpp"
#include "open_parenthesis_syntax.hpp"
#include "parenthesis_expression_syntax.hpp"
#include "syntax_fact.hpp"
#include "syntax_node.hpp"
#include "unary_expression_syntax.hpp"
namespace simple_compiler {

/**
 *
 * 1 + 2 * 3
 *
 *     +
 *    / \
 *    *  3
 *   / \
 *  1   2
 */

Parser::Parser(const TextSource& text) : text_(text), position_(0) {
  tokens_.clear();
  Lexer lexer(text);
  std::shared_ptr<SyntaxToken> token = nullptr;
  do {
    token = lexer.NextToken();
    if (token->Kind() != SyntaxKind::WhiteSpaceToken &&
        token->Kind() != SyntaxKind::BadToken) {
      tokens_.push_back(token);
    }

  } while (token != nullptr && token->Kind() != SyntaxKind::EndOfFileToken);
  diagnostics_->AddRange(*(lexer.Diagnostics()));
}

const std::shared_ptr<const DiagnosticsBag> Parser::Diagnostics() const {
  return diagnostics_;
}

std::shared_ptr<const SyntaxToken> Parser::next_token() {
  const auto current = this->current();
  position_++;
  return current;
}

std::shared_ptr<const SyntaxToken> Parser::match(const SyntaxKind kind) {
  if (current()->Kind() == kind) {
    return next_token();
  }
  diagnostics_->ReportUnexpectedToken(current()->Span(), current()->Kind(),
                                      kind);
  return std::make_shared<const SyntaxToken>(kind, current()->Position(), "");
}

std::shared_ptr<const CompilationUnitSyntax> Parser::ParseCompilationUnit() {
  auto statement = parse_statement();
  auto eofToken = match(SyntaxKind::EndOfFileToken);
  return std::make_shared<const CompilationUnitSyntax>(statement, eofToken);
}
std::shared_ptr<const ExpressionSyntax> Parser::parse_factor() {
  auto left = parse_primary_expression();

  while (current()->Kind() == SyntaxKind::StarToken ||
         current()->Kind() == SyntaxKind::SlashToken) {
    auto op = std::make_shared<const OperatorSyntax>(next_token());
    auto right = parse_primary_expression();
    left = std::make_shared<const BinaryExpressionSyntax>(left, op, right);
  }
  return left;
}

std::shared_ptr<const ExpressionSyntax> Parser::parse_term() {
  auto left = parse_factor();
  while (current()->Kind() == SyntaxKind::PlusToken ||
         current()->Kind() == SyntaxKind::MinusToken) {
    auto op = std::make_shared<const OperatorSyntax>(next_token());
    auto right = parse_factor();
    left = std::make_shared<const BinaryExpressionSyntax>(left, op, right);
  }
  return left;
}

std::shared_ptr<const StatementSyntax> Parser::parse_statement() {
  if (current()->Kind() == SyntaxKind::OpenBraceToken) {
    return parse_block_statement();
  }

  if (current()->Kind() == SyntaxKind::LetKeyword ||
      current()->Kind() == SyntaxKind::VarKeyword) {
    return parse_variable_declaration();
  }

  if (current()->Kind() == SyntaxKind::IfKeyword) {
    return parse_if_statement();
  }

  return parse_expression_statement();
}

std::shared_ptr<const BlockStatementSyntax> Parser::parse_block_statement() {
  std::vector<std::shared_ptr<const StatementSyntax>> statements;
  auto open_brace_syntax = std::make_shared<const OpenBraceSyntax>(
      match(SyntaxKind::OpenBraceToken));
  while (current()->Kind() != SyntaxKind::EndOfFileToken &&
         current()->Kind() != SyntaxKind::CloseBraceToken) {
    auto statement = parse_statement();
    statements.push_back(statement);
  }
  auto close_brace_syntax = std::make_shared<const CloseBraceSyntax>(
      match(SyntaxKind::CloseBraceToken));
  return std::make_shared<const BlockStatementSyntax>(
      open_brace_syntax, statements, close_brace_syntax);
}

std::shared_ptr<const ExpressionStatementSyntax>
Parser::parse_expression_statement() {
  auto expression = parse_expression();
  return std::make_shared<const ExpressionStatementSyntax>(expression);
}

std::shared_ptr<const VariableDeclarationSyntax>
Parser::parse_variable_declaration() {
  auto expected = current()->Kind() == SyntaxKind::LetKeyword
                      ? SyntaxKind::LetKeyword
                      : SyntaxKind::VarKeyword;
  auto keyword = match(expected);
  auto identifier = match(SyntaxKind::IdentifierToken);
  auto equals = match(SyntaxKind::EqualsToken);
  auto initializer = parse_expression();
  return std::make_shared<const VariableDeclarationSyntax>(keyword, identifier,
                                                           equals, initializer);
}

std::shared_ptr<const IfStatementSyntax> Parser::parse_if_statement() {
  auto keyword = match(SyntaxKind::IfKeyword);
  auto condition = parse_expression();
  auto statement = parse_statement();
  auto elseClause = parse_else_clause();
  return std::make_shared<const IfStatementSyntax>(keyword, condition,
                                                   statement, elseClause);
}

std::shared_ptr<const ElseClauseSyntax> Parser::parse_else_clause() {
  if (current()->Kind() != SyntaxKind::ElseKeyword) {
    return nullptr;
  }
  auto keyword = match(SyntaxKind::ElseKeyword);
  auto statement = parse_statement();
  return std::make_shared<const ElseClauseSyntax>(keyword, statement);
}

std::shared_ptr<const ExpressionSyntax> Parser::parse_expression() {
  return parse_assignment_expression();
}

std::shared_ptr<const ExpressionSyntax> Parser::parse_assignment_expression() {
  if (peek(0)->Kind() == SyntaxKind::IdentifierToken &&
      peek(1)->Kind() == SyntaxKind::EqualsToken) {
    auto identifier_syntax =
        std::make_shared<const IdentifierSyntax>(next_token());
    auto op = std::make_shared<const OperatorSyntax>(next_token());
    auto right = parse_assignment_expression();
    return std::make_shared<const AssignmentExpressionSyntax>(identifier_syntax,
                                                              op, right);
  }
  return parse_binary_expression();
}

std::shared_ptr<const ExpressionSyntax> Parser::parse_binary_expression(
    const int parent_precedence) {
  std::shared_ptr<const simple_compiler::ExpressionSyntax> left;

  auto unary_precedence =
      SyntaxFact::GetUnaryOperatorPrecedence(current()->Kind());
  if (unary_precedence != 0 && unary_precedence >= parent_precedence) {
    auto op = std::make_shared<OperatorSyntax>(next_token());
    auto operand = parse_binary_expression(unary_precedence);
    left = std::make_shared<const UnaryExpressionSyntax>(op, operand);
  } else {
    left = parse_primary_expression();
  }

  while (true) {
    auto precedence =
        SyntaxFact::GetBinaryOperatorPrecedence(current()->Kind());
    if (precedence == 0 || precedence <= parent_precedence) {
      break;
    }
    auto op = std::make_shared<const OperatorSyntax>(next_token());
    auto right = parse_binary_expression(precedence);
    left = std::make_shared<const BinaryExpressionSyntax>(left, op, right);
  }
  return left;
}

std::shared_ptr<const ExpressionSyntax> Parser::parse_primary_expression() {
  if (current()->Kind() == SyntaxKind::OpenParenthesisToken) {
    auto left = std::make_shared<const OpenParenthesisSyntax>(next_token());
    auto expression = (parse_expression());
    auto right = std::make_shared<const CloseParenthesisSyntax>(
        match(SyntaxKind::CloseParenthesisToken));
    return std::make_shared<const ParenthesizedExpressionSyntax>(
        left, expression, right);
  }

  if (current()->Kind() == SyntaxKind::TrueKeyword ||
      current()->Kind() == SyntaxKind::FalseKeyword) {
    auto keyword_token = next_token();
    Value value(keyword_token->Kind() == SyntaxKind::TrueKeyword);
    return std::make_shared<const LiteralExpressionSyntax>(keyword_token,
                                                           value);
  }

  if (current()->Kind() == SyntaxKind::IdentifierToken) {
    return std::make_shared<const NameExpressionSyntax>(
        std::make_shared<const IdentifierSyntax>(next_token()));
  }

  auto number_token = match(SyntaxKind::NumberToken);
  int number_value = 0;
  try {
    number_value = std::stoi(number_token->Text());
  } catch (const std::exception& e) {
  }
  Value value(number_value);
  return std::make_shared<const LiteralExpressionSyntax>(number_token, value);
}

std::shared_ptr<const SyntaxToken> Parser::peek(const size_t offset) const {
  const size_t kIndex = position_ + offset;
  if (kIndex >= tokens_.size()) {
    return tokens_.back();
  }
  return tokens_[kIndex];
};

std::shared_ptr<const SyntaxToken> Parser::current() const { return peek(0); };
};  // namespace simple_compiler