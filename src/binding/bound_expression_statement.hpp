#pragma once
#include <memory>

#include "bind_node.hpp"

namespace simple_compiler {
class BoundExpressionStatementNode : public BoundStatementNode {
    public:
    BoundExpressionStatementNode(
        std::shared_ptr<const BoundExpressionNode> expression);
    BoundNodeKind Kind() const override;
    std::shared_ptr<const BoundExpressionNode> Expression() const;
    private:
    std::shared_ptr<const BoundExpressionNode> expression_;
};
}  // namespace simple_compiler