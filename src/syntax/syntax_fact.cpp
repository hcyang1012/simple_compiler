#include "syntax_fact.hpp"

namespace simple_compiler {
int SyntaxFact::GetUnaryOperatorPrecedence(SyntaxKind kind) {
  switch (kind) {
    case SyntaxKind::PlusToken:
    case SyntaxKind::MinusToken:
    case SyntaxKind::BangToken:
      return 6;
    default:
      return 0;
  }
}
int SyntaxFact::GetBinaryOperatorPrecedence(SyntaxKind kind) {
  switch (kind) {
    case SyntaxKind::StarToken:
    case SyntaxKind::SlashToken:
      return 5;

    case SyntaxKind::PlusToken:
    case SyntaxKind::MinusToken:
      return 4;

    case SyntaxKind::EqualsEqualsToken:
    case SyntaxKind::BangEqualsToken:
      return 3;

    case SyntaxKind::AmpersandAmpersandToken:
      return 2;

    case SyntaxKind::PipePipeToken:
      return 1;
    default:
      return 0;
  }
}
SyntaxKind SyntaxFact::GetKeywordKind(const std::string& text) {
  if (text == "true") {
    return SyntaxKind::TrueKeyword;
  }

  if (text == "false") {
    return SyntaxKind::FalseKeyword;
  }

  return SyntaxKind::IdentifierToken;
}
}  // namespace simple_compiler
