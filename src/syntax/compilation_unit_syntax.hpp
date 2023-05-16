#pragma once

#include <memory>

#include "syntax_node.hpp"
#include "syntax_statement.hpp"

namespace simple_compiler {
class CompilationUnitSyntax : public SyntaxNode {
 public:
  CompilationUnitSyntax(std::shared_ptr<const StatementSyntax> statement,
                        std::shared_ptr<const SyntaxToken> endOfFileToken);
  SyntaxKind Kind() const override;
  std::vector<std::shared_ptr<const SyntaxNode>> GetChildren() const override;
  const std::shared_ptr<const StatementSyntax> Statement() const;
  const std::shared_ptr<const SyntaxToken> EndOfFileToken() const;
 private:
  std::shared_ptr<const StatementSyntax> statement_;
  std::shared_ptr<const SyntaxToken> endOfFileToken_;
};
}  // namespace simple_compiler