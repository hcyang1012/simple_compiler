#pragma once
#include "bind_node.hpp"
#include <string>

namespace simple_compiler {
    class BoundAssignmentExpressionNode : public BoundExpressionNode{
        public:
        BoundAssignmentExpressionNode(const std::string& name,
                                      const std::shared_ptr<const BoundExpressionNode> expression_node);
        std::string Name() const;
        std::shared_ptr<const BoundExpressionNode> Expression() const;
        BoundNodeKind Kind() const override;
        ValueType Type() const override;
        private:
        const std::string name_;
        const std::shared_ptr<const BoundExpressionNode> expression_node_;

    };
}