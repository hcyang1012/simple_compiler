#pragma once
#include <memory>
#include <string>

#include "syntax_kind.hpp"
#include "syntax_node.hpp"
#include "syntax_token.hpp"

namespace simple_compiler {
class OpenParenthesisSyntax : public SyntaxNode {
 public:
  OpenParenthesisSyntax(
      const std::shared_ptr<const SyntaxToken> open_parenthesis_token);
  std::shared_ptr<const SyntaxToken> OpenParenthesisToken() const;
  SyntaxKind Kind() const override;
  std::string ValueText() const override;

 private:
  const std::shared_ptr<const SyntaxToken> open_parenthesis_token_;
};
}  // namespace simple_compiler