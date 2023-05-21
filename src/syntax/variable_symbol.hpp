#pragma once
#include <string>

#include "../syntax/value_type.hpp"
namespace simple_compiler {
class VariableSymbol {
 public:
  VariableSymbol(const std::string& name, const bool is_read_only,
                 const simple_compiler::Value& value);
  const std::string& Name() const;
  const bool IsReadOnly() const;
  const simple_compiler::Value& Value() const;
  const simple_compiler::ValueType Type() const;

 private:
  std::string name_;
  bool is_read_only_;
  simple_compiler::Value value_;
};
}  // namespace simple_compiler