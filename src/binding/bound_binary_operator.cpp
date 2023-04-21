#include "bound_binary_operator.hpp"

#include <vector>

namespace simple_compiler {
BoundBinaryOperatorNode::BoundBinaryOperatorNode(
    const simple_compiler::SyntaxKind syntax_kind,
    const BoundBinaryOperatorKind kind, const ValueType left_type,
    const ValueType right_type, ValueType result_type)
    : syntax_kind_(syntax_kind),
      kind_(kind),
      left_type_(left_type),
      right_type_(right_type),
      result_type_(result_type) {}

BoundBinaryOperatorNode::BoundBinaryOperatorNode(
    const simple_compiler::SyntaxKind syntax_kind,
    const BoundBinaryOperatorKind kind, const ValueType left_type,
    const ValueType right_type)
    : syntax_kind_(syntax_kind),
      kind_(kind),
      left_type_(left_type),
      right_type_(right_type),
      result_type_(left_type) {}

const simple_compiler::SyntaxKind BoundBinaryOperatorNode::SyntaxKind() const {
  return syntax_kind_;
};

const BoundBinaryOperatorKind BoundBinaryOperatorNode::Kind() const {
  return kind_;
};

const ValueType BoundBinaryOperatorNode::LeftType() const { return left_type_; }

const ValueType BoundBinaryOperatorNode::RightType() const {
  return right_type_;
}

const ValueType BoundBinaryOperatorNode::ResultType() const {
  return result_type_;
}
std::shared_ptr<const BoundBinaryOperatorNode> BoundBinaryOperatorNode::Bind(
    const simple_compiler::SyntaxKind syntax_kind, const ValueType left_type,
    const ValueType right_type) {
  static std::vector<std::shared_ptr<const BoundBinaryOperatorNode>> operators =
      {
          std::make_shared<const BoundBinaryOperatorNode>(
              simple_compiler::SyntaxKind::PlusToken,
              BoundBinaryOperatorKind::Addition, ValueType::Int,
              ValueType::Int),
          std::make_shared<const BoundBinaryOperatorNode>(
              simple_compiler::SyntaxKind::MinusToken,
              BoundBinaryOperatorKind::Subtraction, ValueType::Int,
              ValueType::Int),
          std::make_shared<const BoundBinaryOperatorNode>(
              simple_compiler::SyntaxKind::StarToken,
              BoundBinaryOperatorKind::Multiplication, ValueType::Int,
              ValueType::Int),
          std::make_shared<const BoundBinaryOperatorNode>(
              simple_compiler::SyntaxKind::SlashToken,
              BoundBinaryOperatorKind::Division, ValueType::Int,
              ValueType::Int),
          std::make_shared<const BoundBinaryOperatorNode>(
              simple_compiler::SyntaxKind::AmpersandAmpersandToken,
              BoundBinaryOperatorKind::LogicalAnd, ValueType::Boolean,
              ValueType::Boolean),
          std::make_shared<const BoundBinaryOperatorNode>(
              simple_compiler::SyntaxKind::PipePipeToken,
              BoundBinaryOperatorKind::LogicalOr, ValueType::Boolean,
              ValueType::Boolean),
      };

  for (const auto& op : operators) {
    if (op->SyntaxKind() == syntax_kind && op->LeftType() == left_type &&
        op->RightType() == right_type) {
      return op;
    }
  }
  return nullptr;
}

}  // namespace simple_compiler
