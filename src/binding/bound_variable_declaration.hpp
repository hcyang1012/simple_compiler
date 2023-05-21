#pragma once
#include <memory>

#include "../syntax/variable_symbol.hpp"
#include "bind_node.hpp"
namespace simple_compiler {
class BoundVariableDeclarationNode : public BoundStatementNode {
 public:
  BoundVariableDeclarationNode(std::shared_ptr<const VariableSymbol> variable,
                             std::shared_ptr<const BoundExpressionNode> initializer);
  std::shared_ptr<const VariableSymbol> Variable() const;
  std::shared_ptr<const BoundExpressionNode> Initializer() const;
  BoundNodeKind Kind() const override;

 private:
  std::shared_ptr<const VariableSymbol> variable_;
  std::shared_ptr<const BoundExpressionNode> initializer_;
};
}  // namespace simple_compiler