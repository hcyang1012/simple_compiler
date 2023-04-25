#pragma once
#include <memory>
#include <vector>

#include "syntax_kind.hpp"
#include "syntax_token.hpp"
#include "syntax/value_type.hpp"
#include "../diagnostics/diagnostics.hpp"
namespace simple_compiler {

class SyntaxNode {
 public:
  virtual SyntaxKind Kind() const = 0;
  virtual std::vector<std::shared_ptr<const SyntaxNode>> GetChildren() const;
  virtual std::string ValueText() const;
  virtual TextSpan Span() const;
  std::string ToString() const;

 private:
};

class SyntaxToken;

class ExpressionSyntax : public SyntaxNode {};

class LiteralExpressionSyntax : public ExpressionSyntax {
 public:
  LiteralExpressionSyntax(const std::shared_ptr<const SyntaxToken> number_token, const Value value);
  std::shared_ptr<const SyntaxToken> LiteralToken() const;
  SyntaxKind Kind() const override;
  std::string ValueText() const override;

 private:
  const Value value_;
  const std::shared_ptr<const SyntaxToken> literal_token_;
};

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

class OpenParenthesisSyntax : public SyntaxNode {
 public:
  OpenParenthesisSyntax(const std::shared_ptr<const SyntaxToken> open_parenthesis_token);
  std::shared_ptr<const SyntaxToken> OpenParenthesisToken() const;
  SyntaxKind Kind() const override;
  std::string ValueText() const override;

 private:
  const std::shared_ptr<const SyntaxToken> open_parenthesis_token_;
};

class CloseParenthesisSyntax : public SyntaxNode {
 public:
  CloseParenthesisSyntax(const std::shared_ptr<const SyntaxToken> close_parenthesis_token);
  std::shared_ptr<const SyntaxToken> CloseParenthesisToken() const;
  SyntaxKind Kind() const override;
  std::string ValueText() const override;

 private:
  const std::shared_ptr<const SyntaxToken> close_parenthesis_token_;
};

class ParenthesizedExpressionSyntax : public ExpressionSyntax {
 public:
  ParenthesizedExpressionSyntax(const std::shared_ptr<const OpenParenthesisSyntax> open_parenthesis,
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
};  // namespace simple_compiler
