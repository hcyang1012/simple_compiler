#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>

#include "compilation/compilation.hpp"
#include "syntax/syntax_tree.hpp"
#include "syntax/value_type.hpp"
void PrettyPrint(const simple_compiler::SyntaxNode& node,
                 const std::string& indent, bool is_last = true);
int main(int argc, char** argv) {
  auto variables =
      std::make_shared<std::map<std::string, simple_compiler::Value>>();
  std::stringstream ss;
  std::shared_ptr<simple_compiler::Compilation> previous = nullptr;
  while (true) {
    if (ss.str().length() == 0) {
      std::cout << "> " << std::flush;
    } else {
      std::cout << "| " << std::flush;
    }
    std::string line;
    std::getline(std::cin, line);
    bool is_empty = (line.length() == 0);

    if (ss.str().length() == 0) {
      if (is_empty) {
        break;
      }
    }

    ss << line << std::endl;
    const auto text = ss.str();
    auto tree = simple_compiler::SyntaxTree::Parse(text);
    if (!is_empty && tree->Diagnostics()->Diagnostics().size() > 0) {
      continue;
    }

    auto compilation =
        previous == nullptr
            ? std::make_shared<simple_compiler::Compilation>(tree)
            : previous->ContinueWith(tree);
    auto result = compilation->Evaluate(variables);
    PrettyPrint(*(tree->Root()), "");

    auto diagnostics = result.Diagnostics();
    if (diagnostics->Diagnostics().size() == 0) {
      std::cout << result.Value().ToString() << std::endl;
      previous = compilation;
    } else {
      for (const auto& diag : diagnostics->Diagnostics()) {
        const auto kLineIndex = tree->Text().GetLineIndex(diag.Span().Start());
        const auto& kErrorLine = tree->Text().Lines()[kLineIndex];
        const size_t kLineNumber = kLineIndex + 1;
        const auto kErrorColumn = diag.Span().Start() - kErrorLine.Start() + 1;
        std::cout << "Line " << kLineNumber << ":" << kErrorColumn << " "
                  << diag.Message() << std::endl;

        std::cout << diag.Message() << std::endl;
        auto prefix_span = simple_compiler::TextSpan::FromBounds(
            kErrorLine.Start(), diag.Span().Start());
        auto postfix_span = simple_compiler::TextSpan::FromBounds(
            diag.Span().End(), kErrorLine.End());

        auto prefix = tree->Text().ToString(prefix_span);
        auto error = tree->Text().ToString(diag.Span());
        auto suffix = tree->Text().ToString(postfix_span);
        std::cout << prefix << "\033[1;31m" << error << "\033[0m" << suffix
                  << std::endl;
      }
    }

    ss.str("");
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