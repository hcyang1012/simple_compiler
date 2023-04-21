#pragma once
#include <memory>
#include <string>
#include <vector>

#include "../syntax/syntax_node.hpp"
#include "binding/bind_node.hpp"
#include "binding/bound_binary_expression.hpp"
#include "binding/bound_literal_expression.hpp"
#include "binding/bound_unary_expression.hpp"
namespace simple_compiler {
class Binder {
 public:
  std::shared_ptr<BoundExpressionNode> BindExpression(
      const std::shared_ptr<const ExpressionSyntax> syntax);
  const std::vector<std::string>& Diagnostics() const;

 private:
  std::vector<std::string> diagnostics_;
  std::shared_ptr<BoundExpressionNode> bind_literal_expression(
      const std::shared_ptr<const LiteralExpressionSyntax> syntax);
  std::shared_ptr<BoundExpressionNode> bind_binary_expression(
      const std::shared_ptr<const BinaryExpressionSyntax> syntax);
  std::shared_ptr<BoundExpressionNode> bind_unary_expression(
      const std::shared_ptr<const UnaryExpressionSyntax> syntax);
  std::shared_ptr<BoundUnaryOperatorKind> bind_unary_operator_kind(
      const SyntaxKind kind, const ValueType type);
  std::shared_ptr<BoundBinaryOperatorKind> bind_binary_operator_kind(
      const SyntaxKind kindl, const ValueType left_type,
      const ValueType right_type);
};
}  // namespace simple_compiler