#include <iostream>
#include <string>

#include "binding/binder.hpp"
#include "evaluator.hpp"
#include "syntax/parser.hpp"
#include "syntax/syntax_node.hpp"
#include "syntax/syntax_tree.hpp"

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

    auto binder = simple_compiler::Binder();
    auto bound_tree = binder.BindExpression(tree->Root());

    auto diagnostics = tree->Diagnostics();
    diagnostics.insert(diagnostics.end(), binder.Diagnostics().begin(),
                       binder.Diagnostics().end());
    for (const auto& diag : diagnostics) {
      std::cout << diag << std::endl;
    }

    auto evaluator = simple_compiler::Evaluator(bound_tree);
    std::cout << evaluator.Evaluate().ToString() << std::endl;
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