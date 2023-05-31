#include "lexer.hpp"

#include <memory>

#include "syntax_fact.hpp"
#include "../diagnostics/diagnostics_bag.hpp"

namespace simple_compiler {
Lexer::Lexer(const TextSource& text) : text_(text), position_(0) {}

const std::shared_ptr<const DiagnosticsBag> Lexer::Diagnostics() const {
  return diagnostics_;
}

/**
 * @brief
 *
 * Tokens are
 * 1. Number
 * 2. Binary operators (+, -, *, /)
 * 3. White spaces
 * 4. Parenthesis
 *
 * @return std::shared_ptr<SyntaxToken>
 */
std::shared_ptr<SyntaxToken> simple_compiler::Lexer::NextToken() {
  if (position_ >= text_.Length()) {
    return std::make_shared<SyntaxToken>(SyntaxKind::EndOfFileToken, position_,
                                         "\0");
  }
  if (std::isdigit(current_char())) {
    size_t start = position_;
    while (std::isdigit(current_char())) {
      next();
    }
    size_t length = position_ - start;
    std::string text = text_.ToString(start, length);
    return std::make_shared<SyntaxToken>(SyntaxKind::NumberToken, start, text);
  }

  if (std::isspace(current_char())) {
    size_t start = position_;
    while (std::isspace(current_char())) {
      next();
    }
    size_t length = position_ - start;
    std::string text = text_.ToString(start, length);
    return std::make_shared<SyntaxToken>(SyntaxKind::WhiteSpaceToken, start,
                                         text);
  }

  if (std::isalpha(current_char())) {
    size_t start = position_;
    while (std::isalpha(current_char())) {
      next();
    }
    size_t length = position_ - start;
    std::string text = text_.ToString(start, length);
    auto kind = SyntaxFact::GetKeywordKind(text);
    return std::make_shared<SyntaxToken>(kind, start, text);
  }

  if (current_char() == '+') {
    return std::make_shared<SyntaxToken>(SyntaxKind::PlusToken, position_++,
                                         "+");
  }
  if (current_char() == '-') {
    return std::make_shared<SyntaxToken>(SyntaxKind::MinusToken, position_++,
                                         "-");
  }
  if (current_char() == '*') {
    return std::make_shared<SyntaxToken>(SyntaxKind::StarToken, position_++,
                                         "*");
  }
  if (current_char() == '/') {
    return std::make_shared<SyntaxToken>(SyntaxKind::SlashToken, position_++,
                                         "/");
  }
  if (current_char() == '(') {
    return std::make_shared<SyntaxToken>(SyntaxKind::OpenParenthesisToken,
                                         position_++, "(");
  }
  if (current_char() == ')') {
    return std::make_shared<SyntaxToken>(SyntaxKind::CloseParenthesisToken,
                                         position_++, ")");
  }
  if (current_char() == '{') {
    return std::make_shared<SyntaxToken>(SyntaxKind::OpenBraceToken,
                                         position_++, "{");
  }
  if (current_char() == '}') {
    return std::make_shared<SyntaxToken>(SyntaxKind::CloseBraceToken,
                                         position_++, "}");
  }

  if (current_char() == '!') {
    if(lookahead() == '='){
      position_ += 2;
      return std::make_shared<SyntaxToken>(SyntaxKind::BangEqualsToken,
                                           position_ - 2, "!=");
    }
    return std::make_shared<SyntaxToken>(SyntaxKind::BangToken, position_++,
                                         "!");
  }
  if (current_char() == '&') {
    if (lookahead() == '&') {
      position_ += 2;
      return std::make_shared<SyntaxToken>(SyntaxKind::AmpersandAmpersandToken,
                                           position_ - 2, "&&");
    }
  }
  if(current_char() == '<'){
    if(lookahead() == '='){
      position_ += 2;
      return std::make_shared<SyntaxToken>(SyntaxKind::LessOrEqualsToken,
                                           position_ - 2, "<=");
    }else{
      position_++;
      return std::make_shared<SyntaxToken>(SyntaxKind::LessToken, position_ - 1,
                                           "<");
    }
  }
  if(current_char() == '>'){
    if(lookahead() == '='){
      position_ += 2;
      return std::make_shared<SyntaxToken>(SyntaxKind::GreaterOrEqualsToken,
                                           position_ - 2, ">=");
    }else{
      position_++;
      return std::make_shared<SyntaxToken>(SyntaxKind::GreaterToken, position_ - 1,
                                           ">");
    }
  }
  if (current_char() == '|') {
    if (lookahead() == '|') {
      position_ += 2;
      return std::make_shared<SyntaxToken>(SyntaxKind::PipePipeToken,
                                           position_ - 2, "||");
    }
  }

  if(current_char() == '='){
    if(lookahead() == '='){
      position_ += 2;
      return std::make_shared<SyntaxToken>(SyntaxKind::EqualsEqualsToken,
                                           position_ - 2, "==");
    }
    return std::make_shared<SyntaxToken>(SyntaxKind::EqualsToken, position_++,
                                         "=");
  }
  diagnostics_->ReportBadCharacter(position_, current_char());
  auto prev_position = position_++;
  return std::make_shared<SyntaxToken>(SyntaxKind::BadToken, prev_position,
                                       text_.ToString(position_ - 1, 1));
}
char Lexer::current_char() const { return peek(0); }
char Lexer::lookahead() const { return peek(1); }
char Lexer::peek(const size_t offset) const {
  size_t position = position_ + offset;
  if (position >= text_.Length()) {
    return '\0';
  }
  return text_[position];
}
void Lexer::next() {
  position_++;
  return;
}
};  // namespace simple_compiler
