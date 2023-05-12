#pragma once
#include <string>
#include "../syntax/value_type.hpp"
namespace simple_compiler {
  class VariableSymbol{
    public:
    VariableSymbol(const std::string& name, const simple_compiler::Value& value);
    const std::string& Name() const;
    const simple_compiler::Value& Value() const;
    const simple_compiler::ValueType Type() const;

    private:
    std::string name_;
    simple_compiler::Value value_;
  };
}