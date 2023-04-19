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
  if (kind == SyntaxKind::MulplicationToken) {
    return "MulplicationToken";
  }
  if (kind == SyntaxKind::DivisionToken) {
    return "DivisionToken";
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
  if(kind == SyntaxKind::NumberExpression){
    return "NumberExpression";
  }
  if(kind == SyntaxKind::BinaryExpression){
    return "BinaryExpression";
  }
  if(kind == SyntaxKind::OpenParenthesisExpression){
    return "OpenParenthesisExpression";
  }
  if(kind == SyntaxKind::CloseParenthesisExpression){
    return "CloseParenthesisExpression";
  }
  if(kind == SyntaxKind::ParenthesisExpression){
    return "ParenthesisExpression";
  }
  return "BadToken";
}
}  // namespace simple_compiler