#pragma once
#include <memory>
#include <vector>

#include "syntax/syntax_node.hpp"
#include "syntax/value_type.hpp"

namespace simple_compiler {
class Evaluator {
 public:
  Evaluator(const std::shared_ptr<const ExpressionSyntax>& root);
  Value Evaluate() const;

 private:
  const std::shared_ptr<const ExpressionSyntax> root_;
  Value evaluate_expression(const std::shared_ptr<const ExpressionSyntax>& node) const;
  Value evaluate_unary_expression(const std::shared_ptr<const UnaryExpressionSyntax>& node) const;
  Value evaluate_binary_expression(
      const std::shared_ptr<const BinaryExpressionSyntax>& node) const;
  Value evaluate_number_expression(
      const std::shared_ptr<const NumberExpressionSyntax>& node) const;
  Value evaluate_parenthesis_expression(
      const std::shared_ptr<const ParenthesizedExpressionSyntax>& node) const;
  std::vector<std::string> diagnostics_;
};
};  // namespace simple_compiler