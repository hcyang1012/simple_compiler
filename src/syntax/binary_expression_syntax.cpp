#include "binary_expression_syntax.hpp"

#include "operator_syntax.hpp"

namespace simple_compiler {
BinaryExpressionSyntax::BinaryExpressionSyntax(
    const std::shared_ptr<const ExpressionSyntax> left,
    const std::shared_ptr<const OperatorSyntax> op,
    const std::shared_ptr<const ExpressionSyntax> right)
    : left_(left), operator_(op), right_(right) {}

std::shared_ptr<const ExpressionSyntax> BinaryExpressionSyntax::Left() const {
  return left_;
}
std::shared_ptr<const OperatorSyntax> BinaryExpressionSyntax::Operator() const {
  return operator_;
}
std::shared_ptr<const ExpressionSyntax> BinaryExpressionSyntax::Right() const {
  return right_;
}
SyntaxKind BinaryExpressionSyntax::Kind() const {
  return SyntaxKind::BinaryExpression;
}
std::vector<std::shared_ptr<const SyntaxNode>>
BinaryExpressionSyntax::GetChildren() const {
  std::vector<std::shared_ptr<const SyntaxNode>> children;
  children.push_back(left_);
  children.push_back(operator_);
  children.push_back(right_);
  return children;
}

TextSpan BinaryExpressionSyntax::Span() const { return operator_->Span(); }
}  // namespace simple_compiler