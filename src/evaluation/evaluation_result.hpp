#pragma once
#include <string>
#include <vector>
#include <memory>

#include "../syntax/value_type.hpp"
#include "../diagnostics/diagnostics_bag.hpp"

namespace simple_compiler {
class EvaluationResult {
 public:
  EvaluationResult(const std::shared_ptr<const DiagnosticsBag> diagnostics,
                   const Value value);
  const std::shared_ptr<const DiagnosticsBag> Diagnostics() const;
  const simple_compiler::Value& Value() const;

 private:
  const std::shared_ptr<const DiagnosticsBag> diagnostics_;
  const simple_compiler::Value value_;
};

}  // namespace simple_compiler