#include "lexer.hpp"

#include <memory>
#include "syntax_fact.hpp"
namespace simple_compiler {
Lexer::Lexer(const std::string& text) : text_(text), position_(0) {}

const std::vector<std::string>& Lexer::Diagnostics() const {
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
  if (position_ >= text_.length()) {
    return std::make_shared<SyntaxToken>(SyntaxKind::EndOfFileToken, position_,
                                         "\0");
  }
  if (std::isdigit(current_char())) {
    size_t start = position_;
    while (std::isdigit(current_char())) {
      next();
    }
    size_t length = position_ - start;
    std::string text = text_.substr(start, length);
    return std::make_shared<SyntaxToken>(SyntaxKind::NumberToken, start, text);
  }

  if (std::isspace(current_char())) {
    size_t start = position_;
    while (std::isspace(current_char())) {
      next();
    }
    size_t length = position_ - start;
    std::string text = text_.substr(start, length);
    return std::make_shared<SyntaxToken>(SyntaxKind::WhiteSpaceToken, start,
                                         text);
  }

  if(std::isalpha(current_char())){
    size_t start = position_;
    while(std::isalpha(current_char())){
      next();
    }
    size_t length = position_ - start;
    std::string text = text_.substr(start, length);
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
    return std::make_shared<SyntaxToken>(SyntaxKind::StarToken,
                                         position_++, "*");
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

  diagnostics_.emplace_back("Lexer ERROR: bad character at position " +
                            std::to_string(position_));
  auto prev_position = position_++;
  return std::make_shared<SyntaxToken>(SyntaxKind::BadToken, prev_position,
                                       text_.substr(position_ - 1, 1));
}
char Lexer::current_char() const {
  if (position_ >= text_.length()) {
    return '\0';
  }
  return text_[position_];
}
void Lexer::next() {
  position_++;
  return;
}
};  // namespace simple_compiler
