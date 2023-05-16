#include "block_statement_syntax.hpp"

namespace simple_compiler {

BlockStatementSyntax::BlockStatementSyntax(
    const std::shared_ptr<const OpenBraceSyntax> open_brace_token,
    const std::vector<std::shared_ptr<const StatementSyntax>> statements,
    const std::shared_ptr<const CloseBraceSyntax> close_brace_token)
    : open_brace_token_(open_brace_token),
      statements_(statements),
      close_brace_token_(close_brace_token) {}

SyntaxKind BlockStatementSyntax::Kind() const {
  return SyntaxKind::BlockStatement;
}

std::shared_ptr<const OpenBraceSyntax> BlockStatementSyntax::OpenBraceToken()
    const {
  return open_brace_token_;
}

const std::vector<std::shared_ptr<const StatementSyntax>>&
BlockStatementSyntax::Statements() const {
  return statements_;
}

std::shared_ptr<const CloseBraceSyntax> BlockStatementSyntax::CloseBraceToken()
    const {
  return close_brace_token_;
}

}  // namespace simple_compiler