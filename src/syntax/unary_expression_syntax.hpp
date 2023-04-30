#pragma once
#include <memory>
#include <vector>

#include "operator_syntax.hpp"
#include "syntax_kind.hpp"
#include "syntax_node.hpp"

namespace simple_compiler {
class UnaryExpressionSyntax : public ExpressionSyntax {
 public:
  UnaryExpressionSyntax(const std::shared_ptr<const OperatorSyntax> op,
                        const std::shared_ptr<const ExpressionSyntax> operand);
  std::shared_ptr<const OperatorSyntax> Operator() const;
  std::shared_ptr<const ExpressionSyntax> Operand() const;
  SyntaxKind Kind() const override;
  std::vector<std::shared_ptr<const SyntaxNode>> GetChildren() const override;
  TextSpan Span() const override;

 private:
  const std::shared_ptr<const OperatorSyntax> operator_;
  const std::shared_ptr<const ExpressionSyntax> operand_;
};
}  // namespace simple_compiler