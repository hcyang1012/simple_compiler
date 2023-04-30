#pragma once
#include "syntax_node.hpp"
namespace simple_compiler {
class LiteralExpressionSyntax : public ExpressionSyntax {
 public:
  LiteralExpressionSyntax(const std::shared_ptr<const SyntaxToken> number_token,
                          const Value value);
  std::shared_ptr<const SyntaxToken> LiteralToken() const;
  SyntaxKind Kind() const override;
  std::string ValueText() const override;

 private:
  const Value value_;
  const std::shared_ptr<const SyntaxToken> literal_token_;
};
}  // namespace simple_compiler