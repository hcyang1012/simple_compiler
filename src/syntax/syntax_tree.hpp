#pragma once

#include <memory>
#include <string>
#include <vector>

#include "syntax_node.hpp"
#include "syntax_token.hpp"
namespace simple_compiler {
class SyntaxTree {
 public:
 SyntaxTree(const std::shared_ptr<const ExpressionSyntax> root,
            const std::vector<std::string> diagnostics,
            const std::shared_ptr<const SyntaxToken> end_of_file_token);

  const std::shared_ptr<const ExpressionSyntax> Root() const ;
  const std::vector<std::string> Diagnostics() const ;
  const std::shared_ptr<const SyntaxToken> EndOfFileToken() const;
 private:
  const std::shared_ptr<const ExpressionSyntax> root_;
  std::vector<std::string> diagnostics_;
  const std::shared_ptr<const SyntaxToken> end_of_file_token_;
};
}  // namespace simple_compiler