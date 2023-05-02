#pragma once
#include "syntax_node.hpp"
#include "operator_syntax.hpp"
namespace simple_compiler {
    class AssignmentExpressionSyntax : public ExpressionSyntax {
        public:
        AssignmentExpressionSyntax(
            const std::shared_ptr<const SyntaxNode> identifier_node,
            const std::shared_ptr<const OperatorSyntax> op,
            const std::shared_ptr<const ExpressionSyntax> expression_node);
        
        SyntaxKind Kind() const override;
        std::vector<std::shared_ptr<const SyntaxNode>> GetChildren() const override;
        const std::shared_ptr<const SyntaxNode> GetIdentifierToken() const;
        const std::shared_ptr<const OperatorSyntax> GetOperatorToken() const;
        const std::shared_ptr<const ExpressionSyntax> GetExpression() const;
        
        private:
        const std::shared_ptr<const SyntaxNode> identifier_node_;
        const std::shared_ptr<const OperatorSyntax> op_;
        const std::shared_ptr<const ExpressionSyntax> expression_node_;
    };
}