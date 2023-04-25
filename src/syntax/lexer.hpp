#pragma once

#include <glog/logging.h>

#include <memory>
#include <string>
#include <vector>

#include "syntax_token.hpp"
#include "../diagnostics/diagnostics_bag.hpp"

namespace simple_compiler {
class Lexer {
 public:
  Lexer(const std::string& text);
  std::shared_ptr<SyntaxToken> NextToken();
  const std::shared_ptr<const DiagnosticsBag> Diagnostics() const;

 private:
  const std::string text_;
  size_t position_;

  std::shared_ptr<DiagnosticsBag> diagnostics_ =
      std::make_shared<simple_compiler::DiagnosticsBag>();

  char current_char() const;
  char lookahead() const;
  char peek(const size_t offset) const;
  void next();
};
};  // namespace simple_compiler