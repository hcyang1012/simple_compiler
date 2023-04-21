#pragma once
#include <memory>

#include "../syntax/value_type.hpp"
#include "bind_node.hpp"
#include "bound_binary_operator.hpp"

namespace simple_compiler {


class BoundBinaryExpressionNode : public BoundExpressionNode {
 public:
  BoundBinaryExpressionNode(
      const std::shared_ptr<const BoundExpressionNode> left,
      const std::shared_ptr<const BoundBinaryOperatorNode> op,
      const std::shared_ptr<const BoundExpressionNode> right);

  BoundNodeKind Kind() const override;
  ValueType Type() const override;
  const std::shared_ptr<const BoundExpressionNode> Left() const;
  const std::shared_ptr<const BoundExpressionNode> Right() const;
  const std::shared_ptr<const BoundBinaryOperatorNode> Operator() const;

 private:
  const std::shared_ptr<const BoundExpressionNode> left_;
  const std::shared_ptr<const BoundBinaryOperatorNode> operator_;
  const std::shared_ptr<const BoundExpressionNode> right_;
};
}  // namespace simple_compiler