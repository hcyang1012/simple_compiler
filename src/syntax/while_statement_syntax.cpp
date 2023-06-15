#include "while_statement_syntax.hpp"

namespace simple_compiler {
WhileKeywordSyntax::WhileKeywordSyntax(
    std::shared_ptr<const SyntaxToken> whileKeyword)
    : whileKeyword_(whileKeyword) {}
std::shared_ptr<const SyntaxToken> WhileKeywordSyntax::GetToken() const {
  return whileKeyword_;
}

SyntaxKind WhileKeywordSyntax::Kind() const { return SyntaxKind::WhileKeyword; }

WhileStatementSyntax::WhileStatementSyntax(
    std::shared_ptr<const WhileKeywordSyntax> whileKeyword,
    std::shared_ptr<const ExpressionSyntax> condition,
    std::shared_ptr<const StatementSyntax> body)
    : whileKeyword_(whileKeyword), condition_(condition), body_(body) {}

SyntaxKind WhileStatementSyntax::Kind() const {
  return SyntaxKind::WhileStatement;
}

std::shared_ptr<const WhileKeywordSyntax>
WhileStatementSyntax::GetWhileKeyword() const {
  return whileKeyword_;
}
std::shared_ptr<const ExpressionSyntax> WhileStatementSyntax::GetCondition()
    const {
  return condition_;
}
std::shared_ptr<const StatementSyntax> WhileStatementSyntax::GetBody() const {
  return body_;
}

std::vector<std::shared_ptr<const SyntaxNode>>
WhileStatementSyntax::GetChildren() const {
  std::vector<std::shared_ptr<const SyntaxNode>> children;
  children.push_back(whileKeyword_);
  children.push_back(condition_);
  children.push_back(body_);
  return children;
}
}  // namespace simple_compiler