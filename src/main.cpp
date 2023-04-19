#include <iostream>
#include <string>

#include "evaluator.hpp"
#include "parser.hpp"
#include "syntax_node.hpp"
#include "syntax_tree.hpp"

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

    if (tree->Diagnostics().size() > 0) {
      for (const auto& diag : tree->Diagnostics()) {
        std::cout << diag << std::endl;
      }
    }

    auto evaluator = simple_compiler::Evaluator(tree->Root());
    std::cout << evaluator.Evaluate() << std::endl;
  }
  return 0;
}

void PrettyPrint(const simple_compiler::SyntaxNode& node,
                 const std::string& indent, bool is_last) {
  // ├─
  // └─
  // │

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