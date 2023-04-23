#pragma once

namespace simple_compiler {
class TextSpan {
 public:
  TextSpan(const size_t start, const size_t length);
  size_t Start() const;
  size_t Length() const;
  size_t End() const;

 private:
  const size_t start_;
  const size_t length_;
}
}  // namespace simple_compiler