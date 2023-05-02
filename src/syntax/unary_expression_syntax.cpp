#include "unary_expression_syntax.hpp"

namespace simple_compiler {
UnaryExpressionSyntax::UnaryExpressionSyntax(
    const std::shared_ptr<const OperatorSyntax> op,
    const std::shared_ptr<const ExpressionSyntax> operand)
    : operator_(op), operand_(operand) {}

std::shared_ptr<const OperatorSyntax> UnaryExpressionSyntax::Operator() const {
  return operator_;
}

std::shared_ptr<const ExpressionSyntax> UnaryExpressionSyntax::Operand() const {
  return operand_;
}

SyntaxKind UnaryExpressionSyntax::Kind() const {
  return SyntaxKind::UnaryExpression;
}

std::vector<std::shared_ptr<const SyntaxNode>>
UnaryExpressionSyntax::GetChildren() const {
  std::vector<std::shared_ptr<const SyntaxNode>> children;
  children.push_back(operator_);
  children.push_back(operand_);
  return children;
}

TextSpan UnaryExpressionSyntax::Span() const { return operator_->Span(); }
}  // namespace simple_compiler