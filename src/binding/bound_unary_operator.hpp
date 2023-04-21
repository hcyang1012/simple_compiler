#pragma once
#include <memory>

#include "../syntax/syntax_kind.hpp"
#include "../syntax/value_type.hpp"

namespace simple_compiler {
enum BoundUnaryOperatorKind {
  Identity,
  Negation,
  LogicalNegation,
};

class BoundUnaryOperatorNode {
 public:
  BoundUnaryOperatorNode(const SyntaxKind syntax_kind,
                         const BoundUnaryOperatorKind kind,
                         const ValueType operand_type, ValueType result_type);
  BoundUnaryOperatorNode(const SyntaxKind syntax_kind,
                         const BoundUnaryOperatorKind kind,
                         const ValueType operand_type);

  const simple_compiler::SyntaxKind SyntaxKind() const;
  const BoundUnaryOperatorKind Kind() const;
  const ValueType OperandType() const;
  const ValueType ResultType() const;
  static std::shared_ptr<const BoundUnaryOperatorNode> Bind(
      const simple_compiler::SyntaxKind syntax_kind, ValueType operand_type);

 private:
  const simple_compiler::SyntaxKind syntax_kind_;
  const BoundUnaryOperatorKind kind_;
  const ValueType operand_type_;
  const ValueType result_type_;
};
}  // namespace simple_compiler