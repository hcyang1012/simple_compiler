#pragma once
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "../syntax/variable_symbol.hpp"

namespace simple_compiler {
class BoundScope {
 public:
  BoundScope(std::shared_ptr<BoundScope> parent);
  bool TryDeclare(std::shared_ptr<const VariableSymbol> variable);
  std::shared_ptr<const VariableSymbol> TryLookup(
      const std::string& name) const;
  std::shared_ptr<BoundScope> Parent() const;
  std::vector<std::shared_ptr<const VariableSymbol>> GetDeclaredVariables()
      const;

 private:
  std::shared_ptr<BoundScope> parent_;
  std::map<std::string, std::shared_ptr<const VariableSymbol>> variables_;
};
}  // namespace simple_compiler