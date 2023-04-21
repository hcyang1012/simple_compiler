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

class BoundLiteralExpressionNode : public BoundExpressionNode {
 public:
  BoundLiteralExpressionNode(const Value& value);
  BoundNodeKind Kind() const override;
  ValueType Type() const override;
  const simple_compiler::Value& Value() const;

 private:
  const simple_compiler::Value value_;
};

enum BoundUnaryOperatorKind {
  Identity,
  Negation,
};

class BoundUnaryExpressionNode : public BoundExpressionNode {
 public:
  BoundUnaryExpressionNode(
      const std::shared_ptr<const BoundUnaryOperatorKind> operator_kind,
      const std::shared_ptr<const BoundExpressionNode> operand);

  BoundNodeKind Kind() const override;
  ValueType Type() const override;
  const BoundUnaryOperatorKind& OperatorKind() const;
  const std::shared_ptr<const BoundExpressionNode> Operand() const;

 private:
  const std::shared_ptr<const BoundUnaryOperatorKind> operator_kind_;
  const std::shared_ptr<const BoundExpressionNode> operand_;
};

enum BoundBinaryOperatorKind {
  Addition,
  Subtraction,
  Multiplication,
  Division,
};

class BoundBinaryExpressionNode : public BoundExpressionNode {
 public:
  BoundBinaryExpressionNode(
      const std::shared_ptr<const BoundExpressionNode> left,
      const std::shared_ptr<const BoundBinaryOperatorKind> operator_kind,
      const std::shared_ptr<const BoundExpressionNode> right);

  BoundNodeKind Kind() const override;
  ValueType Type() const override;
  const std::shared_ptr<const BoundExpressionNode> Left() const;
  const std::shared_ptr<const BoundExpressionNode> Right() const;
  const BoundBinaryOperatorKind& OperatorKind() const;

 private:
  const std::shared_ptr<const BoundExpressionNode> left_;
  const std::shared_ptr<const BoundBinaryOperatorKind> operator_kind_;
  const std::shared_ptr<const BoundExpressionNode> right_;
};
}  // namespace simple_compiler