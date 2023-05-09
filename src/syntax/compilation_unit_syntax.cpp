#include "compilation_unit_syntax.hpp"

namespace simple_compiler {
CompilationUnitSyntax::CompilationUnitSyntax(
    std::shared_ptr<const ExpressionSyntax> expression,
    std::shared_ptr<const SyntaxToken> endOfFileToken)
    : expression_(expression), endOfFileToken_(endOfFileToken) {}
SyntaxKind CompilationUnitSyntax::Kind() const {
  return SyntaxKind::CompilationUnit;
}
std::vector<std::shared_ptr<const SyntaxNode>>
CompilationUnitSyntax::GetChildren() const {
  std::vector<std::shared_ptr<const SyntaxNode>> children;
  children.push_back(expression_);
  return children;
}

const std::shared_ptr<const ExpressionSyntax>
CompilationUnitSyntax::Expression() const {
  return expression_;
}
const std::shared_ptr<const SyntaxToken> CompilationUnitSyntax::EndOfFileToken()
    const {
  return endOfFileToken_;
}
}  // namespace simple_compiler