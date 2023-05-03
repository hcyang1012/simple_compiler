#pragma once
#include <string>

#include "../text/text_span.hpp"
namespace simple_compiler {
class Diagnostics {
 public:
  Diagnostics(const TextSpan& span, std::string message);
  Diagnostics(const Diagnostics& diagnostics) = default;

  Diagnostics& operator=(const Diagnostics& diagnostics) = default;
  const TextSpan& Span() const;
  const std::string& Message() const;

 private:
  TextSpan span_;
  std::string message_;
};
}  // namespace simple_compiler