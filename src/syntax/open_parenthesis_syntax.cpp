#include "open_parenthesis_syntax.hpp"

namespace simple_compiler {
OpenParenthesisSyntax::OpenParenthesisSyntax(
    const std::shared_ptr<const SyntaxToken> open_parenthesis_token)
    : open_parenthesis_token_(open_parenthesis_token) {}

std::shared_ptr<const SyntaxToken> OpenParenthesisSyntax::OpenParenthesisToken()
    const {
  return open_parenthesis_token_;
};

SyntaxKind OpenParenthesisSyntax::Kind() const {
  return SyntaxKind::OpenParenthesisExpression;
};

std::string OpenParenthesisSyntax::ValueText() const {
  return open_parenthesis_token_->Text();
};
}  // namespace simple_compiler