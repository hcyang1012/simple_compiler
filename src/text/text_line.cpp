#include "text_line.hpp"

namespace simple_compiler {
TextLine::TextLine(const std::string& text, const size_t start,
                   const size_t length, const size_t length_with_endings)
    : text_(text),
      start_(start),
      length_(length),
      length_with_endings_(length_with_endings) {}

const std::string& TextLine::Text() const { return text_; }

size_t TextLine::Start() const { return start_; }

size_t TextLine::End() const { return start_ + length_; }

size_t TextLine::Length() const { return length_; }

size_t TextLine::LengthWithEndings() const { return length_with_endings_; }

TextSpan TextLine::Span() const { return TextSpan(start_, length_); }

TextSpan TextLine::SpanIncludingLineBreak() const {
  return TextSpan(start_, length_with_endings_);
}
std::string TextLine::ToString(const size_t start, const size_t length) const {
  return text_.substr(start_, length);
}

std::string TextLine::ToString(const TextSpan& span) const {
  return ToString(span.Start(), span.Length());
}
}  // namespace simple_compiler
