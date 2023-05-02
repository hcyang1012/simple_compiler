#include "evaluation_result.hpp"

#include <memory>
namespace simple_compiler {
EvaluationResult::EvaluationResult(
    const std::shared_ptr<const DiagnosticsBag> diagnostics,
    const simple_compiler::Value value)
    : diagnostics_(diagnostics), value_(value) {}

const std::shared_ptr<const DiagnosticsBag> EvaluationResult::Diagnostics()
    const {
  return diagnostics_;
}
const Value& EvaluationResult::Value() const { return value_; }
}  // namespace simple_compiler