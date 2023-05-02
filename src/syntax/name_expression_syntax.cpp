#include "name_expression_syntax.hpp"

#include <memory>
#include <vector>

namespace simple_compiler {
NameExpressionSyntax::NameExpressionSyntax(
    const std::shared_ptr<const IdentifierSyntax> identifiernode)
    : identifier_node_(identifiernode) {}

const std::shared_ptr<const SyntaxNode>
NameExpressionSyntax::GetIdentifierNode() const {
  return identifier_node_;
}

SyntaxKind NameExpressionSyntax::Kind() const {
  return SyntaxKind::NameExpression;
}

std::vector<std::shared_ptr<const SyntaxNode>>
NameExpressionSyntax::GetChildren() const {
  return std::vector<std::shared_ptr<const SyntaxNode>>{identifier_node_};
}
}  // namespace simple_compiler
