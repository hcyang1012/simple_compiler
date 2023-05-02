#pragma once
#include <memory>
#include <vector>

#include "syntax_kind.hpp"
#include "syntax_node.hpp"
#include "syntax_token.hpp"
#include "identifier_syntax.hpp"

namespace simple_compiler {
class NameExpressionSyntax : public ExpressionSyntax {
 public:
  NameExpressionSyntax(
      const std::shared_ptr<const IdentifierSyntax> identifier_node);
  const std::shared_ptr<const SyntaxNode> GetIdentifierNode() const;
  SyntaxKind Kind() const override;
  std::vector<std::shared_ptr<const SyntaxNode>> GetChildren() const override;

 private:
  std::shared_ptr<const IdentifierSyntax> identifier_node_;
};
}  // namespace simple_compiler