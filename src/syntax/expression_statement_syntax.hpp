#pragma once
#include <memory>

#include "syntax_statement.hpp"
#include "syntax_node.hpp"
namespace simple_compiler {
class ExpressionStatementSyntax : public StatementSyntax {
 public:
  ExpressionStatementSyntax(
      const std::shared_ptr<const ExpressionSyntax> expression);
  std::shared_ptr<const ExpressionSyntax> Expression() const;
  SyntaxKind Kind() const override;
  std::string ValueText() const override;
  std::vector<std::shared_ptr<const SyntaxNode>> GetChildren() const override;

 private:
  const std::shared_ptr<const ExpressionSyntax> expression_;
};
}  // namespace simple_compiler