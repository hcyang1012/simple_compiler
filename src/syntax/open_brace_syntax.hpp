#pragma once
#include <memory>
#include <string>

#include "syntax_kind.hpp"
#include "syntax_node.hpp"
#include "syntax_token.hpp"

namespace simple_compiler {
class OpenBraceSyntax : public SyntaxNode {
 public:
  OpenBraceSyntax(
      const std::shared_ptr<const SyntaxToken> open_brace_token);
  std::shared_ptr<const SyntaxToken> OpenBraceToken() const;
  SyntaxKind Kind() const override;
  std::string ValueText() const override;

 private:
  const std::shared_ptr<const SyntaxToken> open_brace_token_;
};
}  // namespace simple_compiler