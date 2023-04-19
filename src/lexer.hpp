#pragma once

#include <glog/logging.h>

#include <memory>
#include <string>
#include <vector>

#include "syntax_token.hpp"
namespace simple_compiler {
class Lexer {
 public:
  Lexer(const std::string& text);
  std::shared_ptr<SyntaxToken> NextToken();
  const std::vector<std::string>& Diagnostics() const;

 private:
  const std::string text_;
  size_t position_;

  std::vector<std::string> diagnostics_;

  char current_char() const;
  void next();
};
};  // namespace simple_compiler