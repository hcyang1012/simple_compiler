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
  EqualsToken,
  EqualsEqualsToken,
  OpenBraceToken,
  CloseBraceToken,
  LessOrEqualsToken,
  LessToken,
  GreaterOrEqualsToken,
  GreaterToken,

  TrueKeyword,
  FalseKeyword,
  ForKeyword,
  LetKeyword,
  VarKeyword,
  IfKeyword,
  ElseKeyword,
  WhileKeyword,
  ToKeyword,  

  CompilationUnit,

  LiteralExpression,
  UnaryExpression,
  BinaryExpression,
  OpenParenthesisExpression,
  CloseParenthesisExpression,
  ParenthesisExpression,
  NameExpression,
  AssignmentExpression,
  OpenBraceExpression,
  CloseBraceExpression,

  Identifier,

  BlockStatement,
  ExpressionStatement,
  ElaseClause,
  IfStatement,
  WhileStatement,
  ForStatement,

  VariableDeclaration,


};
std::string ToString(SyntaxKind kind);
}  // namespace simple_compiler