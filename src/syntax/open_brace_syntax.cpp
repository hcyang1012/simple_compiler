#include "open_brace_syntax.hpp"

namespace simple_compiler {
OpenBraceSyntax::OpenBraceSyntax(
    const std::shared_ptr<const SyntaxToken> open_brace_token)
    : open_brace_token_(open_brace_token) {}

std::shared_ptr<const SyntaxToken> OpenBraceSyntax::OpenBraceToken() const {
  return open_brace_token_;
};

SyntaxKind OpenBraceSyntax::Kind() const {
  return SyntaxKind::OpenBraceExpression;
};

std::string OpenBraceSyntax::ValueText() const {
  return open_brace_token_->Text();
};
}  // namespace simple_compiler