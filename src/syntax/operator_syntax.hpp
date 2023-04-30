#pragma once
#include <memory>

#include "syntax_node.hpp"
#include "syntax_token.hpp"

namespace simple_compiler {

class OperatorSyntax : public SyntaxNode {
 public:
  OperatorSyntax(const std::shared_ptr<const SyntaxToken> operator_token);
  std::shared_ptr<const SyntaxToken> OperatorToken() const;
  SyntaxKind Kind() const override;
  std::string ValueText() const override;
  TextSpan Span() const override;

 private:
  const std::shared_ptr<const SyntaxToken> operator_token_;
};

}  // namespace simple_compiler