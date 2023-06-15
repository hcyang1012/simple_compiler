#pragma once
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "../binding/bind_node.hpp"
#include "../binding/bound_assignment_expression.hpp"
#include "../binding/bound_binary_expression.hpp"
#include "../binding/bound_block_statement.hpp"
#include "../binding/bound_expression_statement.hpp"
#include "../binding/bound_literal_expression.hpp"
#include "../binding/bound_unary_expression.hpp"
#include "../binding/bound_variable_expression.hpp"
#include "../binding/bound_variable_declaration.hpp"
#include "../binding/bound_if_statement.hpp"
#include "../binding/bound_while_statement.hpp"
#include "../syntax/syntax_node.hpp"
#include "../syntax/value_type.hpp"

namespace simple_compiler {
class Evaluator {
 public:
  Evaluator(const std::shared_ptr<const BoundStatementNode> root,
            const std::shared_ptr<std::map<std::string, Value>> variables);
  Value Evaluate();

 private:
  std::shared_ptr<const Value> last_value_ = nullptr;
  const std::shared_ptr<const BoundStatementNode> root_;
  void evaluate_block_statement(
      const std::shared_ptr<const BoundBlockStatementNode> block);
  void evaluate_expression_statement(
      const std::shared_ptr<const BoundExpressionStatementNode> statement);
  void evaluate_variable_declaration(
      const std::shared_ptr<const BoundVariableDeclarationNode> statement);
  void evaluate_if_statement(
      const std::shared_ptr<const BoundIfStatementNode> statement);
  void evaluate_while_statement(
      const std::shared_ptr<const BoundWhileStatementNode> statement);
  void evaluate_statement(
      const std::shared_ptr<const BoundStatementNode> statment);

  Value evaluate_expression(
      const std::shared_ptr<const BoundExpressionNode>& node) const;
  Value evaluate_unary_expression(
      const std::shared_ptr<const BoundUnaryExpressionNode>& node) const;
  Value evaluate_binary_expression(
      const std::shared_ptr<const BoundBinaryExpressionNode>& node) const;
  Value evaluate_literal_expression(
      const std::shared_ptr<const BoundLiteralExpressionNode>& node) const;
  Value evaluate_variable_expression(
      const std::shared_ptr<const BoundVariableExpressionNode>& node) const;
  Value evaluate_assignment_expression(
      const std::shared_ptr<const BoundAssignmentExpressionNode>& node) const;

  const std::shared_ptr<std::map<std::string, Value>> variables_;
  std::vector<std::string> diagnostics_;
};
};  // namespace simple_compiler