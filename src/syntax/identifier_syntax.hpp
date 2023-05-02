#pragma once
#include "syntax_node.hpp"
#include <memory>
#include <vector>
namespace simple_compiler {
    class IdentifierSyntax : public SyntaxNode {
        public:
        IdentifierSyntax(const std::shared_ptr<const SyntaxToken> identifier_token);
        std::shared_ptr<const SyntaxToken> IdentifierToken() const;
        std::string ValueText() const;
        SyntaxKind Kind() const override;
        TextSpan Span() const override;
        private:
        std::shared_ptr<const SyntaxToken> identifier_token_;
    };
}