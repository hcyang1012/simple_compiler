#pragma once
#include <string>
#include <vector>
#include <memory>

#include "../syntax/value_type.hpp"

namespace simple_compiler {
class EvaluationResult {
 public:
  EvaluationResult(std::shared_ptr<std::vector<std::string>> diagnostics,
                   const Value value);
  std::shared_ptr<std::vector<std::string>> Diagnostics() const;
  const simple_compiler::Value& Value() const;

 private:
  std::shared_ptr<std::vector<std::string>> diagnostics_;
  const simple_compiler::Value value_;
};

}  // namespace simple_compiler