#include "syntax_tree.hpp"

namespace simple_compiler {
SyntaxTree::SyntaxTree(
    const std::shared_ptr<const ExpressionSyntax> root,
    const std::vector<std::string> diagnostics,
    const std::shared_ptr<const SyntaxToken> end_of_file_token)
    : root_(root),
      diagnostics_(diagnostics),
      end_of_file_token_(end_of_file_token) {}

const std::shared_ptr<const ExpressionSyntax> SyntaxTree::Root() const {
  return root_;
}

const std::vector<std::string> SyntaxTree::Diagnostics() const {
  return diagnostics_;
}
}  // namespace simple_compiler