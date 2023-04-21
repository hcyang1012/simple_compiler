#include "syntax_node.hpp"

#include "syntax_kind.hpp"

namespace simple_compiler {
std::string SyntaxNode::ValueText() const { return ""; }

std::vector<std::shared_ptr<const SyntaxNode>> SyntaxNode::GetChildren() const {
  return {};
}

LiteralExpressionSyntax::LiteralExpressionSyntax(
    const std::shared_ptr<const SyntaxToken> number_token)
    : number_token_(number_token) {}

std::shared_ptr<const SyntaxToken> LiteralExpressionSyntax::NumberToken() const {
  return number_token_;
}
SyntaxKind LiteralExpressionSyntax::Kind() const {
  return SyntaxKind::LiteralExpression;
}

std::string LiteralExpressionSyntax::ValueText() const {
  return number_token_->Text();
}

OperatorSyntax::OperatorSyntax(
    const std::shared_ptr<const SyntaxToken> operator_token)
    : operator_token_(operator_token) {}

std::shared_ptr<const SyntaxToken> OperatorSyntax::OperatorToken() const {
  return operator_token_;
}

SyntaxKind OperatorSyntax::Kind() const { return operator_token_->Kind(); }

std::string OperatorSyntax::ValueText() const {
  return operator_token_->Text();
}

BinaryExpressionSyntax::BinaryExpressionSyntax(
    const std::shared_ptr<const ExpressionSyntax> left,
    const std::shared_ptr<const OperatorSyntax> op,
    const std::shared_ptr<const ExpressionSyntax> right)
    : left_(left), operator_(op), right_(right) {}

std::shared_ptr<const ExpressionSyntax> BinaryExpressionSyntax::Left() const {
  return left_;
}
std::shared_ptr<const OperatorSyntax> BinaryExpressionSyntax::Operator() const {
  return operator_;
}
std::shared_ptr<const ExpressionSyntax> BinaryExpressionSyntax::Right() const {
  return right_;
}
SyntaxKind BinaryExpressionSyntax::Kind() const {
  return SyntaxKind::BinaryExpression;
}
std::vector<std::shared_ptr<const SyntaxNode>>
BinaryExpressionSyntax::GetChildren() const {
  std::vector<std::shared_ptr<const SyntaxNode>> children;
  children.push_back(left_);
  children.push_back(operator_);
  children.push_back(right_);
  return children;
}

std::string SyntaxNode::ToString() const {
  return simple_compiler::ToString(Kind()) + ": " + ValueText();
}
OpenParenthesisSyntax::OpenParenthesisSyntax(
    const std::shared_ptr<const SyntaxToken> open_parenthesis_token)
    : open_parenthesis_token_(open_parenthesis_token) {}

std::shared_ptr<const SyntaxToken> OpenParenthesisSyntax::OpenParenthesisToken()
    const {
  return open_parenthesis_token_;
};

SyntaxKind OpenParenthesisSyntax::Kind() const {
  return SyntaxKind::OpenParenthesisExpression;
};

std::string OpenParenthesisSyntax::ValueText() const {
  return open_parenthesis_token_->Text();
};

CloseParenthesisSyntax::CloseParenthesisSyntax(
    const std::shared_ptr<const SyntaxToken> close_parenthesis_token)
    : close_parenthesis_token_(close_parenthesis_token) {}

std::shared_ptr<const SyntaxToken>
CloseParenthesisSyntax::CloseParenthesisToken() const {
  return close_parenthesis_token_;
};

SyntaxKind CloseParenthesisSyntax::Kind() const {
  return SyntaxKind::CloseParenthesisExpression;
};

std::string CloseParenthesisSyntax::ValueText() const {
  return close_parenthesis_token_->Text();
};

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

UnaryExpressionSyntax::UnaryExpressionSyntax(
    const std::shared_ptr<const OperatorSyntax> op,
    const std::shared_ptr<const ExpressionSyntax> operand)
    : operator_(op), operand_(operand) {}

std::shared_ptr<const OperatorSyntax> UnaryExpressionSyntax::Operator() const {
  return operator_;
}

std::shared_ptr<const ExpressionSyntax> UnaryExpressionSyntax::Operand() const {
  return operand_;
}

SyntaxKind UnaryExpressionSyntax::Kind() const {
  return SyntaxKind::UnaryExpression;
}

std::vector<std::shared_ptr<const SyntaxNode>>
UnaryExpressionSyntax::GetChildren() const {
  std::vector<std::shared_ptr<const SyntaxNode>> children;
  children.push_back(operator_);
  children.push_back(operand_);
  return children;
}

}  // namespace simple_compiler
