#include "diagnostics.hpp"

namespace simple_compiler {
Diagnostics::Diagnostics(const TextSpan& span, std::string message)
    : span_(span), message_(message) {}

const std::string& Diagnostics::Message() const { return message_; }
const TextSpan& Diagnostics::Span() const { return span_; }
}  // namespace simple_compiler
