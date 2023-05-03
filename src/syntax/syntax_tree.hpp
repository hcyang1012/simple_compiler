#pragma once

#include <memory>
#include <string>
#include <vector>

#include "../diagnostics/diagnostics_bag.hpp"
#include "syntax_node.hpp"
#include "syntax_token.hpp"
namespace simple_compiler {
class SyntaxTree {
 public:
  SyntaxTree(const std::shared_ptr<const ExpressionSyntax> root,
             const std::shared_ptr<const DiagnosticsBag> diagnostics,
             const std::shared_ptr<const SyntaxToken> end_of_file_token);

  const std::shared_ptr<const ExpressionSyntax> Root() const;
  const std::shared_ptr<const DiagnosticsBag> Diagnostics() const;
  const std::shared_ptr<const SyntaxToken> EndOfFileToken() const;

  static std::shared_ptr<const SyntaxTree> Parse(const std::string& text);

 private:
  const std::shared_ptr<const ExpressionSyntax> root_;
  const std::shared_ptr<const DiagnosticsBag> diagnostics_;
  const std::shared_ptr<const SyntaxToken> end_of_file_token_;
};
}  // namespace simple_compiler