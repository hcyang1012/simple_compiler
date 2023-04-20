#include "syntax_fact.hpp"

namespace simple_compiler {
int SyntaxFact::GetUnaryOperatorPrecedence(SyntaxKind kind){
  switch (kind) {
    case SyntaxKind::PlusToken:
    case SyntaxKind::MinusToken:
      return 3;
    default:
      return 0;
  }
}
int SyntaxFact::GetBinaryOperatorPrecedence(SyntaxKind kind) {
  switch (kind) {
    case SyntaxKind::PlusToken:
    case SyntaxKind::MinusToken:
      return 2;
    case SyntaxKind::StartToken:
    case SyntaxKind::SlashToken:
      return 1;
    default:
      return 0;
  }
}
}  // namespace simple_compiler