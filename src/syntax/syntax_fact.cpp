#include "syntax_fact.hpp"

namespace simple_compiler {
int SyntaxFact::GetUnaryOperatorPrecedence(SyntaxKind kind) {
  switch (kind) {
    case SyntaxKind::PlusToken:
    case SyntaxKind::MinusToken:
      return 5;
    case SyntaxKind::BangToken:
      return 4;
    default:
      return 0;
  }
}
int SyntaxFact::GetBinaryOperatorPrecedence(SyntaxKind kind) {
  switch (kind) {
    case SyntaxKind::StarToken:
    case SyntaxKind::SlashToken:
      return 3;

    case SyntaxKind::PlusToken:
    case SyntaxKind::MinusToken:
      return 2;

    case SyntaxKind::AmpersandAmpersandToken:
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
