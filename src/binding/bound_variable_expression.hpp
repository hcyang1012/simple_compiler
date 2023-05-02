#pragma once
#include "bind_node.hpp"
#include "../syntax/value_type.hpp"
#include "../syntax/syntax_kind.hpp"

#include <string>
namespace simple_compiler{
    class BoundVariableExpressionNode : public BoundExpressionNode{
        public:
        BoundVariableExpressionNode(const std::string& name, const ValueType& type);
        std::string Name() const;
        ValueType Type() const;
        BoundNodeKind Kind() const override;
        private:
        std::string name_;
        ValueType type_;
    };
}