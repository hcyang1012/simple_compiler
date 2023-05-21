#include "evaluator.hpp"

#include <stdexcept>

#include "../syntax/parser.hpp"
#include "../syntax/value_type.hpp"

namespace simple_compiler {
Evaluator::Evaluator(
    const std::shared_ptr<const BoundStatementNode> root,
    const std::shared_ptr<std::map<std::string, Value>> variables)
    : root_(root), variables_(variables), diagnostics_() {}

Value Evaluator::Evaluate() {
  if (root_ == nullptr) {
    return Value(0);
  }
  evaluate_statement(root_);
  if (last_value_ == nullptr) {
    return Value(0);
  } else {
    return *last_value_;
  }
}

void Evaluator::evaluate_block_statement(
    const std::shared_ptr<const BoundBlockStatementNode> block) {
  for (auto statement : block->Statements()) {
    evaluate_statement(statement);
  }
}
void Evaluator::evaluate_expression_statement(
    const std::shared_ptr<const BoundExpressionStatementNode> statement) {
  last_value_ = std::make_shared<const Value>(
      evaluate_expression(statement->Expression()));
}

void Evaluator::evaluate_variable_declaration(
    const std::shared_ptr<const BoundVariableDeclarationNode> statement) {
  const auto& name = statement->Variable()->Name();
  const auto& value = evaluate_expression(statement->Initializer());
  variables_->insert_or_assign(name, value);
  last_value_ = std::make_shared<const Value>(value);
}

void Evaluator::evaluate_statement(
    const std::shared_ptr<const BoundStatementNode> statement) {
  switch (statement->Kind()) {
    case BoundNodeKind::BoundBlockStatement:
      return evaluate_block_statement(
          std::static_pointer_cast<const BoundBlockStatementNode>(statement));
    case BoundNodeKind::BoundVariableDeclarationStatement:
      return evaluate_variable_declaration(
          std::static_pointer_cast<const BoundVariableDeclarationNode>(
              statement));
    case BoundNodeKind::BoundExpressionStatement:
      return evaluate_expression_statement(
          std::static_pointer_cast<const BoundExpressionStatementNode>(
              statement));
  }
  throw std::runtime_error("Unexpected statment: " + statement->Kind());
}

Value Evaluator::evaluate_expression(
    const std::shared_ptr<const BoundExpressionNode>& node) const {
  switch (node->Kind()) {
    case BoundNodeKind::BoundUnaryExpression:
      return evaluate_unary_expression(
          std::static_pointer_cast<const BoundUnaryExpressionNode>(node));
    case BoundNodeKind::BoundVariableExpression:
      return evaluate_variable_expression(
          std::static_pointer_cast<const BoundVariableExpressionNode>(node));
    case BoundNodeKind::BoundAssignmentExpression:
      return evaluate_assignment_expression(
          std::static_pointer_cast<const BoundAssignmentExpressionNode>(node));
    case BoundNodeKind::BoundBinaryExpression:
      return evaluate_binary_expression(
          std::static_pointer_cast<const BoundBinaryExpressionNode>(node));
    case BoundNodeKind::BoundLiteralExpression:
      return evaluate_literal_expression(
          std::static_pointer_cast<const BoundLiteralExpressionNode>(node));
  }

  throw std::runtime_error("Unexpected expression: " + node->Kind());
}

Value Evaluator::evaluate_unary_expression(
    const std::shared_ptr<const BoundUnaryExpressionNode>& node) const {
  auto operand = evaluate_expression(node->Operand());
  if (node->Operator()->Kind() == BoundUnaryOperatorKind::Negation) {
    return Value(-operand.AsInt());
  } else if (node->Operator()->Kind() ==
             BoundUnaryOperatorKind::LogicalNegation) {
    return Value(!operand.AsBool());
  }
  return operand;
}

Value Evaluator::evaluate_literal_expression(
    const std::shared_ptr<const BoundLiteralExpressionNode>& node) const {
  return node->Value();
}

Value Evaluator::evaluate_binary_expression(
    const std::shared_ptr<const BoundBinaryExpressionNode>& node) const {
  auto left = evaluate_expression(node->Left());
  auto right = evaluate_expression(node->Right());

  switch (node->Operator()->Kind()) {
    case BoundBinaryOperatorKind::Addition:
      return Value(left.AsInt() + right.AsInt());
    case BoundBinaryOperatorKind::Subtraction:
      return Value(left.AsInt() - right.AsInt());
    case BoundBinaryOperatorKind::Multiplication:
      return Value(left.AsInt() * right.AsInt());
    case BoundBinaryOperatorKind::Division:
      return Value(left.AsInt() / right.AsInt());
    case BoundBinaryOperatorKind::LogicalAnd:
      return Value(left.AsBool() && right.AsBool());
    case BoundBinaryOperatorKind::LogicalOr:
      return Value(left.AsBool() || right.AsBool());
    case BoundBinaryOperatorKind::Equals:
      return Value(left.Equals(right));
    case BoundBinaryOperatorKind::NotEquals:
      return Value(!left.Equals(right));
  }

  throw std::runtime_error("Unexpected binary operator: " +
                           node->Operator()->Kind());
  return Value(0);
}

Value Evaluator::evaluate_variable_expression(
    const std::shared_ptr<const BoundVariableExpressionNode>& node) const {
  auto it = variables_->find(node->Name());
  if (it == variables_->end()) {
    throw std::runtime_error("Variable not found: " + node->Name());
  }
  return it->second;
}

Value Evaluator::evaluate_assignment_expression(
    const std::shared_ptr<const BoundAssignmentExpressionNode>& node) const {
  auto value = evaluate_expression(node->Expression());
  variables_->erase(node->Name());
  variables_->insert({node->Name(), value});
  return value;
}

};  // namespace simple_compiler