#pragma once
#include <string>

#include "text_span.hpp"
namespace simple_compiler {
class Diagnostics {
 public:
  Diagnostics(const TextSpan& span, std::string message);
  const TextSpan& Span() const;
  const std::string& Message() const;

 private:
  const TextSpan span_;
  const std::string message_;
};
}  // namespace simple_compiler