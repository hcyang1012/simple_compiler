#include "value_type.hpp"

namespace simple_compiler {
Value::Value(int value) : type_(ValueType::Int), data_({.int_ = value}) {}
Value::Value(bool value)
    : type_(ValueType::Boolean), data_({.boolean_ = value}) {}

int Value::AsInt() const { return data_.int_; }

bool Value::AsBool() const { return data_.boolean_; }

bool Value::Equals(const Value& other) const {
  if (type_ != other.type_) {
    return false;
  }
  switch (type_) {
    case ValueType::Int:
      return data_.int_ == other.data_.int_;
    case ValueType::Boolean:
      return data_.boolean_ == other.data_.boolean_;
  }
  return false;
}

ValueType Value::Type() const { return type_; }

std::string ToString(const ValueType& value) {
  switch (value) {
    case ValueType::Int:
      return "int";
    case ValueType::Boolean:
      return "boolean";
  }
  return "";
}

std::string Value::ToString() const {
  switch (type_) {
    case ValueType::Int:
      return std::to_string(data_.int_);
    case ValueType::Boolean:
      return data_.boolean_ ? "true" : "false";
  }
  return "";
}
}  // namespace simple_compiler
