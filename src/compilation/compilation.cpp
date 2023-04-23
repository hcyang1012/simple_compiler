#include "compilation.hpp"

#include <memory>

#include "../binding/binder.hpp"
#include "../evaluation/evaluator.hpp"
#include "../syntax/syntax_tree.hpp"

namespace simple_compiler {
Compilation::Compilation(
    const std::shared_ptr<const simple_compiler::SyntaxTree> syntax_tree)
    : syntax_tree_(syntax_tree) {}

EvaluationResult Compilation::Evaluate() const {
  auto binder = Binder();
  auto bound_expression = binder.BindExpression(syntax_tree_->Root());

  auto diagnostics = syntax_tree_->Diagnostics();
  diagnostics.insert(diagnostics.end(), binder.Diagnostics().begin(),
                     binder.Diagnostics().end());

  auto evaluator = Evaluator(bound_expression);
  auto value = evaluator.Evaluate();
  return EvaluationResult(std::make_shared<std::vector<std::string>>(), value);
}

const std::shared_ptr<const simple_compiler::SyntaxTree>
Compilation::SyntaxTree() const {
  return syntax_tree_;
}

}  // namespace simple_compiler
