#include "evaluation_result.hpp"

#include <memory>
namespace simple_compiler {
EvaluationResult::EvaluationResult(
    std::shared_ptr<std::vector<std::string>> diagnostics,
    const simple_compiler::Value value)
    : diagnostics_(diagnostics), value_(value) {}

std::shared_ptr<std::vector<std::string>> EvaluationResult::Diagnostics()
    const {
  return diagnostics_;
}
const Value& EvaluationResult::Value() const { return value_; }
}  // namespace simple_compiler