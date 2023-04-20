#include "evaluator.hpp"

#include <stdexcept>

#include "syntax/parser.hpp"
#include "syntax/value_type.hpp"

namespace simple_compiler {
Evaluator::Evaluator(const std::shared_ptr<const ExpressionSyntax>& root)
    : root_(root), diagnostics_() {}

Value Evaluator::Evaluate() const {
  if (root_ == nullptr) {
    return Value(0);
  }
  return evaluate_expression(root_);
}

Value Evaluator::evaluate_expression(
    const std::shared_ptr<const ExpressionSyntax>& node) const {
  switch (node->Kind()) {
    case SyntaxKind::UnaryExpression:
      return evaluate_unary_expression(
          std::static_pointer_cast<const UnaryExpressionSyntax>(node));
    case SyntaxKind::BinaryExpression:
      return evaluate_binary_expression(
          std::static_pointer_cast<const BinaryExpressionSyntax>(node));
    case SyntaxKind::NumberExpression:
      return evaluate_number_expression(
          std::static_pointer_cast<const NumberExpressionSyntax>(node));
    case SyntaxKind::ParenthesisExpression:
      return evaluate_parenthesis_expression(
          std::static_pointer_cast<const ParenthesizedExpressionSyntax>(node));
  }

  throw std::runtime_error("Unexpected expression: " + node->ValueText());
}

Value Evaluator::evaluate_unary_expression(
    const std::shared_ptr<const UnaryExpressionSyntax>& node) const {
  auto operand = evaluate_expression(node->Operand());
  if (node->Operator()->Kind() == SyntaxKind::MinusToken) {
    return Value(-operand.AsInt());
  } else {
    return operand;
  }
}

Value Evaluator::evaluate_number_expression(
    const std::shared_ptr<const NumberExpressionSyntax>& node) const {
  try{
    return Value(std::stoi(node->ValueText()));
  }catch(const std::exception& ex){
    throw std::runtime_error("Unexpected number: " + node->ValueText());
  }
}

Value Evaluator::evaluate_binary_expression(
    const std::shared_ptr<const BinaryExpressionSyntax>& node) const {
  auto left = evaluate_expression(node->Left());
  auto right = evaluate_expression(node->Right());

  switch (node->Operator()->Kind()) {
    case SyntaxKind::PlusToken:
      return Value(left.AsInt() + right.AsInt());
    case SyntaxKind::MinusToken:
      return Value(left.AsInt() - right.AsInt());
    case SyntaxKind::StartToken:
      return Value(left.AsInt() * right.AsInt());
    case SyntaxKind::SlashToken:
      return Value(left.AsInt() / right.AsInt());
  }

  throw std::runtime_error("Unexpected binary operator: " +
                           node->Operator()->ValueText());
  return Value(0);
}

Value Evaluator::evaluate_parenthesis_expression(
    const std::shared_ptr<const ParenthesizedExpressionSyntax>& node) const {
  return evaluate_expression(node->Expression());
}
};  // namespace simple_compiler