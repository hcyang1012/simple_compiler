#pragma once
#include <memory>
#include <string>
#include <vector>
#include <map>

#include "../evaluation/evaluation_result.hpp"
#include "../syntax/syntax_tree.hpp"
#include "../syntax/value_type.hpp"

namespace simple_compiler {
class Compilation {
 public:
  Compilation(const std::shared_ptr<const SyntaxTree> syntax_tree);
  EvaluationResult Evaluate(std::shared_ptr<std::map<std::string, Value>> variables);
  const std::shared_ptr<const simple_compiler::SyntaxTree> SyntaxTree() const;

 private:
  const std::shared_ptr<const simple_compiler::SyntaxTree> syntax_tree_;
};
}  // namespace simple_compiler