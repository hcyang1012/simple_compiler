#include "expression_statement_syntax.hpp"

namespace simple_compiler {
ExpressionStatementSyntax::ExpressionStatementSyntax(
    const std::shared_ptr<const ExpressionSyntax> expression)
    : expression_(expression) {}

std::shared_ptr<const ExpressionSyntax> ExpressionStatementSyntax::Expression()
    const {
  return expression_;
}

SyntaxKind ExpressionStatementSyntax::Kind() const {
  return SyntaxKind::ExpressionStatement;
}

std::string ExpressionStatementSyntax::ValueText() const {
  return expression_->ValueText();
}
std::vector<std::shared_ptr<const SyntaxNode>>
ExpressionStatementSyntax::GetChildren() const {
  return {expression_};
}
}  // namespace simple_compiler