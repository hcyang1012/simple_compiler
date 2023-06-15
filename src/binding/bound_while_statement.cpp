#include "bound_while_statement.hpp"

namespace simple_compiler {

BoundWhileStatementNode::BoundWhileStatementNode(
    std::shared_ptr<const BoundExpressionNode> condition,
    std::shared_ptr<const BoundStatementNode> body)
    : condition_(condition), body_(body) {}

BoundNodeKind BoundWhileStatementNode::Kind() const {
  return BoundNodeKind::BoundWhileStatement;
}

std::shared_ptr<const BoundExpressionNode>
BoundWhileStatementNode::GetCondition() const {
  return condition_;
}

std::shared_ptr<const BoundStatementNode> BoundWhileStatementNode::GetBody()
    const {
  return body_;
}

}  // namespace simple_compiler