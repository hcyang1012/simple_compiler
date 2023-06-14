#include "if_statement_syntax.hpp"

namespace simple_compiler {
ElseClauseSyntax::ElseClauseSyntax(
    const std::shared_ptr<const SyntaxToken> else_keyword,
    const std::shared_ptr<const StatementSyntax> else_statement)
    : else_keyword_(else_keyword), else_statement_(else_statement) {}

std::shared_ptr<const SyntaxToken> ElseClauseSyntax::ElseKeyword() const {
  return else_keyword_;
}

std::shared_ptr<const StatementSyntax> ElseClauseSyntax::ElseStatement()
    const {
  return else_statement_;
}

SyntaxKind ElseClauseSyntax::Kind() const { return SyntaxKind::ElaseClause; }

TextSpan ElseClauseSyntax::Span() const {
  return TextSpan(else_keyword_->Span().Start(), else_statement_->Span().End());
}

IfStatementSyntax::IfStatementSyntax(
    const std::shared_ptr<const SyntaxToken> if_keyword,
    const std::shared_ptr<const ExpressionSyntax> condition,
    const std::shared_ptr<const StatementSyntax> then_statement,
    const std::shared_ptr<const ElseClauseSyntax> else_clause)
    : if_keyword_(if_keyword),
      condition_(condition),
      then_statement_(then_statement),
      else_clause_(else_clause) {}

std::shared_ptr<const SyntaxToken> IfStatementSyntax::IfKeyword() const {
  return if_keyword_;
}

std::shared_ptr<const ExpressionSyntax> IfStatementSyntax::Condition() const {
  return condition_;
}

std::shared_ptr<const StatementSyntax> IfStatementSyntax::ThenStatement()
    const {
  return then_statement_;
}

std::shared_ptr<const ElseClauseSyntax> IfStatementSyntax::ElseClause() const {
  return else_clause_;
}

SyntaxKind IfStatementSyntax::Kind() const { return SyntaxKind::IfStatement; }

}  // namespace simple_compiler