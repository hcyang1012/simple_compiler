#include "text_span.hpp"

#include <cstddef>
namespace simple_compiler {
TextSpan::TextSpan(const size_t start, const size_t length)
    : start_(start), length_(length) {}

size_t TextSpan::Start() const { return start_; }
size_t TextSpan::Length() const { return length_; }
size_t TextSpan::End() const { return start_ + length_; }

}  // namespace simple_compiler
