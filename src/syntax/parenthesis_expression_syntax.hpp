#pragma once
#include <memory>
#include <vector>

#include "syntax_kind.hpp"
#include "syntax_node.hpp"
#include "open_parenthesis_syntax.hpp"
#include "close_parenthesis_syntax.hpp"

namespace simple_compiler {
class ParenthesizedExpressionSyntax : public ExpressionSyntax {
 public:
  ParenthesizedExpressionSyntax(
      const std::shared_ptr<const OpenParenthesisSyntax> open_parenthesis,
      const std::shared_ptr<const ExpressionSyntax> expression,
      const std::shared_ptr<const CloseParenthesisSyntax> close_parenthesis);
  std::shared_ptr<const OpenParenthesisSyntax> OpenParenthesis() const;
  std::shared_ptr<const ExpressionSyntax> Expression() const;
  std::shared_ptr<const CloseParenthesisSyntax> CloseParenthesis() const;
  SyntaxKind Kind() const override;
  std::vector<std::shared_ptr<const SyntaxNode>> GetChildren() const override;

 private:
  const std::shared_ptr<const OpenParenthesisSyntax> open_parenthesis_;
  const std::shared_ptr<const ExpressionSyntax> expression_;
  const std::shared_ptr<const CloseParenthesisSyntax> close_parenthesis_;
};
}  // namespace simple_compiler