#include "syntax_token.hpp"

#include "syntax_kind.hpp"

namespace simple_compiler {
size_t SyntaxToken::Position() const { return position_; }
const std::string& SyntaxToken::Text() const { return text_; }
std::string ToString(const SyntaxToken& token) {
  return ToString(token.Kind()) + ": " + token.Text();
}
SyntaxKind SyntaxToken::Kind() const { return kind_; }
TextSpan SyntaxToken::Span() const {
  return TextSpan(position_, text_.length());
}
}  // namespace simple_compiler
