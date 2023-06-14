#include "if_statement_syntax.hpp"

namespace simple_compiler {

IfKeywordSyntax::IfKeywordSyntax(std::shared_ptr<const SyntaxToken> token) {}

SyntaxKind IfKeywordSyntax::Kind() const { return SyntaxKind::IfKeyword; }

std::shared_ptr<const SyntaxToken> IfKeywordSyntax::GetToken() const {
  return token_;
}

ElseKeywordSyntax::ElseKeywordSyntax(std::shared_ptr<const SyntaxToken> token) {
}

SyntaxKind ElseKeywordSyntax::Kind() const { return SyntaxKind::ElseKeyword; }

std::shared_ptr<const SyntaxToken> ElseKeywordSyntax::GetToken() const {
  return token_;
}

ElseClauseSyntax::ElseClauseSyntax(
    const std::shared_ptr<const ElseKeywordSyntax> else_keyword,
    const std::shared_ptr<const StatementSyntax> else_statement)
    : else_keyword_(else_keyword), else_statement_(else_statement) {}

std::shared_ptr<const ElseKeywordSyntax> ElseClauseSyntax::ElseKeyword() const {
  return else_keyword_;
}

std::shared_ptr<const StatementSyntax> ElseClauseSyntax::ElseStatement() const {
  return else_statement_;
}

SyntaxKind ElseClauseSyntax::Kind() const { return SyntaxKind::ElaseClause; }

TextSpan ElseClauseSyntax::Span() const {
  return TextSpan(else_keyword_->Span().Start(), else_statement_->Span().End());
}

std::vector<std::shared_ptr<const SyntaxNode>> ElseClauseSyntax::GetChildren()
    const {
  return std::vector<std::shared_ptr<const SyntaxNode>>{else_keyword_,
                                                        else_statement_};
}

IfStatementSyntax::IfStatementSyntax(
    const std::shared_ptr<const IfKeywordSyntax> if_keyword,
    const std::shared_ptr<const ExpressionSyntax> condition,
    const std::shared_ptr<const StatementSyntax> then_statement,
    const std::shared_ptr<const ElseClauseSyntax> else_clause)
    : if_keyword_(if_keyword),
      condition_(condition),
      then_statement_(then_statement),
      else_clause_(else_clause) {}

std::shared_ptr<const IfKeywordSyntax> IfStatementSyntax::IfKeyword() const {
  return if_keyword_;
}

std::shared_ptr<const ExpressionSyntax> IfStatementSyntax::Condition() const {
  return condition_;
}

std::shared_ptr<const StatementSyntax> IfStatementSyntax::ThenStatement()
    const {
  return then_statement_;
}

std::shared_ptr<const ElseClauseSyntax> IfStatementSyntax::ElseClause() const {
  return else_clause_;
}

std::vector<std::shared_ptr<const SyntaxNode>> IfStatementSyntax::GetChildren()
    const {
  if (else_clause_ == nullptr) {
    return std::vector<std::shared_ptr<const SyntaxNode>>{
        if_keyword_, condition_, then_statement_};
  }
  return std::vector<std::shared_ptr<const SyntaxNode>>{
      if_keyword_, condition_, then_statement_, else_clause_};
}

SyntaxKind IfStatementSyntax::Kind() const { return SyntaxKind::IfStatement; }

}  // namespace simple_compiler