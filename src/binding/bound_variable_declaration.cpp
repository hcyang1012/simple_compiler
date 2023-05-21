#include "bound_variable_declaration.hpp"

namespace simple_compiler {
BoundVariableDeclarationNode::BoundVariableDeclarationNode(
    std::shared_ptr<const VariableSymbol> variable,
    std::shared_ptr<const BoundExpressionNode> initializer)
    : variable_(variable), initializer_(initializer) {}

std::shared_ptr<const VariableSymbol> BoundVariableDeclarationNode::Variable()
    const {
  return variable_;
}

std::shared_ptr<const BoundExpressionNode>
BoundVariableDeclarationNode::Initializer() const {
  return initializer_;
}

BoundNodeKind BoundVariableDeclarationNode::Kind() const {
  return BoundNodeKind::BoundVariableDeclarationStatement;
}
}  // namespace simple_compiler