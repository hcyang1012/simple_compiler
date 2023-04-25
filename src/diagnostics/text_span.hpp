#pragma once
#include <cstddef>

namespace simple_compiler {
class TextSpan {
 public:
  TextSpan(const size_t start, const size_t length);
  TextSpan(const TextSpan& other) = default;

  TextSpan& operator=(const TextSpan& other) = default;
  size_t Start() const;
  size_t Length() const;
  size_t End() const;

 private:
  size_t start_;
  size_t length_;
};
}  // namespace simple_compiler