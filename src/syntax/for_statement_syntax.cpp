#include "for_statement_syntax.hpp"

namespace simple_compiler {

ForKeywordSyntax::ForKeywordSyntax(std::shared_ptr<const SyntaxToken> keyword)
    : keyword_(keyword) {}

std::shared_ptr<const SyntaxToken> ForKeywordSyntax::Keyword() const {
  return keyword_;
}

SyntaxKind ForKeywordSyntax::Kind() const { return SyntaxKind::ForKeyword; }

ToKeywordSyntax::ToKeywordSyntax(std::shared_ptr<const SyntaxToken> keyword)
    : keyword_(keyword) {}

std::shared_ptr<const SyntaxToken> ToKeywordSyntax::Keyword() const {
  return keyword_;
}

SyntaxKind ToKeywordSyntax::Kind() const { return SyntaxKind::ToKeyword; }

ForStatementSyntax::ForStatementSyntax(
    std::shared_ptr<const ForKeywordSyntax> for_keyword,
    std::shared_ptr<const IdentifierSyntax> identifier,
    std::shared_ptr<const OperatorSyntax> equal_token,
    std::shared_ptr<const ExpressionSyntax> lower_bound,
    std::shared_ptr<const ToKeywordSyntax> to_keyword,
    std::shared_ptr<const ExpressionSyntax> upper_bound,
    std::shared_ptr<const StatementSyntax> body)
    : for_keyword_(for_keyword),
      identifier_(identifier),
      equal_token_(equal_token),
      lower_bound_(lower_bound),
      to_keyword_(to_keyword),
      upper_bound_(upper_bound),
      body_(body) {}

std::shared_ptr<const ForKeywordSyntax> ForStatementSyntax::ForKeyword() const {
  return for_keyword_;
}

std::shared_ptr<const IdentifierSyntax> ForStatementSyntax::Identifier() const {
  return identifier_;
}

std::shared_ptr<const OperatorSyntax> ForStatementSyntax::EqualToken() const {
  return equal_token_;
}

std::shared_ptr<const ExpressionSyntax> ForStatementSyntax::LowerBound() const {
  return lower_bound_;
}

std::shared_ptr<const ToKeywordSyntax> ForStatementSyntax::ToKeyword() const {
  return to_keyword_;
}

std::shared_ptr<const ExpressionSyntax> ForStatementSyntax::UpperBound() const {
  return upper_bound_;
}

std::shared_ptr<const StatementSyntax> ForStatementSyntax::Body() const {
  return body_;
}

SyntaxKind ForStatementSyntax::Kind() const { return SyntaxKind::ForStatement; }

std::vector<std::shared_ptr<const SyntaxNode>> ForStatementSyntax::GetChildren()
    const {
  return {for_keyword_, identifier_,  equal_token_, lower_bound_,
          to_keyword_,  upper_bound_, body_};
}

}  // namespace simple_compiler