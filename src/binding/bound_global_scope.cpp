#include "bound_global_scope.hpp"

#include "binder.hpp"
namespace simple_compiler {
BoundGlobalScope::BoundGlobalScope(
    std::shared_ptr<const BoundGlobalScope> previous,
    std::shared_ptr<const simple_compiler::DiagnosticsBag> diagnostics,
    const std::vector<std::shared_ptr<const VariableSymbol>>& variables,
    std::shared_ptr<const BoundStatementNode> statement)
    : previous_(previous),
      diagnostics_(diagnostics),
      variables_(variables),
      statement_(statement) {}

std::shared_ptr<const BoundGlobalScope> BoundGlobalScope::Previous() const {
  return previous_;
}

std::shared_ptr<const simple_compiler::DiagnosticsBag>
BoundGlobalScope::Diagnostics() const {
  return diagnostics_;
}

const std::vector<std::shared_ptr<const VariableSymbol>>&
BoundGlobalScope::Variables() const {
  return variables_;
}

std::shared_ptr<const BoundStatementNode> BoundGlobalScope::Statement()
    const {
  return statement_;
}

}  // namespace simple_compiler
