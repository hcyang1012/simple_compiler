#include "bind_node.hpp"

namespace simple_compiler {
BoundUnaryExpressionNode::BoundUnaryExpressionNode(
    const std::shared_ptr<const BoundUnaryOperatorKind> operator_kind,
    const std::shared_ptr<const BoundExpressionNode> operand)
    : operator_kind_(operator_kind), operand_(operand) {}

BoundNodeKind BoundUnaryExpressionNode::Kind() const {
  return BoundNodeKind::BoundUnaryExpression;
}

ValueType BoundUnaryExpressionNode::Type() const { return operand_->Type(); };

const BoundUnaryOperatorKind& BoundUnaryExpressionNode::OperatorKind() const {
  return *operator_kind_;
}
const std::shared_ptr<const BoundExpressionNode>
BoundUnaryExpressionNode::Operand() const {
  return operand_;
}
BoundLiteralExpressionNode::BoundLiteralExpressionNode(
    const simple_compiler::Value& value)
    : value_(value) {}

BoundNodeKind BoundLiteralExpressionNode::Kind() const {
  return BoundNodeKind::BoundLiteralExpression;
}

ValueType BoundLiteralExpressionNode::Type() const { return value_.Type(); }

const simple_compiler::Value& BoundLiteralExpressionNode::Value() const {
  return value_;
}

BoundBinaryExpressionNode::BoundBinaryExpressionNode(
    const std::shared_ptr<const BoundExpressionNode> left,
    const std::shared_ptr<const BoundBinaryOperatorKind> operator_kind_,
    const std::shared_ptr<const BoundExpressionNode> right)
    : left_(left), operator_kind_(operator_kind_), right_(right) {}

BoundNodeKind BoundBinaryExpressionNode::Kind() const {
  return BoundNodeKind::BoundBinaryExpression;
}

ValueType BoundBinaryExpressionNode::Type() const { return left_->Type(); }

const std::shared_ptr<const BoundExpressionNode>
BoundBinaryExpressionNode::Left() const {
  return left_;
}

const std::shared_ptr<const BoundExpressionNode>
BoundBinaryExpressionNode::Right() const {
  return right_;
}

const BoundBinaryOperatorKind& BoundBinaryExpressionNode::OperatorKind() const {
  return *operator_kind_;
}

}  // namespace simple_compiler
