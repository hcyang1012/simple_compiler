#include "syntax_node.hpp"

#include "syntax_kind.hpp"

namespace simple_compiler {
std::string SyntaxNode::ValueText() const { return ""; }

TextSpan SyntaxNode::Span() const { return TextSpan(0, 0); }

std::vector<std::shared_ptr<const SyntaxNode>> SyntaxNode::GetChildren() const {
  return {};
}

std::string SyntaxNode::ToString() const {
  return simple_compiler::ToString(Kind()) + ": " + ValueText();
}

}  // namespace simple_compiler
