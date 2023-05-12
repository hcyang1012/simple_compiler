#pragma once
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "../binding/bound_global_scope.hpp"
#include "../evaluation/evaluation_result.hpp"
#include "../syntax/syntax_tree.hpp"
#include "../syntax/value_type.hpp"

namespace simple_compiler {
class Compilation : public std::enable_shared_from_this<Compilation> {
 public:
  Compilation(const std::shared_ptr<const SyntaxTree> syntax_tree);
  Compilation(std::shared_ptr<Compilation> previous,
              std::shared_ptr<const SyntaxTree> syntax_tree);
  EvaluationResult Evaluate(
      std::shared_ptr<std::map<std::string, Value>> variables);
  const std::shared_ptr<const simple_compiler::SyntaxTree> SyntaxTree() const;
  std::shared_ptr<Compilation> ContinueWith(
      std::shared_ptr<const simple_compiler::SyntaxTree> syntax_tree);

  std::shared_ptr<const BoundGlobalScope> GlobalScope();

 private:
  std::shared_ptr<Compilation> previous_;
  const std::shared_ptr<const simple_compiler::SyntaxTree> syntax_tree_;
  std::shared_ptr<const BoundGlobalScope> global_scope_;
};
}  // namespace simple_compiler