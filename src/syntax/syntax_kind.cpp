#include "syntax_kind.hpp"
namespace simple_compiler {
std::string ToString(SyntaxKind kind) {
  if (kind == SyntaxKind::NumberToken) {
    return "NumberToken";
  }
  if (kind == SyntaxKind::WhiteSpaceToken) {
    return "WhiteSpaceToken";
  }
  if (kind == SyntaxKind::PlusToken) {
    return "PlusToken";
  }
  if (kind == SyntaxKind::MinusToken) {
    return "MinusToken";
  }
  if (kind == SyntaxKind::StarToken) {
    return "StarToken";
  }
  if (kind == SyntaxKind::SlashToken) {
    return "SlashToken";
  }
  if (kind == SyntaxKind::OpenParenthesisToken) {
    return "OpenParenthesisToken";
  }
  if (kind == SyntaxKind::CloseParenthesisToken) {
    return "CloseParenthesisToken";
  }
  if (kind == SyntaxKind::EndOfFileToken) {
    return "EndOfFileToken";
  }
  if (kind == SyntaxKind::LiteralExpression) {
    return "LiteralExpression";
  }
  if (kind == SyntaxKind::BinaryExpression) {
    return "BinaryExpression";
  }
  if (kind == SyntaxKind::OpenParenthesisExpression) {
    return "OpenParenthesisExpression";
  }
  if (kind == SyntaxKind::CloseParenthesisExpression) {
    return "CloseParenthesisExpression";
  }
  if (kind == SyntaxKind::ParenthesisExpression) {
    return "ParenthesisExpression";
  }

  if (kind == SyntaxKind::OpenBraceToken) {
    return "OpenBraceToken";
  }

  if (kind == SyntaxKind::CloseBraceToken) {
    return "CloseBraceToken";
  }

  if (kind == SyntaxKind::LessOrEqualsToken) {
    return "LessOrEqualsToken";
  }

  if (kind == SyntaxKind::LessToken) {
    return "LessToken";
  }

  if (kind == SyntaxKind::GreaterOrEqualsToken) {
    return "GreaterOrEqualsToken";
  }

  if (kind == SyntaxKind::GreaterToken) {
    return "GreaterToken";
  }

  if (kind == SyntaxKind::UnaryExpression) {
    return "UnaryExpression";
  }

  if (kind == SyntaxKind::TrueKeyword) {
    return "TrueKeyword";
  }
  if (kind == SyntaxKind::FalseKeyword) {
    return "FalseKeyword";
  }

  if (kind == SyntaxKind::LetKeyword) {
    return "LetKeyword";
  }

  if (kind == SyntaxKind::VarKeyword) {
    return "VarKeyword";
  }

  if (kind == SyntaxKind::IdentifierToken) {
    return "IdentifierToken";
  }

  if (kind == SyntaxKind::AmpersandAmpersandToken) {
    return "AmpersandAmpersandToken";
  }

  if (kind == SyntaxKind::PipePipeToken) {
    return "PipePipeToken";
  }

  if (kind == SyntaxKind::BangToken) {
    return "BangToken";
  }

  if (kind == SyntaxKind::AssignmentExpression) {
    return "AssignmentExpression";
  }

  if (kind == SyntaxKind::Identifier) {
    return "Identifier";
  }

  if (kind == SyntaxKind::EqualsToken) {
    return "EqualsToken";
  }

  if (kind == SyntaxKind::EqualsEqualsToken) {
    return "EqualsEqualsToken";
  }

  if (kind == SyntaxKind::BangEqualsToken) {
    return "BangEqualsToken";
  }

  if (kind == SyntaxKind::NameExpression) {
    return "NameExpression";
  }

  if (kind == SyntaxKind::CompilationUnit) {
    return "CompilationUnit";
  }

  if (kind == SyntaxKind::BlockStatement) {
    return "BlockStatement";
  }

  if (kind == SyntaxKind::ExpressionStatement) {
    return "ExpressionStatement";
  }

  if (kind == SyntaxKind::OpenBraceExpression) {
    return "OpenBraceExpression";
  }

  if (kind == SyntaxKind::CloseBraceExpression) {
    return "CloseBraceExpression";
  }

  if (kind == SyntaxKind::VariableDeclaration) {
    return "VariableDeclaration";
  }

  if (kind == IfKeyword) {
    return "IfKeyword";
  }

  if (kind == SyntaxKind::ElseKeyword) {
    return "ElseKeyword";
  }

  if (kind == SyntaxKind::ElaseClause) {
    return "ElaseClause";
  }

  if (kind == SyntaxKind::IfStatement) {
    return "IfStatement";
  }

  return "BadToken";
}
}  // namespace simple_compiler