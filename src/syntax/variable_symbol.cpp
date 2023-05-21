#include "variable_symbol.hpp"

namespace simple_compiler {
VariableSymbol::VariableSymbol(const std::string& name, const bool is_read_only,
                               const simple_compiler::Value& value)
    : name_(name), is_read_only_(is_read_only), value_(value) {}

const std::string& VariableSymbol::Name() const { return name_; }
const bool VariableSymbol::IsReadOnly() const { return is_read_only_; }
const simple_compiler::Value& VariableSymbol::Value() const { return value_; }
const simple_compiler::ValueType VariableSymbol::Type() const {
  return value_.Type();
}
}  // namespace simple_compiler
