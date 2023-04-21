#pragma once

#include <string>

#include "syntax_kind.hpp"
namespace simple_compiler {
class SyntaxFact {
 public:
  static int GetUnaryOperatorPrecedence(SyntaxKind kind);
  static int GetBinaryOperatorPrecedence(SyntaxKind kind);
  static SyntaxKind GetKeywordKind(const std::string& text);
};
}  // namespace simple_compiler