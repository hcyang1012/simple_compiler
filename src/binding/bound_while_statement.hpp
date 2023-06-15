#pragma once
#include "bind_node.hpp"

namespace simple_compiler {
class BoundWhileStatementNode : public BoundStatementNode {
 public:
  BoundWhileStatementNode(std::shared_ptr<const BoundExpressionNode> condition,
                      std::shared_ptr<const BoundStatementNode> body);
  BoundNodeKind Kind() const override;
  std::shared_ptr<const BoundExpressionNode> GetCondition() const;
  std::shared_ptr<const BoundStatementNode> GetBody() const;


 private:
  std::shared_ptr<const BoundExpressionNode> condition_;
  std::shared_ptr<const BoundStatementNode> body_;
};
}