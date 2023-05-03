#include "syntax_tree.hpp"

#include <memory>

#include "../diagnostics/diagnostics_bag.hpp"
#include "parser.hpp"
namespace simple_compiler {
SyntaxTree::SyntaxTree(
    const TextSource& text, const std::shared_ptr<const ExpressionSyntax> root,
    const std::shared_ptr<const DiagnosticsBag> diagnostics,
    const std::shared_ptr<const SyntaxToken> end_of_file_token)
    : text_(text),
      root_(root),
      diagnostics_(diagnostics),
      end_of_file_token_(end_of_file_token) {}

const std::shared_ptr<const ExpressionSyntax> SyntaxTree::Root() const {
  return root_;
}

const std::shared_ptr<const DiagnosticsBag> SyntaxTree::Diagnostics() const {
  return diagnostics_;
}

const TextSource& SyntaxTree::Text() const { return text_; }

std::shared_ptr<const SyntaxTree> SyntaxTree::Parse(const std::string& text) {
  Parser parser(text);
  return parser.Parse();
}

}  // namespace simple_compiler