#include "parenthesis_expression_syntax.hpp"

namespace simple_compiler {

ParenthesizedExpressionSyntax::ParenthesizedExpressionSyntax(
    const std::shared_ptr<const OpenParenthesisSyntax> open_parenthesis,
    const std::shared_ptr<const ExpressionSyntax> expression,
    const std::shared_ptr<const CloseParenthesisSyntax> close_parenthesis)
    : open_parenthesis_(open_parenthesis),
      expression_(expression),
      close_parenthesis_(close_parenthesis) {}

std::shared_ptr<const OpenParenthesisSyntax>
ParenthesizedExpressionSyntax::OpenParenthesis() const {
  return open_parenthesis_;
}

std::shared_ptr<const ExpressionSyntax>
ParenthesizedExpressionSyntax::Expression() const {
  return expression_;
}

std::shared_ptr<const CloseParenthesisSyntax>
ParenthesizedExpressionSyntax::CloseParenthesis() const {
  return close_parenthesis_;
}

SyntaxKind ParenthesizedExpressionSyntax::Kind() const {
  return SyntaxKind::ParenthesisExpression;
}

std::vector<std::shared_ptr<const SyntaxNode>>
ParenthesizedExpressionSyntax::GetChildren() const {
  std::vector<std::shared_ptr<const SyntaxNode>> children;
  children.push_back(open_parenthesis_);
  children.push_back(expression_);
  children.push_back(close_parenthesis_);
  return children;
}

}  // namespace simple_compiler