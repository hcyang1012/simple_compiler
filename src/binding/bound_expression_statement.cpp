#include "bound_expression_statement.hpp"

namespace simple_compiler {
BoundExpressionStatementNode::BoundExpressionStatementNode(
    std::shared_ptr<const BoundExpressionNode> expression)
    : expression_(expression) {}

BoundNodeKind BoundExpressionStatementNode::Kind() const {
  return BoundNodeKind::BoundExpressionStatement;
}

std::shared_ptr<const BoundExpressionNode>
BoundExpressionStatementNode::Expression() const {
  return expression_;
}
}  // namespace simple_compiler