#include "close_parenthesis_syntax.hpp"

namespace simple_compiler {
CloseParenthesisSyntax::CloseParenthesisSyntax(
    const std::shared_ptr<const SyntaxToken> close_parenthesis_token)
    : close_parenthesis_token_(close_parenthesis_token) {}

std::shared_ptr<const SyntaxToken>
CloseParenthesisSyntax::CloseParenthesisToken() const {
  return close_parenthesis_token_;
};

SyntaxKind CloseParenthesisSyntax::Kind() const {
  return SyntaxKind::CloseParenthesisExpression;
};

std::string CloseParenthesisSyntax::ValueText() const {
  return close_parenthesis_token_->Text();
};
}  // namespace simple_compiler