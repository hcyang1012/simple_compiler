#pragma once
#include <string>
namespace simple_compiler {
enum ValueType {
  Int = 0,
};
class Value {
 public:
  explicit Value(int value);
  int AsInt() const;
  ValueType Type() const;
  std::string ToString() const;
 private:
  const ValueType type_;
  union {
    int int_;
  } data_;
};

std::string ToString(const ValueType& value);

}  // namespace simple_compiler