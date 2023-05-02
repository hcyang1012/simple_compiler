#include "identifier_syntax.hpp"

namespace simple_compiler {
IdentifierSyntax::IdentifierSyntax(
    const std::shared_ptr<const SyntaxToken> identifier_token)
    : identifier_token_(identifier_token) {}

std::shared_ptr<const SyntaxToken> IdentifierSyntax::IdentifierToken() const {
  return identifier_token_;
}

std::string IdentifierSyntax::ValueText() const {
  return identifier_token_->Text();
}

SyntaxKind IdentifierSyntax::Kind() const { return SyntaxKind::Identifier; }
TextSpan IdentifierSyntax::Span() const { return identifier_token_->Span(); }
}  // namespace simple_compiler
