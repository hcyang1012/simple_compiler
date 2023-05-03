#pragma once
#include <string>
#include <memory>
#include <vector>
#include "text_line.hpp"

namespace simple_compiler {
  class TextSource {
    public:
      TextSource(const std::string& text);
      const std::string& Text() const;
      const std::vector<TextLine>& Lines() const;
      size_t GetLineIndex(const size_t position) const;

      std::string ToString(const size_t start, const size_t length) const;
      std::string ToString(const TextSpan& span) const;

      const size_t Length() const;
      char operator[](const size_t index) const;
    private:
      const std::string text_;
      std::vector<TextLine> lines_;

      void parse_lines();
      size_t get_line_break_length(const std::string& text, const size_t position) const;
  };
}