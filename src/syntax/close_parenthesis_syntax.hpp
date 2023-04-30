#pragma once
#include <memory>
#include <string>

#include "syntax_kind.hpp"
#include "syntax_token.hpp"
#include "syntax_node.hpp"

namespace simple_compiler {

class CloseParenthesisSyntax : public SyntaxNode {
 public:
  CloseParenthesisSyntax(
      const std::shared_ptr<const SyntaxToken> close_parenthesis_token);
  std::shared_ptr<const SyntaxToken> CloseParenthesisToken() const;
  SyntaxKind Kind() const override;
  std::string ValueText() const override;

 private:
  const std::shared_ptr<const SyntaxToken> close_parenthesis_token_;
};

}  // namespace simple_compiler