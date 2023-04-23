#include "binder.hpp"

#include <stdexcept>

#include "bound_binary_expression.hpp"
#include "bound_literal_expression.hpp"
#include "bound_unary_expression.hpp"
#include "bound_unary_operator.hpp"

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
    case SyntaxKind::ParenthesisExpression:
      return BindExpression(
          std::static_pointer_cast<const ParenthesizedExpressionSyntax>(syntax)
              ->Expression());
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
    bool bool_value = syntax->LiteralToken()->Kind() == SyntaxKind::TrueKeyword;
    value = std::make_shared<Value>(bool_value);
  }
  return std::make_shared<BoundLiteralExpressionNode>(*value);
}

std::shared_ptr<BoundExpressionNode> Binder::bind_binary_expression(
    const std::shared_ptr<const BinaryExpressionSyntax> syntax) {
  auto bound_left = BindExpression(syntax->Left());
  auto bound_right = BindExpression(syntax->Right());
  auto bound_operator = BoundBinaryOperatorNode::Bind(
      syntax->Operator()->Kind(), bound_left->Type(), bound_right->Type());
  if (bound_operator == nullptr) {
    diagnostics_.push_back(
        "Binary operator '" + syntax->Operator()->ValueText() +
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
  auto bound_operator = BoundUnaryOperatorNode::Bind(syntax->Operator()->Kind(),
                                                     bound_operand->Type());
  if (bound_operator == nullptr) {
    diagnostics_.push_back(
        "Unary operator '" + syntax->Operator()->ValueText() +
        "' is not defined for type '" + ToString(bound_operand->Type()) + "'.");
    return bound_operand;
  }
  return std::make_shared<BoundUnaryExpressionNode>(bound_operator,
                                                    bound_operand);
}

std::shared_ptr<BoundUnaryOperatorKind> Binder::bind_unary_operator_kind(
    const SyntaxKind kind, const ValueType type) {
  if (type == ValueType::Boolean) {
    switch (kind) {
      case SyntaxKind::BangToken:
        return std::make_shared<BoundUnaryOperatorKind>(
            BoundUnaryOperatorKind::LogicalNegation);
    }
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
  if (left_type == ValueType::Int && right_type == ValueType::Int) {
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
  if (left_type == ValueType::Boolean && right_type == ValueType::Boolean) {
    switch (kind) {
      case SyntaxKind::AmpersandAmpersandToken:
        return std::make_shared<BoundBinaryOperatorKind>(
            BoundBinaryOperatorKind::LogicalAnd);
      case SyntaxKind::PipePipeToken:
        return std::make_shared<BoundBinaryOperatorKind>(
            BoundBinaryOperatorKind::LogicalOr);
      default:
        throw std::runtime_error("Unexpected syntax kind: " + ToString(kind));
    }
  }
  return nullptr;
}

}  // namespace simple_compiler
