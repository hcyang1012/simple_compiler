#pragma once

#include <memory>
#include <string>
#include <vector>

#include "../diagnostics/diagnostics_bag.hpp"
#include "../text/text_source.hpp"
#include "syntax_node.hpp"
#include "syntax_token.hpp"
#include "compilation_unit_syntax.hpp"

namespace simple_compiler {
class SyntaxTree {
 public:
  SyntaxTree(const TextSource& text);

  const std::shared_ptr<const CompilationUnitSyntax> Root() const;
  const std::shared_ptr<const DiagnosticsBag> Diagnostics() const;
  const std::shared_ptr<const SyntaxToken> EndOfFileToken() const;

  const TextSource& Text() const;

  static std::shared_ptr<const SyntaxTree> Parse(const std::string& text);

 private:
  const TextSource text_;
  std::shared_ptr<const CompilationUnitSyntax> root_;
  std::shared_ptr<const DiagnosticsBag> diagnostics_;
  std::shared_ptr<const SyntaxToken> end_of_file_token_;
};
}  // namespace simple_compiler