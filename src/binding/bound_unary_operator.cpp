#include "bound_unary_operator.hpp"

#include <vector>

namespace simple_compiler {
BoundUnaryOperatorNode::BoundUnaryOperatorNode(
    const simple_compiler::SyntaxKind syntax_kind,
    const BoundUnaryOperatorKind kind, const ValueType operand_type,
    ValueType result_type)
    : syntax_kind_(syntax_kind),
      kind_(kind),
      operand_type_(operand_type),
      result_type_(result_type) {}

BoundUnaryOperatorNode::BoundUnaryOperatorNode(
    const simple_compiler::SyntaxKind syntax_kind,
    const BoundUnaryOperatorKind kind, const ValueType operand_type)
    : syntax_kind_(syntax_kind),
      kind_(kind),
      operand_type_(operand_type),
      result_type_(operand_type) {}

const simple_compiler::SyntaxKind BoundUnaryOperatorNode::SyntaxKind() const {
  return syntax_kind_;
};

const BoundUnaryOperatorKind BoundUnaryOperatorNode::Kind() const {
  return kind_;
};

const ValueType BoundUnaryOperatorNode::OperandType() const {
  return operand_type_;
};

const ValueType BoundUnaryOperatorNode::ResultType() const {
  return result_type_;
}
std::shared_ptr<const BoundUnaryOperatorNode> BoundUnaryOperatorNode::Bind(
    const simple_compiler::SyntaxKind syntax_kind, ValueType operand_type) {
  static std::vector<std::shared_ptr<const BoundUnaryOperatorNode>> operators =
      {
          std::make_shared<const BoundUnaryOperatorNode>(
              simple_compiler::SyntaxKind::PlusToken,
              BoundUnaryOperatorKind::Identity, ValueType::Int),
          std::make_shared<const BoundUnaryOperatorNode>(
              simple_compiler::SyntaxKind::MinusToken,
              BoundUnaryOperatorKind::Negation, ValueType::Int),
          std::make_shared<const BoundUnaryOperatorNode>(
              simple_compiler::SyntaxKind::BangToken,
              BoundUnaryOperatorKind::LogicalNegation, ValueType::Boolean),
      };

  for (auto op : operators) {
    if (op->SyntaxKind() == syntax_kind && op->OperandType() == operand_type) {
      return op;
    }
  }
  return nullptr;
}

}  // namespace simple_compiler
