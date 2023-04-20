#pragma once
#include <string>

namespace simple_compiler {
enum SyntaxKind {
  BadToken,
  EndOfFileToken,
  NumberToken,
  WhiteSpaceToken,
  PlusToken,
  MinusToken,
  StartToken,
  SlashToken,
  OpenParenthesisToken,
  CloseParenthesisToken,

  NumberExpression,
  UnaryExpression,
  BinaryExpression,
  OpenParenthesisExpression,
  CloseParenthesisExpression,
  ParenthesisExpression,
};
std::string ToString(SyntaxKind kind);
}  // namespace simple_compiler