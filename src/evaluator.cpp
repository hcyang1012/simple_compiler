#include "evaluator.hpp"

#include <stdexcept>

#include "syntax/parser.hpp"

namespace simple_compiler {
Evaluator::Evaluator(const std::shared_ptr<const ExpressionSyntax>& root)
    : root_(root), diagnostics_() {}

int Evaluator::Evaluate() const {
  if (root_ == nullptr) {
    return 0;
  }
  return evaluate_expression(root_);
}

int Evaluator::evaluate_expression(
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

int Evaluator::evaluate_unary_expression(
    const std::shared_ptr<const UnaryExpressionSyntax>& node) const {
  auto operand = evaluate_expression(node->Operand());
  if (node->Operator()->Kind() == SyntaxKind::MinusToken) {
    return -operand;
  } else {
    return operand;
  }
}

int Evaluator::evaluate_number_expression(
    const std::shared_ptr<const NumberExpressionSyntax>& node) const {
  try{
    return std::stoi(node->ValueText());
  }catch(const std::exception& ex){
    throw std::runtime_error("Unexpected number: " + node->ValueText());
  }
}

int Evaluator::evaluate_binary_expression(
    const std::shared_ptr<const BinaryExpressionSyntax>& node) const {
  auto left = evaluate_expression(node->Left());
  auto right = evaluate_expression(node->Right());

  switch (node->Operator()->Kind()) {
    case SyntaxKind::PlusToken:
      return left + right;
    case SyntaxKind::MinusToken:
      return left - right;
    case SyntaxKind::StartToken:
      return left * right;
    case SyntaxKind::SlashToken:
      return left / right;
  }

  throw std::runtime_error("Unexpected binary operator: " +
                           node->Operator()->ValueText());
  return 0;
}

int Evaluator::evaluate_parenthesis_expression(
    const std::shared_ptr<const ParenthesizedExpressionSyntax>& node) const {
  return evaluate_expression(node->Expression());
}
};  // namespace simple_compiler