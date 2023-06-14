#pragma once
#include <memory>
#include <vector>

#include "syntax_node.hpp"
#include "syntax_statement.hpp"

namespace simple_compiler {


class IfKeywordSyntax : public SyntaxNode {
 public:
  IfKeywordSyntax(std::shared_ptr<const SyntaxToken> token);
  SyntaxKind Kind() const override;
  std::shared_ptr<const SyntaxToken> GetToken() const;
  private:
  std::shared_ptr<const SyntaxToken> token_;
};

class ElseKeywordSyntax : public SyntaxNode {
 public:
  ElseKeywordSyntax(std::shared_ptr<const SyntaxToken> token);
  SyntaxKind Kind() const override;
  std::shared_ptr<const SyntaxToken> GetToken() const;
  private:
  std::shared_ptr<const SyntaxToken> token_;
};

class ElseClauseSyntax : public SyntaxNode {
 public:
  ElseClauseSyntax(const std::shared_ptr<const ElseKeywordSyntax> else_keyword,
                    const std::shared_ptr<const StatementSyntax> else_statement);
  std::shared_ptr<const ElseKeywordSyntax> ElseKeyword() const;
  std::shared_ptr<const StatementSyntax> ElseStatement() const;
  SyntaxKind Kind() const override;
  TextSpan Span() const override;
  std::vector<std::shared_ptr<const SyntaxNode>> GetChildren() const override;
 private:
  std::shared_ptr<const ElseKeywordSyntax> else_keyword_;
  std::shared_ptr<const StatementSyntax> else_statement_;
};

class IfStatementSyntax : public StatementSyntax {
 public:
  IfStatementSyntax(const std::shared_ptr<const IfKeywordSyntax> if_keyword,
                    const std::shared_ptr<const ExpressionSyntax> condition,
                    const std::shared_ptr<const StatementSyntax> then_statement,
                    const std::shared_ptr<const ElseClauseSyntax> else_clause);
  std::shared_ptr<const IfKeywordSyntax> IfKeyword() const;
  std::shared_ptr<const ExpressionSyntax> Condition() const;
  std::shared_ptr<const StatementSyntax> ThenStatement() const;
  std::shared_ptr<const ElseClauseSyntax> ElseClause() const;
  std::vector<std::shared_ptr<const SyntaxNode>> GetChildren() const override;
  SyntaxKind Kind() const override;
 private:
  std::shared_ptr<const IfKeywordSyntax> if_keyword_;
  std::shared_ptr<const ExpressionSyntax> condition_;
  std::shared_ptr<const StatementSyntax> then_statement_;
  std::shared_ptr<const ElseClauseSyntax> else_clause_;
};
}  // namespace simple_compiler