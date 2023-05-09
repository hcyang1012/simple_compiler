#pragma once
#include <memory>
#include <string>
#include <vector>

#include "syntax_node.hpp"
#include "syntax_token.hpp"
#include "syntax_tree.hpp"
#include "compilation_unit_syntax.hpp"
#include "../diagnostics/diagnostics_bag.hpp"
#include "../text/text_source.hpp"
namespace simple_compiler {
class Parser {
 public:
  Parser(const TextSource& text);
  std::shared_ptr<const CompilationUnitSyntax> ParseCompilationUnit();
  const std::shared_ptr<const DiagnosticsBag> Diagnostics() const;

 private:
  const TextSource text_;
  std::shared_ptr<const ExpressionSyntax> parse_expression();
  std::shared_ptr<const ExpressionSyntax> parse_assignment_expression();
  std::shared_ptr<const ExpressionSyntax> parse_binary_expression(
      const int parent_precedence = 0);
  std::shared_ptr<const ExpressionSyntax> parse_primary_expression();
  std::shared_ptr<const ExpressionSyntax> parse_term();
  std::shared_ptr<const ExpressionSyntax> parse_factor();

  std::shared_ptr<const SyntaxToken> peek(const size_t offset) const;
  std::shared_ptr<const SyntaxToken> current() const;
  std::shared_ptr<const SyntaxToken> next_token();
  std::shared_ptr<const SyntaxToken> match(const SyntaxKind kind);
  std::vector<std::shared_ptr<const SyntaxToken>> tokens_;
  size_t position_;

  std::shared_ptr<DiagnosticsBag> diagnostics_ =
      std::make_shared<DiagnosticsBag>();
};
};  // namespace simple_compiler