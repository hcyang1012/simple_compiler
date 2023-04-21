#include "binder.hpp"

#include <stdexcept>

namespace simple_compiler {
std::shared_ptr<BoundExpressionNode> Binder::BindExpression(
    const std::shared_ptr<const ExpressionSyntax> syntax) {
  switch (syntax->Kind()) {
    case SyntaxKind::LiteralExpression:
      return bind_literal_expression(
          std::static_pointer_cast<const LiteralExpressionSyntax>(syntax));
    case SyntaxKind::BinaryExpression:
      return bind_binary_expression(
          std::static_pointer_cast<const BinaryExpressionSyntax>(syntax));
    case SyntaxKind::UnaryExpression:
      return bind_unary_expression(
          std::static_pointer_cast<const UnaryExpressionSyntax>(syntax));
    default:
      throw std::runtime_error("Unexpected syntax kind: " +
                               ToString(syntax->Kind()));
  }
}

const std::vector<std::string>& Binder::Diagnostics() const {
  return diagnostics_;
}

std::shared_ptr<BoundExpressionNode> Binder::bind_literal_expression(
    const std::shared_ptr<const LiteralExpressionSyntax> syntax) {
  std::shared_ptr<Value> value;
  try {
    int int_value = std::stoi(syntax->ValueText());
    value = std::make_shared<Value>(int_value);
  } catch (std::exception& e) {
    value = std::make_shared<Value>(0);
  }
  return std::make_shared<BoundLiteralExpressionNode>(*value);
}

std::shared_ptr<BoundExpressionNode> Binder::bind_binary_expression(
    const std::shared_ptr<const BinaryExpressionSyntax> syntax) {
  auto bound_left = BindExpression(syntax->Left());
  auto bound_right = BindExpression(syntax->Right());
  auto bound_operator =
      bind_binary_operator_kind(syntax->Operator()->OperatorToken()->Kind(),
                                bound_left->Type(), bound_right->Type());
  if (bound_operator == nullptr) {
    diagnostics_.push_back(
        "Binary operator '" +
        ToString(syntax->Operator()->OperatorToken()->Kind()) +
        "' is not defined for types '" + ToString(bound_left->Type()) +
        "' and '" + ToString(bound_right->Type()) + "'.");
    return bound_left;
  }
  return std::make_shared<BoundBinaryExpressionNode>(bound_left, bound_operator,
                                                     bound_right);
}

std::shared_ptr<BoundExpressionNode> Binder::bind_unary_expression(
    const std::shared_ptr<const UnaryExpressionSyntax> syntax) {
  auto bound_operand = BindExpression(syntax->Operand());
  auto bound_operator = bind_unary_operator_kind(syntax->Operator()->Kind(),
                                                 bound_operand->Type());
  if (bound_operand == nullptr) {
    diagnostics_.push_back(
        "Unary operator '" + ToString(syntax->Operator()->Kind()) +
        "' is not defined for type '" + ToString(bound_operand->Type()) + "'.");
    return bound_operand;
  }
  return std::make_shared<BoundUnaryExpressionNode>(bound_operator,
                                                    bound_operand);
}

std::shared_ptr<BoundUnaryOperatorKind> Binder::bind_unary_operator_kind(
    const SyntaxKind kind, const ValueType type) {
  if (type != ValueType::Int) {
    return nullptr;
  }

  switch (kind) {
    case SyntaxKind::PlusToken:
      return std::make_shared<BoundUnaryOperatorKind>(
          BoundUnaryOperatorKind::Identity);
    case SyntaxKind::MinusToken:
      return std::make_shared<BoundUnaryOperatorKind>(
          BoundUnaryOperatorKind::Negation);
    default:
      throw std::runtime_error("Unexpected syntax kind: " + ToString(kind));
  }
}

std::shared_ptr<BoundBinaryOperatorKind> Binder::bind_binary_operator_kind(
    const SyntaxKind kind, const ValueType left_type,
    const ValueType right_type) {
  if (left_type != ValueType::Int || right_type != ValueType::Int) {
    return nullptr;
  }
  switch (kind) {
    case SyntaxKind::PlusToken:
      return std::make_shared<BoundBinaryOperatorKind>(
          BoundBinaryOperatorKind::Addition);
    case SyntaxKind::MinusToken:
      return std::make_shared<BoundBinaryOperatorKind>(
          BoundBinaryOperatorKind::Subtraction);
    case SyntaxKind::StarToken:
      return std::make_shared<BoundBinaryOperatorKind>(
          BoundBinaryOperatorKind::Multiplication);
    case SyntaxKind::SlashToken:
      return std::make_shared<BoundBinaryOperatorKind>(
          BoundBinaryOperatorKind::Division);
    default:

      throw std::runtime_error("Unexpected syntax kind: " + ToString(kind));
  }
}

}  // namespace simple_compiler
