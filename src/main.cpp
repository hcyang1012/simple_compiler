#include <iostream>
#include <string>

#include "compilation/compilation.hpp"
#include "syntax/parser.hpp"

void PrettyPrint(const simple_compiler::SyntaxNode& node,
                 const std::string& indent, bool is_last = true);
int main(int argc, char** argv) {
  while (true) {
    std::cout << "> " << std::flush;
    std::string line;
    std::getline(std::cin, line);
    if (line.length() == 0) {
      break;
    }
    auto parser = simple_compiler::Parser(line);
    auto tree = parser.Parse();

    PrettyPrint(*(tree->Root()), "");

    simple_compiler::Compilation compilation(tree);
    auto result = compilation.Evaluate();

    auto diagnostics = result.Diagnostics();
    for (const auto& diag : *diagnostics) {
      std::cout << diag << std::endl;
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