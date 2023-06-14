#pragma once
#include <memory>

#include "syntax_node.hpp"
#include "syntax_statement.hpp"

namespace simple_compiler {

class ElseClauseSyntax : public SyntaxNode {
 public:
  ElseClauseSyntax(const std::shared_ptr<const SyntaxToken> else_keyword,
                    const std::shared_ptr<const StatementSyntax> else_statement);
  std::shared_ptr<const SyntaxToken> ElseKeyword() const;
  std::shared_ptr<const StatementSyntax> ElseStatement() const;
  SyntaxKind Kind() const override;
  TextSpan Span() const override;
 private:
  std::shared_ptr<const SyntaxToken> else_keyword_;
  std::shared_ptr<const StatementSyntax> else_statement_;
};

class IfStatementSyntax : public StatementSyntax {
 public:
  IfStatementSyntax(const std::shared_ptr<const SyntaxToken> if_keyword,
                    const std::shared_ptr<const ExpressionSyntax> condition,
                    const std::shared_ptr<const StatementSyntax> then_statement,
                    const std::shared_ptr<const ElseClauseSyntax> else_clause);
  std::shared_ptr<const SyntaxToken> IfKeyword() const;
  std::shared_ptr<const ExpressionSyntax> Condition() const;
  std::shared_ptr<const StatementSyntax> ThenStatement() const;
  std::shared_ptr<const ElseClauseSyntax> ElseClause() const;
  SyntaxKind Kind() const override;
 private:
  std::shared_ptr<const SyntaxToken> if_keyword_;
  std::shared_ptr<const ExpressionSyntax> condition_;
  std::shared_ptr<const StatementSyntax> then_statement_;
  std::shared_ptr<const ElseClauseSyntax> else_clause_;
};
}  // namespace simple_compiler