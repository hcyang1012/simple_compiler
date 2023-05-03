#pragma once
#include <string>

#include "syntax_kind.hpp"
#include "../text/text_span.hpp"
namespace simple_compiler {

class SyntaxToken {
 public:
  SyntaxToken(SyntaxKind kind, size_t position, std::string text)
      : kind_(kind), position_(position), text_(text) {}
  SyntaxToken(const SyntaxToken& token) = default;
  size_t Position() const;
  const std::string& Text() const;

  SyntaxKind Kind() const;
  TextSpan Span() const;

 private:
  const SyntaxKind kind_;
  const size_t position_;
  const std::string text_;
};
std::string ToString(const SyntaxToken& token);
}  // namespace simple_compiler