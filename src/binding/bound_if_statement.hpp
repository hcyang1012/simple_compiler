#pragma once
#include "bind_node.hpp"

namespace simple_compiler {

class BoundIfStatementNode : public BoundStatementNode {
 public:
  BoundIfStatementNode(
      std::shared_ptr<const BoundExpressionNode> condition,
      std::shared_ptr<const BoundStatementNode> then_statement,
      std::shared_ptr<const BoundStatementNode> else_statement);
  BoundNodeKind Kind() const override;
  std::shared_ptr<const BoundExpressionNode> Condition() const;
  std::shared_ptr<const BoundStatementNode> ThenStatement() const;
  std::shared_ptr<const BoundStatementNode> ElseStatement() const;

 private:
  std::shared_ptr<const BoundExpressionNode> condition_;
  std::shared_ptr<const BoundStatementNode> then_statement_;
  std::shared_ptr<const BoundStatementNode> else_statement_;
};

}  // namespace simple_compiler