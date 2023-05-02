#include "bound_assignment_expression.hpp"

namespace simple_compiler {
BoundAssignmentExpressionNode::BoundAssignmentExpressionNode(
    const std::string& name,
    const std::shared_ptr<const BoundExpressionNode> expression_node)
    : name_(name), expression_node_(expression_node) {}

std::string BoundAssignmentExpressionNode::Name() const { return name_; }

std::shared_ptr<const BoundExpressionNode>
BoundAssignmentExpressionNode::Expression() const {
  return expression_node_;
}

BoundNodeKind BoundAssignmentExpressionNode::Kind() const {
  return BoundNodeKind::BoundAssignmentExpression;
}

ValueType BoundAssignmentExpressionNode::Type() const {
  return expression_node_->Type();
}

}  // namespace simple_compiler
