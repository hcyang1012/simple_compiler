#pragma once
#include <string>
namespace simple_compiler {
enum ValueType {
  Int = 0,
  Boolean,
};
class Value {
 public:
  Value(const Value& other);
  explicit Value(int value);
  explicit Value(bool value);
  static Value Build(const ValueType type);
  int AsInt() const;
  bool AsBool() const;
  bool Equals(const Value& other) const;
  ValueType Type() const;
  std::string ToString() const;
 private:
  ValueType type_;
  union {
    int int_;
    bool boolean_;
  } data_;
};

std::string ToString(const ValueType& value);

}  // namespace simple_compiler