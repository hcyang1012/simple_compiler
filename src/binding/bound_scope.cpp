#include "bound_scope.hpp"

namespace simple_compiler {
BoundScope::BoundScope(std::shared_ptr<BoundScope> parent)
    : parent_(parent) {}

bool BoundScope::TryDeclare(
    const std::shared_ptr<const VariableSymbol> variable) {
  if (variables_.find(variable->Name()) != variables_.end()) {
    return false;
  }
  variables_.insert({variable->Name(), variable});
  return true;
}

std::shared_ptr<const VariableSymbol> BoundScope::TryLookup(
    const std::string& name) const {
  if (variables_.find(name) != variables_.end()) {
    return variables_.at(name);
  }
  if (parent_ != nullptr) {
    return parent_->TryLookup(name);
  }
  return nullptr;
}

std::shared_ptr<BoundScope> BoundScope::Parent() const { return parent_; }

std::vector<std::shared_ptr<const VariableSymbol>>
BoundScope::GetDeclaredVariables() const {
  std::vector<std::shared_ptr<const VariableSymbol>> variables;
  for (const auto& variable : variables_) {
    variables.push_back(variable.second);
  }
  return variables;
}

}  // namespace simple_compiler
