#pragma once
#include <memory>
#include <vector>

#include "syntax/syntax_node.hpp"

namespace simple_compiler {
class Evaluator {
 public:
  Evaluator(const std::shared_ptr<const ExpressionSyntax>& root);
  int Evaluate();

 private:
  const std::shared_ptr<const ExpressionSyntax> root_;
  int evaluate_expression(const std::shared_ptr<const ExpressionSyntax>& node);
  int evaluate_binary_expression(
      const std::shared_ptr<const BinaryExpressionSyntax>& node);
  int evaluate_number_expression(
      const std::shared_ptr<const NumberExpressionSyntax>& node);
  int evaluate_parenthesis_expression(
      const std::shared_ptr<const ParenthesizedExpressionSyntax>& node);
  std::vector<std::string> diagnostics_;
};
};  // namespace simple_compiler