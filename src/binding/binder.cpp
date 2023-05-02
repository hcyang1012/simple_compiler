#include "binder.hpp"

#include <memory>
#include <stdexcept>

#include "../syntax/assignment_expression_syntax.hpp"
#include "../syntax/literal_expression_syntax.hpp"
#include "../syntax/name_expression_syntax.hpp"
#include "../syntax/parenthesis_expression_syntax.hpp"
#include "../syntax/value_type.hpp"
#include "bound_assignment_expression.hpp"
#include "bound_binary_expression.hpp"
#include "bound_literal_expression.hpp"
#include "bound_unary_expression.hpp"
#include "bound_unary_operator.hpp"
#include "bound_variable_expression.hpp"

namespace simple_compiler {
Binder::Binder(const std::shared_ptr<std::map<std::string, Value>> variables)
    : variables_(variables) {}

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
      return bind_parenthesized_expression(
          std::static_pointer_cast<const ParenthesizedExpressionSyntax>(
              syntax));
    case SyntaxKind::NameExpression:
      return bind_name_expression(
          std::static_pointer_cast<const NameExpressionSyntax>(syntax));
    case SyntaxKind::AssignmentExpression:
      return bind_assignment_expression(
          std::static_pointer_cast<const AssignmentExpressionSyntax>(syntax));
    default:
      throw std::runtime_error("Unexpected syntax kind: " +
                               ToString(syntax->Kind()));
  }
}

const std::shared_ptr<const DiagnosticsBag> Binder::Diagnostics() const {
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
    diagnostics_->ReportUndefinedBinaryOperator(
        syntax->Operator()->Span(), *(syntax->Operator()), bound_left->Type(),
        bound_right->Type());
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
    diagnostics_->ReportUndefinedUnaryOperator(syntax->Operator()->Span(),
                                               *(syntax->Operator()),
                                               bound_operand->Type());
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

std::shared_ptr<BoundExpressionNode> Binder::bind_parenthesized_expression(
    const std::shared_ptr<const ParenthesizedExpressionSyntax> syntax) {
  return BindExpression(syntax->Expression());
}

std::shared_ptr<BoundExpressionNode> Binder::bind_name_expression(
    const std::shared_ptr<const NameExpressionSyntax> syntax) {
  const std::string kVariableName = syntax->GetIdentifierNode()->ValueText();
  auto variable = variables_->find(kVariableName);
  if (variable == variables_->end()) {
    diagnostics_->ReportUndefinedName(syntax->GetIdentifierNode()->Span(),
                                      kVariableName);
    return std::make_shared<BoundLiteralExpressionNode>(Value(0));
  }
  return std::make_shared<BoundVariableExpressionNode>(kVariableName,
                                                       variable->second.Type());
}

std::shared_ptr<BoundExpressionNode> Binder::bind_assignment_expression(
    std::shared_ptr<const AssignmentExpressionSyntax> syntax) {
  auto name = syntax->GetIdentifierToken()->ValueText();
  auto expression = BindExpression(syntax->GetExpression());

  switch (expression->Type()) {
    case ValueType::Int:
      variables_->insert({name, Value(0)});
      break;
    case ValueType::Boolean:
      variables_->insert({name, Value(false)});
      break;
    default:
      throw std::runtime_error("Unexpected value type: " +
                               ToString(expression->Type()));
  }

  return std::make_shared<BoundAssignmentExpressionNode>(name, expression);
}

}  // namespace simple_compiler
