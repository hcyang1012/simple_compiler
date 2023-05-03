#include "text_source.hpp"

namespace simple_compiler {
TextSource::TextSource(const std::string& text) : text_(text) { parse_lines(); }
const std::string& TextSource::Text() const { return text_; }
const std::vector<TextLine>& TextSource::Lines() const { return lines_; }
size_t TextSource::GetLineIndex(const size_t position) const {
  size_t lower = 0;
  size_t upper = lines_.size() - 1;

  while (lower <= upper) {
    const size_t kIndex = (lower + upper) / 2;

    const auto kStart = lines_[kIndex].Start();
    if (position == kStart) {
      return kIndex;
    } else if (position < kStart) {
      upper = kIndex - 1;
    } else {
      lower = kIndex + 1;
    }
  }
  return lower - 1;
}
std::string TextSource::ToString(const size_t start,
                                 const size_t length) const {
  return text_.substr(start, length);
}

std::string TextSource::ToString(const TextSpan& span) const {
  return ToString(span.Start(), span.Length());
}
const size_t TextSource::Length() const { return text_.length(); }
char TextSource::operator[](const size_t index) const { return text_[index]; }

void TextSource::parse_lines() {
  lines_.clear();

  size_t position = 0;
  size_t line_start = 0;
  size_t line_length = 0;

  while (position < text_.length()) {
    const size_t kLineBreakLength = get_line_break_length(text_, position);
    if (kLineBreakLength == 0) {
      position++;
      line_length++;
    } else {
      lines_.emplace_back(text_, line_start, line_length,
                          line_length + kLineBreakLength);
      position += kLineBreakLength;
      line_start = position;
      line_length = 0;
    }
  }
  if (line_length > 0) {
    lines_.emplace_back(text_, line_start, line_length, line_length);
  }
}
size_t TextSource::get_line_break_length(const std::string& text,
                                         const size_t position) const {
  auto c = text[position];
  auto l = position + 1 < text.length() ? text[position + 1] : '\0';
  if (c == '\r' && l == '\n') {
    return 2;
  } else if (c == '\r' || c == '\n') {
    return 1;
  } else {
    return 0;
  }
}
}  // namespace simple_compiler