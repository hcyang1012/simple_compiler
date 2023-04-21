#include "bound_unary_expression.hpp"
#include "bound_unary_operator.hpp"

namespace simple_compiler {
BoundUnaryExpressionNode::BoundUnaryExpressionNode(
    const std::shared_ptr<const BoundUnaryOperatorNode> op,
    const std::shared_ptr<const BoundExpressionNode> operand)
    : operator_(op), operand_(operand) {}

BoundNodeKind BoundUnaryExpressionNode::Kind() const {
  return BoundNodeKind::BoundUnaryExpression;
}

ValueType BoundUnaryExpressionNode::Type() const { return operand_->Type(); };

const std::shared_ptr<const BoundUnaryOperatorNode> BoundUnaryExpressionNode::Operator() const {
  return operator_;
}
const std::shared_ptr<const BoundExpressionNode>
BoundUnaryExpressionNode::Operand() const {
  return operand_;
}
};  // namespace simple_compiler
