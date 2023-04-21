#pragma once
#include <memory>

#include "bind_node.hpp"
#include "bound_unary_operator.hpp"
namespace simple_compiler {

class BoundUnaryExpressionNode : public BoundExpressionNode {
 public:
  BoundUnaryExpressionNode(
      const std::shared_ptr<const BoundUnaryOperatorNode> op,
      const std::shared_ptr<const BoundExpressionNode> operand);

  BoundNodeKind Kind() const override;
  ValueType Type() const override;
  const std::shared_ptr<const BoundUnaryOperatorNode> Operator() const;
  const std::shared_ptr<const BoundExpressionNode> Operand() const;

 private:
  const std::shared_ptr<const BoundUnaryOperatorNode> operator_;
  const std::shared_ptr<const BoundExpressionNode> operand_;
};
}  // namespace simple_compiler