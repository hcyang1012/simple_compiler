#pragma once
#include <memory>
#include <string>
#include <vector>

#include "syntax_node.hpp"
#include "syntax_token.hpp"
#include "syntax_tree.hpp"

namespace simple_compiler {
class Parser {
 public:
  Parser(const std::string& text);
  std::shared_ptr<const SyntaxTree> Parse();
  const std::vector<std::string>& Diagnostics() const;

 private:
  std::shared_ptr<const ExpressionSyntax> parse_expression(
      const int parent_precedence = 0);
  std::shared_ptr<const ExpressionSyntax> parse_primary_expression();
  std::shared_ptr<const ExpressionSyntax> parse_term();
  std::shared_ptr<const ExpressionSyntax> parse_factor();

  std::shared_ptr<const SyntaxToken> peek(const size_t offset) const;
  std::shared_ptr<const SyntaxToken> current() const;
  std::shared_ptr<const SyntaxToken> next_token();
  std::shared_ptr<const SyntaxToken> match(const SyntaxKind kind);
  std::vector<std::shared_ptr<const SyntaxToken>> tokens_;
  size_t position_;

  std::vector<std::string> diagnostics_;
};
};  // namespace simple_compiler