#pragma once
#include <string>
namespace simple_compiler {
enum ValueType {
  Int = 0,
  Boolean,
};
class Value {
 public:
  explicit Value(int value);
  explicit Value(bool value);
  int AsInt() const;
  bool AsBool() const;
  ValueType Type() const;
  std::string ToString() const;
 private:
  const ValueType type_;
  union {
    int int_;
    bool boolean_;
  } data_;
};

std::string ToString(const ValueType& value);

}  // namespace simple_compiler