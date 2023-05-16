#pragma once
#include <memory>
#include <vector>

#include "../diagnostics/diagnostics_bag.hpp"
#include "../syntax/compilation_unit_syntax.hpp"
#include "../syntax/variable_symbol.hpp"
#include "bind_node.hpp"

namespace simple_compiler {
class BoundGlobalScope {
 public:
  BoundGlobalScope(
      std::shared_ptr<const BoundGlobalScope> previous,
      std::shared_ptr<const DiagnosticsBag> diagnostics,
      const std::vector<std::shared_ptr<const VariableSymbol>>& variables,
      std::shared_ptr<const BoundStatementNode> statement);
  std::shared_ptr<const BoundGlobalScope> Previous() const;
  std::shared_ptr<const simple_compiler::DiagnosticsBag> Diagnostics() const;
  const std::vector<std::shared_ptr<const VariableSymbol>>& Variables() const;
  std::shared_ptr<const BoundStatementNode> Statement() const;

 private:
  std::shared_ptr<const BoundGlobalScope> previous_;
  std::shared_ptr<const simple_compiler::DiagnosticsBag> diagnostics_;
  std::vector<std::shared_ptr<const VariableSymbol>> variables_;
  std::shared_ptr<const BoundStatementNode> statement_;
};
}  // namespace simple_compiler