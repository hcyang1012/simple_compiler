#pragma once
#include <memory>
#include <string>

#include "syntax_kind.hpp"
#include "syntax_node.hpp"
#include "syntax_token.hpp"

namespace simple_compiler {
class CloseBraceSyntax : public SyntaxNode {
 public:
  CloseBraceSyntax(
      const std::shared_ptr<const SyntaxToken> close_brace_token);
  std::shared_ptr<const SyntaxToken> CloseBraceToken() const;
  SyntaxKind Kind() const override;
  std::string ValueText() const override;

 private:
  const std::shared_ptr<const SyntaxToken> close_brace_token_;
};
}  // namespace simple_compiler