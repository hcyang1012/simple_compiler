#include "compilation.hpp"

#include <memory>

#include "../binding/binder.hpp"
#include "../binding/bound_global_scope.hpp"
#include "../diagnostics/diagnostics_bag.hpp"
#include "../evaluation/evaluator.hpp"
#include "../syntax/syntax_tree.hpp"

namespace simple_compiler {
Compilation::Compilation(
    const std::shared_ptr<const simple_compiler::SyntaxTree> syntax_tree)
    : Compilation(nullptr, syntax_tree) {}

Compilation::Compilation(
    std::shared_ptr<Compilation> previous,
    std::shared_ptr<const simple_compiler::SyntaxTree> syntax_tree)
    : previous_(previous), syntax_tree_(syntax_tree), global_scope_(nullptr) {}

EvaluationResult Compilation::Evaluate(
    std::shared_ptr<std::map<std::string, Value>> variables) {
  auto diagnostics = std::make_shared<DiagnosticsBag>();
  diagnostics->AddRange(*(syntax_tree_->Diagnostics()));
  diagnostics->AddRange(*(GlobalScope()->Diagnostics()));

  auto evaluator =
      std::make_unique<Evaluator>(global_scope_->Expression(), variables);
  auto value = evaluator->Evaluate();
  return EvaluationResult(diagnostics, value);
}

const std::shared_ptr<const simple_compiler::SyntaxTree>
Compilation::SyntaxTree() const {
  return syntax_tree_;
}

std::shared_ptr<Compilation> Compilation::ContinueWith(
    std::shared_ptr<const simple_compiler::SyntaxTree> syntax_tree) {
  return std::make_shared<Compilation>(shared_from_this(), syntax_tree);
}

std::shared_ptr<const BoundGlobalScope> Compilation::GlobalScope() {
  if (global_scope_ == nullptr) {
    auto prev = previous_ == nullptr ? nullptr : previous_->GlobalScope();
    global_scope_ = Binder::BindGlobalScope(prev, syntax_tree_->Root());
  }
  return global_scope_;
}

}  // namespace simple_compiler
