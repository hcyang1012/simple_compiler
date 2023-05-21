#pragma once
#include <memory>
#include <vector>

#include "close_brace_syntax.hpp"
#include "open_brace_syntax.hpp"
#include "syntax_statement.hpp"
#include "syntax_token.hpp"

namespace simple_compiler {
class BlockStatementSyntax : public StatementSyntax {
 public:
  BlockStatementSyntax(
      const std::shared_ptr<const OpenBraceSyntax> open_brace_token,
      const std::vector<std::shared_ptr<const StatementSyntax>> statements,
      const std::shared_ptr<const CloseBraceSyntax> close_brace_token);
  SyntaxKind Kind() const override;
  std::shared_ptr<const OpenBraceSyntax> OpenBraceToken() const;
  const std::vector<std::shared_ptr<const StatementSyntax>>& Statements() const;
  std::shared_ptr<const CloseBraceSyntax> CloseBraceToken() const;
  std::vector<std::shared_ptr<const SyntaxNode>> GetChildren() const override;

 private:
  const std::shared_ptr<const OpenBraceSyntax> open_brace_token_;
  const std::vector<std::shared_ptr<const StatementSyntax>> statements_;
  const std::shared_ptr<const CloseBraceSyntax> close_brace_token_;
};
}  // namespace simple_compiler