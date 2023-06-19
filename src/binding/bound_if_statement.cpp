#include "bound_if_statement.hpp"
namespace simple_compiler {

BoundIfStatementNode::BoundIfStatementNode(
    std::shared_ptr<const BoundExpressionNode> condition,
    std::shared_ptr<const BoundStatementNode> then_statement,
    std::shared_ptr<const BoundStatementNode> else_statement)
    : condition_(condition),
      then_statement_(then_statement),
      else_statement_(else_statement) {}

BoundNodeKind BoundIfStatementNode::Kind() const {
  return BoundNodeKind::BoundIfStatement;
}

std::shared_ptr<const BoundExpressionNode> BoundIfStatementNode::Condition()
    const {
  return condition_;
}

std::shared_ptr<const BoundStatementNode> BoundIfStatementNode::ThenStatement()
    const {
  return then_statement_;
}

std::shared_ptr<const BoundStatementNode> BoundIfStatementNode::ElseStatement()
    const {
  return else_statement_;
}

}  // namespace simple_compiler
