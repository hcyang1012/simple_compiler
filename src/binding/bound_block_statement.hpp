#pragma once
#include <memory>
#include <vector>

#include "../syntax/syntax_statement.hpp"
#include "bind_node.hpp"

namespace simple_compiler {
class BoundBlockStatementNode : public BoundStatementNode {
 public:
  BoundBlockStatementNode(
      const std::vector<std::shared_ptr<const BoundStatementNode>>& statements);
  std::vector<std::shared_ptr<const BoundStatementNode>> Statements() const;
  BoundNodeKind Kind() const override;

 private:
  const std::vector<std::shared_ptr<const BoundStatementNode>> statements_;
};
}  // namespace simple_compiler