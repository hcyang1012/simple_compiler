#pragma once
#include <memory>
#include <vector>

#include "../diagnostics/diagnostics.hpp"
#include "syntax/value_type.hpp"
#include "syntax_kind.hpp"
#include "syntax_token.hpp"
namespace simple_compiler {

class SyntaxNode {
 public:
  virtual SyntaxKind Kind() const = 0;
  virtual std::vector<std::shared_ptr<const SyntaxNode>> GetChildren() const;
  virtual std::string ValueText() const;
  virtual TextSpan Span() const;
  std::string ToString() const;

 private:
};

class SyntaxToken;

class ExpressionSyntax : public SyntaxNode {};


};  // namespace simple_compiler
