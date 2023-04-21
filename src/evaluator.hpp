#pragma once
#include <memory>
#include <vector>

#include "syntax/syntax_node.hpp"
#include "syntax/value_type.hpp"
#include "binding/bind_node.hpp"

namespace simple_compiler {
class Evaluator {
 public:
  Evaluator(const std::shared_ptr<const BoundExpressionNode>& root);
  Value Evaluate() const;

 private:
  const std::shared_ptr<const BoundExpressionNode> root_;
  Value evaluate_expression(const std::shared_ptr<const BoundExpressionNode>& node) const;
  Value evaluate_unary_expression(const std::shared_ptr<const BoundUnaryExpressionNode>& node) const;
  Value evaluate_binary_expression(
      const std::shared_ptr<const BoundBinaryExpressionNode>& node) const;
  Value evaluate_literal_expression(
      const std::shared_ptr<const BoundLiteralExpressionNode>& node) const;
  std::vector<std::string> diagnostics_;
};
};  // namespace simple_compiler