#include "bound_literal_expression.hpp"
namespace simple_compiler {

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
}  // namespace simple_compiler
