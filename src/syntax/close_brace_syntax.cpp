#include "close_brace_syntax.hpp"

namespace simple_compiler {
CloseBraceSyntax::CloseBraceSyntax(
    const std::shared_ptr<const SyntaxToken> close_brace_token)
    : close_brace_token_(close_brace_token) {}

std::shared_ptr<const SyntaxToken> CloseBraceSyntax::CloseBraceToken() const {
  return close_brace_token_;
};

SyntaxKind CloseBraceSyntax::Kind() const {
  return SyntaxKind::CloseBraceExpression;
};

std::string CloseBraceSyntax::ValueText() const {
  return close_brace_token_->Text();
};

}  // namespace simple_compiler