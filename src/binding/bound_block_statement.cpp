#include "bound_block_statement.hpp"

namespace simple_compiler {
BoundBlockStatementNode::BoundBlockStatementNode(
    const std::vector<std::shared_ptr<const BoundStatementNode>>& statements)
    : statements_(statements) {}

BoundNodeKind BoundBlockStatementNode::Kind() const {
  return BoundNodeKind::BoundBlockStatement;
}

std::vector<std::shared_ptr<const BoundStatementNode>>
BoundBlockStatementNode::Statements() const {
  return statements_;
}
}  // namespace simple_compiler
