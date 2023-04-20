#include "evaluator.hpp"

#include <stdexcept>

#include "syntax/parser.hpp"

namespace simple_compiler {
Evaluator::Evaluator(const std::shared_ptr<const ExpressionSyntax>& root)
    : root_(root), diagnostics_() {}

int Evaluator::Evaluate() {
  if (root_ == nullptr) {
    return 0;
  }
  return evaluate_expression(root_);
}

int Evaluator::evaluate_expression(
    const std::shared_ptr<const ExpressionSyntax>& node) {
  switch (node->Kind()) {
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

int Evaluator::evaluate_number_expression(
    const std::shared_ptr<const NumberExpressionSyntax>& node) {
  return std::stoi(node->ValueText());
}

int Evaluator::evaluate_binary_expression(
    const std::shared_ptr<const BinaryExpressionSyntax>& node) {
  auto left = evaluate_expression(node->Left());
  auto right = evaluate_expression(node->Right());

  switch (node->Operator()->Kind()) {
    case SyntaxKind::PlusToken:
      return left + right;
    case SyntaxKind::MinusToken:
      return left - right;
    case SyntaxKind::MulplicationToken:
      return left * right;
    case SyntaxKind::DivisionToken:
      return left / right;
  }

  throw std::runtime_error("Unexpected binary operator: " +
                           node->Operator()->ValueText());
  return 0;
}

int Evaluator::evaluate_parenthesis_expression(
    const std::shared_ptr<const ParenthesizedExpressionSyntax>& node) {
  return evaluate_expression(node->Expression());
}
};  // namespace simple_compiler