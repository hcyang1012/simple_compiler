#pragma once
#include <memory>
#include <string>
#include <vector>

#include "../evaluation/evaluation_result.hpp"
#include "../syntax/syntax_tree.hpp"
#include "../syntax/value_type.hpp"

namespace simple_compiler {
class Compilation {
 public:
  Compilation(const std::shared_ptr<const SyntaxTree> syntax_tree);
  EvaluationResult Evaluate() const;
  const std::shared_ptr<const simple_compiler::SyntaxTree> SyntaxTree() const;

 private:
  const std::shared_ptr<const simple_compiler::SyntaxTree> syntax_tree_;
};
}  // namespace simple_compiler