#include "compilation.hpp"

#include <memory>

#include "../binding/binder.hpp"
#include "../evaluation/evaluator.hpp"
#include "../syntax/syntax_tree.hpp"
#include "../diagnostics/diagnostics_bag.hpp"

namespace simple_compiler {
Compilation::Compilation(
    const std::shared_ptr<const simple_compiler::SyntaxTree> syntax_tree)
    : syntax_tree_(syntax_tree) {}

EvaluationResult Compilation::Evaluate(std::shared_ptr<std::map<std::string, Value>> variables) {
  auto binder = Binder(variables);
  auto bound_expression = binder.BindExpression(syntax_tree_->Root()->Expression());

  auto diagnostics = std::make_shared<DiagnosticsBag>();
  diagnostics->AddRange(*(syntax_tree_->Diagnostics()));
  diagnostics->AddRange(*(binder.Diagnostics()));

  auto evaluator = std::make_unique<Evaluator>(bound_expression, variables);
  auto value = evaluator->Evaluate();
  return EvaluationResult(diagnostics, value);
}

const std::shared_ptr<const simple_compiler::SyntaxTree>
Compilation::SyntaxTree() const {
  return syntax_tree_;
}

}  // namespace simple_compiler
