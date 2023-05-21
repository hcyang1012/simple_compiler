#pragma once
#include "expression_statement_syntax.hpp"
#include "syntax_node.hpp"
#include <memory>
namespace simple_compiler {
class VariableDeclarationSyntax : public StatementSyntax {
 public:
  VariableDeclarationSyntax(std::shared_ptr<const SyntaxToken> keyword,
                            std::shared_ptr<const SyntaxToken> identifier,
                            std::shared_ptr<const SyntaxToken> equals_token,
                            std::shared_ptr<const ExpressionSyntax> initializer);
  std::shared_ptr<const SyntaxToken> Keyword() const;
  std::shared_ptr<const SyntaxToken> Identifier() const;
  std::shared_ptr<const SyntaxToken> EqualsToken() const;
  std::shared_ptr<const ExpressionSyntax> Initializer() const;

  SyntaxKind Kind() const override;
  private:
  std::shared_ptr<const SyntaxToken> keyword_;
  std::shared_ptr<const SyntaxToken> identifier_;
  std::shared_ptr<const SyntaxToken> equals_token_;
  std::shared_ptr<const ExpressionSyntax> initializer_;

};
}  // namespace simple_compiler