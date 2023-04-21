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
  if (kind == SyntaxKind::UnaryExpression) {
    return "UnaryExpression";
  }

  if (kind == SyntaxKind::TrueKeyword) {
    return "TrueKeyword";
  }
  if (kind == SyntaxKind::FalseKeyword) {
    return "FalseKeyword";
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
  return "BadToken";
}
}  // namespace simple_compiler