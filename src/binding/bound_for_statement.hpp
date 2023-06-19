#pragma once
#include <memory>

#include "../syntax/variable_symbol.hpp"
#include "bind_node.hpp"

namespace simple_compiler {

class BoundForStatementNode : public BoundStatementNode {
 public:
  BoundForStatementNode(std::shared_ptr<const VariableSymbol> variable,
                        std::shared_ptr<const BoundExpressionNode> lower_bound,
                        std::shared_ptr<const BoundExpressionNode> upper_bound,
                        std::shared_ptr<const BoundStatementNode> body);

  BoundNodeKind Kind() const override;
  std::shared_ptr<const VariableSymbol> Variable() const;
  std::shared_ptr<const BoundExpressionNode> LowerBound() const;
  std::shared_ptr<const BoundExpressionNode> UpperBound() const;
  std::shared_ptr<const BoundStatementNode> Body() const;

 private:
  std::shared_ptr<const VariableSymbol> variable_;
  std::shared_ptr<const BoundExpressionNode> lower_bound_;
  std::shared_ptr<const BoundExpressionNode> upper_bound_;
  std::shared_ptr<const BoundStatementNode> body_;
};

}  // namespace simple_compiler