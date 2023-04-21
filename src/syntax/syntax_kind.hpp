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
  IdentifierToken,
  AmpersandAmpersandToken,
  PipePipeToken,
  BangToken,
  BangEqualsToken,
  EqualsEqualsToken,

  TrueKeyword,
  FalseKeyword,

  LiteralExpression,
  UnaryExpression,
  BinaryExpression,
  OpenParenthesisExpression,
  CloseParenthesisExpression,
  ParenthesisExpression,
};
std::string ToString(SyntaxKind kind);
}  // namespace simple_compiler