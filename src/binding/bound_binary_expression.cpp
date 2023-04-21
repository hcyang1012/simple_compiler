#include "bound_binary_expression.hpp"

namespace simple_compiler {
BoundBinaryExpressionNode::BoundBinaryExpressionNode(
    const std::shared_ptr<const BoundExpressionNode> left,
    const std::shared_ptr<const BoundBinaryOperatorNode> op,
    const std::shared_ptr<const BoundExpressionNode> right)
    : left_(left), operator_(op), right_(right) {}

BoundNodeKind BoundBinaryExpressionNode::Kind() const {
  return BoundNodeKind::BoundBinaryExpression;
}

ValueType BoundBinaryExpressionNode::Type() const {
  return operator_->ResultType();
}

const std::shared_ptr<const BoundExpressionNode>
BoundBinaryExpressionNode::Left() const {
  return left_;
}

const std::shared_ptr<const BoundExpressionNode>
BoundBinaryExpressionNode::Right() const {
  return right_;
}

const std::shared_ptr<const BoundBinaryOperatorNode>
BoundBinaryExpressionNode::Operator() const {
  return operator_;
}
}  // namespace simple_compiler
