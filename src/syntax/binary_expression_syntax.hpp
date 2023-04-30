#pragma once
#include <memory>

#include "syntax_node.hpp"
#include "operator_syntax.hpp"

namespace simple_compiler {
class BinaryExpressionSyntax : public ExpressionSyntax {
 public:
  BinaryExpressionSyntax(const std::shared_ptr<const ExpressionSyntax> left,
                         const std::shared_ptr<const OperatorSyntax> op,
                         const std::shared_ptr<const ExpressionSyntax> right);
  std::shared_ptr<const ExpressionSyntax> Left() const;
  std::shared_ptr<const OperatorSyntax> Operator() const;
  std::shared_ptr<const ExpressionSyntax> Right() const;
  SyntaxKind Kind() const override;
  std::vector<std::shared_ptr<const SyntaxNode>> GetChildren() const override;
  TextSpan Span() const override;

 private:
  const std::shared_ptr<const ExpressionSyntax> left_;
  const std::shared_ptr<const OperatorSyntax> operator_;
  const std::shared_ptr<const ExpressionSyntax> right_;
};
}