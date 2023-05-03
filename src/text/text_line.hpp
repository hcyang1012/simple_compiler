#pragma once
#include <string>
#include "text_span.hpp"

namespace simple_compiler{
  class TextLine{
    public:
      TextLine(const std::string& text, const size_t start, const size_t length, const size_t length_with_endings);
      const std::string& Text() const;
      size_t Start() const;
      size_t End() const;
      size_t Length() const;
      size_t LengthWithEndings() const;
      TextSpan Span() const;
      TextSpan SpanIncludingLineBreak() const;
      std::string ToString(const size_t start, const size_t length) const;
      std::string ToString(const TextSpan& span) const;
    private:
      const std::string text_;
      const size_t start_;
      const size_t length_;
      const size_t length_with_endings_;
  };
}