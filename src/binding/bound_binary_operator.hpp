#pragma once
#include <memory>

#include "../syntax/syntax_kind.hpp"
#include "../syntax/value_type.hpp"

namespace simple_compiler {
enum BoundBinaryOperatorKind {
  Addition,
  Subtraction,
  Multiplication,
  Division,
  LogicalAnd,
  LogicalOr,
};
class BoundBinaryOperatorNode {
 public:
  BoundBinaryOperatorNode(const SyntaxKind syntax_kind,
                          const BoundBinaryOperatorKind kind,
                          const ValueType left_type, const ValueType right_type,
                          ValueType result_type);
  BoundBinaryOperatorNode(const SyntaxKind syntax_kind,
                          const BoundBinaryOperatorKind kind,
                          const ValueType left_type, const ValueType right_type);

  const simple_compiler::SyntaxKind SyntaxKind() const;
  const BoundBinaryOperatorKind Kind() const;
  const ValueType LeftType() const;
  const ValueType RightType() const;
  const ValueType ResultType() const;
  static std::shared_ptr<const BoundBinaryOperatorNode> Bind(
      const simple_compiler::SyntaxKind syntax_kind, const ValueType left_type,
      const ValueType right_type);

 private:
  const simple_compiler::SyntaxKind syntax_kind_;
  const BoundBinaryOperatorKind kind_;
  const ValueType left_type_;
  const ValueType right_type_;
  const ValueType result_type_;
};
}  // namespace simple_compiler