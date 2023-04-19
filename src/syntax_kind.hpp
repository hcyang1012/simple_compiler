#pragma once
#include <string>

namespace simple_compiler {
enum SyntaxKind {
  NumberToken,
  WhiteSpaceToken,
  PlusToken,
  MinusToken,
  MulplicationToken,
  DivisionToken,
  OpenParenthesisToken,
  CloseParenthesisToken,
  BadToken,
  EndOfFileToken,

  NumberExpression,
  BinaryExpression,
  OpenParenthesisExpression,
  CloseParenthesisExpression,
  ParenthesisExpression,
};
std::string ToString(SyntaxKind kind);
}  // namespace simple_compiler