#include "value_type.hpp"

namespace simple_compiler {
Value::Value(int value) : type_(ValueType::Int), data_({.int_ = value}) {}

int Value::AsInt() const { return data_.int_; }

ValueType Value::Type() const { return type_; }

std::string ToString(const ValueType& value) {
  switch (value) {
    case ValueType::Int:
      return "int";
  }
  return "";
}

std::string Value::ToString() const {
  switch (type_) {
    case ValueType::Int:
      return std::to_string(data_.int_);
  }
  return "";
}
}  // namespace simple_compiler
