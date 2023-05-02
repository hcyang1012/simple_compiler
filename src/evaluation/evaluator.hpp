#pragma once
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "../binding/bind_node.hpp"
#include "../binding/bound_assignment_expression.hpp"
#include "../binding/bound_binary_expression.hpp"
#include "../binding/bound_literal_expression.hpp"
#include "../binding/bound_unary_expression.hpp"
#include "../binding/bound_variable_expression.hpp"
#include "../syntax/syntax_node.hpp"
#include "../syntax/value_type.hpp"

namespace simple_compiler {
class Evaluator {
 public:
  Evaluator(
      const std::shared_ptr<const BoundExpressionNode>& root,
      const std::shared_ptr<std::map<std::string, Value>> variables);
  Value Evaluate() const;

 private:
  const std::shared_ptr<const BoundExpressionNode> root_;
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