#pragma once
#include <memory>
#include <vector>

#include "operator_syntax.hpp"
#include "syntax_node.hpp"
#include "syntax_statement.hpp"
#include "identifier_syntax.hpp"

namespace simple_compiler {

class ForKeywordSyntax : public StatementSyntax {
 public:
  explicit ForKeywordSyntax(const std::shared_ptr<const SyntaxToken> keyword);

  std::shared_ptr<const SyntaxToken> Keyword() const;
  SyntaxKind Kind() const override;

 private:
  const std::shared_ptr<const SyntaxToken> keyword_;
};

class ToKeywordSyntax : public StatementSyntax {
 public:
  explicit ToKeywordSyntax(const std::shared_ptr<const SyntaxToken> keyword);

  std::shared_ptr<const SyntaxToken> Keyword() const;
  SyntaxKind Kind() const override;

 private:
  const std::shared_ptr<const SyntaxToken> keyword_;
};

class ForStatementSyntax : public StatementSyntax {
 public:
  ForStatementSyntax(
      const std::shared_ptr<const ForKeywordSyntax> for_keyword,
      const std::shared_ptr<const IdentifierSyntax> identifier,
      const std::shared_ptr<const OperatorSyntax> equal_token,
      const std::shared_ptr<const ExpressionSyntax> lower_bound,
      const std::shared_ptr<const ToKeywordSyntax> to_keyword,
      const std::shared_ptr<const ExpressionSyntax> upper_bound,
      const std::shared_ptr<const StatementSyntax> body);

  std::shared_ptr<const ForKeywordSyntax> ForKeyword() const;
  std::shared_ptr<const IdentifierSyntax> Identifier() const;
  std::shared_ptr<const OperatorSyntax> EqualToken() const;
  std::shared_ptr<const ExpressionSyntax> LowerBound() const;
  std::shared_ptr<const ToKeywordSyntax> ToKeyword() const;
  std::shared_ptr<const ExpressionSyntax> UpperBound() const;
  std::shared_ptr<const StatementSyntax> Body() const;

  SyntaxKind Kind() const override;
  std::vector<std::shared_ptr<const SyntaxNode>> GetChildren() const override;

 private:
  const std::shared_ptr<const ForKeywordSyntax> for_keyword_;
  const std::shared_ptr<const IdentifierSyntax> identifier_;
  const std::shared_ptr<const OperatorSyntax> equal_token_;
  const std::shared_ptr<const ExpressionSyntax> lower_bound_;
  const std::shared_ptr<const ToKeywordSyntax> to_keyword_;
  const std::shared_ptr<const ExpressionSyntax> upper_bound_;
  const std::shared_ptr<const StatementSyntax> body_;
};

}  // namespace simple_compiler