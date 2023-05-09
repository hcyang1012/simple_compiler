#include "syntax_tree.hpp"

#include <memory>

#include "../diagnostics/diagnostics_bag.hpp"
#include "parser.hpp"
namespace simple_compiler {
SyntaxTree::SyntaxTree(const TextSource& text) : text_(text) {
  auto parser = Parser(text);
  auto root = parser.ParseCompilationUnit();
  auto diagnostics = parser.Diagnostics();

  root_ = root;
  diagnostics_ = diagnostics;
}

const std::shared_ptr<const CompilationUnitSyntax> SyntaxTree::Root() const {
  return root_;
}

const std::shared_ptr<const DiagnosticsBag> SyntaxTree::Diagnostics() const {
  return diagnostics_;
}

const TextSource& SyntaxTree::Text() const { return text_; }

std::shared_ptr<const SyntaxTree> SyntaxTree::Parse(const std::string& text) {
  return std::make_shared<SyntaxTree>(text);
}

}  // namespace simple_compiler