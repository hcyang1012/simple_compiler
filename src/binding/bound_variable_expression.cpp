#include "bound_variable_expression.hpp"

namespace simple_compiler {
BoundVariableExpressionNode::BoundVariableExpressionNode(const std::string& name,
                                                 const ValueType& type)
    : name_(name), type_(type) {}

std::string BoundVariableExpressionNode::Name() const { return name_; }
ValueType BoundVariableExpressionNode::Type() const { return type_; }
BoundNodeKind BoundVariableExpressionNode::Kind() const {
  return BoundNodeKind::BoundVariableExpression;
}
}  // namespace simple_compiler
