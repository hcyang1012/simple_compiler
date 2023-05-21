#include "syntax_variable_declaration.hpp"

namespace simple_compiler {
VariableDeclarationSyntax::VariableDeclarationSyntax(
    std::shared_ptr<const SyntaxToken> keyword,
    std::shared_ptr<const SyntaxToken> identifier,
    std::shared_ptr<const SyntaxToken> equals_token,
    std::shared_ptr<const ExpressionSyntax> initializer)
    : keyword_(keyword),
      identifier_(identifier),
      equals_token_(equals_token),
      initializer_(initializer) {}

SyntaxKind VariableDeclarationSyntax::Kind() const {
  return SyntaxKind::VariableDeclaration;
}

std::shared_ptr<const SyntaxToken> VariableDeclarationSyntax::Keyword() const {
  return keyword_;
}

std::shared_ptr<const SyntaxToken> VariableDeclarationSyntax::Identifier()
    const {
  return identifier_;
}

std::shared_ptr<const SyntaxToken> VariableDeclarationSyntax::EqualsToken()
    const {
  return equals_token_;
}

std::shared_ptr<const ExpressionSyntax> VariableDeclarationSyntax::Initializer()
    const {
  return initializer_;
}

}  // namespace simple_compiler