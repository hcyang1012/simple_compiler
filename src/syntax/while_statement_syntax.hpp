#pragma once
#include "syntax_node.hpp"
#include "syntax_statement.hpp"
#include <memory>
#include <vector>
namespace simple_compiler {

  class WhileKeywordSyntax : public SyntaxNode {
    public:
    WhileKeywordSyntax(std::shared_ptr<const SyntaxToken> whileKeyword);
    std::shared_ptr<const SyntaxToken> GetToken() const;
    SyntaxKind Kind() const override;
    private:
    std::shared_ptr<const SyntaxToken> whileKeyword_;
  };

  class WhileStatementSyntax : public StatementSyntax {
    public:
    WhileStatementSyntax(
      std::shared_ptr<const WhileKeywordSyntax> whileKeyword,
      std::shared_ptr<const ExpressionSyntax> condition,
      std::shared_ptr<const StatementSyntax> body
    );
    SyntaxKind Kind() const override;
    std::shared_ptr<const WhileKeywordSyntax> GetWhileKeyword() const;
    std::shared_ptr<const ExpressionSyntax> GetCondition() const;
    std::shared_ptr<const StatementSyntax> GetBody() const;
    std::vector<std::shared_ptr<const SyntaxNode>> GetChildren() const override;
    private:
    std::shared_ptr<const WhileKeywordSyntax> whileKeyword_;
    std::shared_ptr<const ExpressionSyntax> condition_;
    std::shared_ptr<const StatementSyntax> body_;
  };
}