#pragma once
#include <memory>

#include "../syntax/value_type.hpp"
namespace simple_compiler {
enum BoundNodeKind {
  BoundLiteralExpression,
  BoundUnaryExpression,
  BoundBinaryExpression,
};

class BoundNode {
 public:
  virtual BoundNodeKind Kind() const = 0;
};
class BoundExpressionNode : public BoundNode {
 public:
  virtual ValueType Type() const = 0;

 private:
};


}  // namespace simple_compiler