#include "literal_expression_syntax.hpp"

namespace simple_compiler {
LiteralExpressionSyntax::LiteralExpressionSyntax(
    const std::shared_ptr<const SyntaxToken> literal_token, const Value value)
    : literal_token_(literal_token), value_(value) {}

std::shared_ptr<const SyntaxToken> LiteralExpressionSyntax::LiteralToken()
    const {
  return literal_token_;
}
SyntaxKind LiteralExpressionSyntax::Kind() const {
  return SyntaxKind::LiteralExpression;
}

std::string LiteralExpressionSyntax::ValueText() const {
  return literal_token_->Text();
}
}  // namespace simple_compiler