#include "parser.hpp"

#include <vector>

#include "lexer.hpp"
#include "syntax_fact.hpp"
#include "syntax_node.hpp"

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

Parser::Parser(const std::string& text) : position_(0) {
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
  std::copy(lexer.Diagnostics().begin(), lexer.Diagnostics().end(),
            std::back_inserter(diagnostics_));
}

const std::vector<std::string>& Parser::Diagnostics() const {
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
  diagnostics_.push_back(
      "Parser ERROR: Unexpected token: " + ToString(current()->Kind()) +
      ". Expected: " + ToString(kind));
  return std::make_shared<const SyntaxToken>(kind, current()->Position(), "");
}

std::shared_ptr<const SyntaxTree> Parser::Parse() {
  auto expression = parse_expression();
  auto eofToken = match(SyntaxKind::EndOfFileToken);
  return std::make_shared<const SyntaxTree>(expression, diagnostics_, eofToken);
}
std::shared_ptr<const ExpressionSyntax> Parser::parse_factor() {
  auto left = parse_primary_expression();

  while (current()->Kind() == SyntaxKind::StartToken ||
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

std::shared_ptr<const ExpressionSyntax> Parser::parse_expression(
    const int parent_precedence) {
  std::shared_ptr<const simple_compiler::ExpressionSyntax> left;

  auto unary_precedence =
      SyntaxFact::GetUnaryOperatorPrecedence(current()->Kind());
  if (unary_precedence != 0 && unary_precedence >= parent_precedence) {
    auto op = std::make_shared<OperatorSyntax>(next_token());
    auto operand = parse_expression(unary_precedence);
    left =
        std::make_shared<const UnaryExpressionSyntax>(op, operand);
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
    auto right = parse_expression(precedence);
    left = std::make_shared<const BinaryExpressionSyntax>(left, op, right);
  }
  return left;
}

std::shared_ptr<const ExpressionSyntax> Parser::parse_primary_expression() {
  if (current()->Kind() == SyntaxKind::OpenParenthesisToken) {
    auto left = std::make_shared<const OpenParenthesisSyntax>(next_token());
    auto expression = parse_expression();
    auto right = std::make_shared<const CloseParenthesisSyntax>(
        match(SyntaxKind::CloseParenthesisToken));
    return std::make_shared<const ParenthesizedExpressionSyntax>(
        left, expression, right);
  }
  auto number_token = match(SyntaxKind::NumberToken);
  return std::make_shared<const NumberExpressionSyntax>(number_token);
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