#include "bound_for_statement.hpp"

namespace simple_compiler {

BoundForStatementNode::BoundForStatementNode(
    std::shared_ptr<const VariableSymbol> variable,
    std::shared_ptr<const BoundExpressionNode> lower_bound,
    std::shared_ptr<const BoundExpressionNode> upper_bound,
    std::shared_ptr<const BoundStatementNode> body)
    : variable_(variable),
      lower_bound_(lower_bound),
      upper_bound_(upper_bound),
      body_(body) {}

BoundNodeKind BoundForStatementNode::Kind() const {
  return BoundNodeKind::BoundForStatement;
}

std::shared_ptr<const VariableSymbol> BoundForStatementNode::Variable() const {
  return variable_;
}

std::shared_ptr<const BoundExpressionNode> BoundForStatementNode::LowerBound()
    const {
  return lower_bound_;
}

std::shared_ptr<const BoundExpressionNode> BoundForStatementNode::UpperBound()
    const {
  return upper_bound_;
}

std::shared_ptr<const BoundStatementNode> BoundForStatementNode::Body() const {
  return body_;
}

}  // namespace simple_compiler