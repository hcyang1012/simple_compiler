#pragma once

#include "../syntax/value_type.hpp"
#include "bind_node.hpp"
namespace simple_compiler {

class BoundLiteralExpressionNode : public BoundExpressionNode {
 public:
  BoundLiteralExpressionNode(const Value& value);
  BoundNodeKind Kind() const override;
  ValueType Type() const override;
  const simple_compiler::Value& Value() const;

 private:
  const simple_compiler::Value value_;
};
}  // namespace simple_compiler