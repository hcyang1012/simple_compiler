#include "operator_syntax.hpp"

namespace simple_compiler {
OperatorSyntax::OperatorSyntax(
    const std::shared_ptr<const SyntaxToken> operator_token)
    : operator_token_(operator_token) {}

std::shared_ptr<const SyntaxToken> OperatorSyntax::OperatorToken() const {
  return operator_token_;
}

SyntaxKind OperatorSyntax::Kind() const { return operator_token_->Kind(); }

std::string OperatorSyntax::ValueText() const {
  return operator_token_->Text();
}

TextSpan OperatorSyntax::Span() const { return operator_token_->Span(); }
}  // namespace simple_compiler