#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "compilation/compilation.hpp"
#include "syntax/value_type.hpp"
#include "syntax/syntax_tree.hpp"

void PrettyPrint(const simple_compiler::SyntaxNode& node,
                 const std::string& indent, bool is_last = true);
int main(int argc, char** argv) {
  auto variables =
      std::make_shared<std::map<std::string, simple_compiler::Value>>();
  while (true) {
    std::cout << "> " << std::flush;
    std::string line;
    std::getline(std::cin, line);
    if (line.length() == 0) {
      break;
    }
    auto tree = simple_compiler::SyntaxTree::Parse(line);

    PrettyPrint(*(tree->Root()), "");

    simple_compiler::Compilation compilation(tree);
    auto result = compilation.Evaluate(variables);

    auto diagnostics = result.Diagnostics();
    for (const auto& diag : diagnostics->Diagnostics()) {
      std::cout << diag.Message() << std::endl;
      auto prefix = line.substr(0, diag.Span().Start());
      auto error = line.substr(diag.Span().Start(), diag.Span().Length());
      auto suffix = line.substr(diag.Span().End());
      std::cout << prefix << "\033[1;31m" << error << "\033[0m" << suffix
                << std::endl;
    }
    std::cout << result.Value().ToString() << std::endl;
  }
  return 0;
}

void PrettyPrint(const simple_compiler::SyntaxNode& node,
                 const std::string& indent, bool is_last) {
  std::string new_indent = indent;
  std::cout << indent;
  if (is_last) {
    std::cout << "└─";
  } else {
    std::cout << "├─";
  }
  new_indent += is_last ? "    " : "│    ";
  std::cout << node.ToString() << std::endl;
  for (const auto& child : node.GetChildren()) {
    PrettyPrint(*child, new_indent, child == node.GetChildren().back());
  }
}