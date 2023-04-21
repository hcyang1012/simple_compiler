#include "evaluator.hpp"

#include <stdexcept>

#include "syntax/parser.hpp"
#include "syntax/value_type.hpp"

namespace simple_compiler {
Evaluator::Evaluator(const std::shared_ptr<const BoundExpressionNode>& root)
    : root_(root), diagnostics_() {}

Value Evaluator::Evaluate() const {
  if (root_ == nullptr) {
    return Value(0);
  }
  return evaluate_expression(root_);
}

Value Evaluator::evaluate_expression(
    const std::shared_ptr<const BoundExpressionNode>& node) const {
  switch (node->Kind()) {
    case BoundNodeKind::BoundUnaryExpression:
      return evaluate_unary_expression(
          std::static_pointer_cast<const BoundUnaryExpressionNode>(node));
    case BoundNodeKind::BoundBinaryExpression:
      return evaluate_binary_expression(
          std::static_pointer_cast<const BoundBinaryExpressionNode>(node));
    case BoundNodeKind::BoundLiteralExpression:
      return evaluate_number_expression(
          std::static_pointer_cast<const BoundLiteralExpressionNode>(node));
  }

  throw std::runtime_error("Unexpected expression: " + node->Kind());
}

Value Evaluator::evaluate_unary_expression(
    const std::shared_ptr<const BoundUnaryExpressionNode>& node) const {
  auto operand = evaluate_expression(node->Operand());
  if (node->OperatorKind() == BoundUnaryOperatorKind::Negation) {
    return Value(-operand.AsInt());
  } else {
    return operand;
  }
}

Value Evaluator::evaluate_number_expression(
    const std::shared_ptr<const BoundLiteralExpressionNode>& node) const {
  return node->Value();
}

Value Evaluator::evaluate_binary_expression(
    const std::shared_ptr<const BoundBinaryExpressionNode>& node) const {
  auto left = evaluate_expression(node->Left());
  auto right = evaluate_expression(node->Right());

  switch (node->OperatorKind()) {
    case BoundBinaryOperatorKind::Addition:
      return Value(left.AsInt() + right.AsInt());
    case BoundBinaryOperatorKind::Subtraction:
      return Value(left.AsInt() - right.AsInt());
    case BoundBinaryOperatorKind::Multiplication:
      return Value(left.AsInt() * right.AsInt());
    case BoundBinaryOperatorKind::Division:
      return Value(left.AsInt() / right.AsInt());
  }

  throw std::runtime_error("Unexpected binary operator: " +
                           node->OperatorKind());
  return Value(0);
}

};  // namespace simple_compiler