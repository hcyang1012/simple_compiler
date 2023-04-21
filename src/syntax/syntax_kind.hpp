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
  StarToken,
  SlashToken,
  OpenParenthesisToken,
  CloseParenthesisToken,

  LiteralExpression,
  UnaryExpression,
  BinaryExpression,
  OpenParenthesisExpression,
  CloseParenthesisExpression,
  ParenthesisExpression,
};
std::string ToString(SyntaxKind kind);
}  // namespace simple_compiler