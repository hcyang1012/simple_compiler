#include "assignment_expression_syntax.hpp"

namespace simple_compiler {
AssignmentExpressionSyntax::AssignmentExpressionSyntax(
    const std::shared_ptr<const SyntaxNode> identifier_node,
    const std::shared_ptr<const OperatorSyntax> op,
    const std::shared_ptr<const ExpressionSyntax> expression_node)
    : identifier_node_(identifier_node),
      op_(op),
      expression_node_(expression_node) {}

SyntaxKind AssignmentExpressionSyntax::Kind() const {
  return SyntaxKind::AssignmentExpression;
}

std::vector<std::shared_ptr<const SyntaxNode>>
AssignmentExpressionSyntax::GetChildren() const {
  return std::vector<std::shared_ptr<const SyntaxNode>>{identifier_node_, op_,
                                                        expression_node_};
}

const std::shared_ptr<const SyntaxNode>
AssignmentExpressionSyntax::GetIdentifierToken() const {
  return identifier_node_;
}

const std::shared_ptr<const OperatorSyntax>
AssignmentExpressionSyntax::GetOperatorToken() const {
  return op_;
}

const std::shared_ptr<const ExpressionSyntax>
AssignmentExpressionSyntax::GetExpression() const {
  return expression_node_;
}

}  // namespace simple_compiler
