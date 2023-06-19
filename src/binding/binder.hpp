#pragma once
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "../diagnostics/diagnostics_bag.hpp"
#include "../syntax/assignment_expression_syntax.hpp"
#include "../syntax/binary_expression_syntax.hpp"
#include "../syntax/block_statement_syntax.hpp"
#include "../syntax/compilation_unit_syntax.hpp"
#include "../syntax/expression_statement_syntax.hpp"
#include "../syntax/if_statement_syntax.hpp"
#include "../syntax/literal_expression_syntax.hpp"
#include "../syntax/name_expression_syntax.hpp"
#include "../syntax/parenthesis_expression_syntax.hpp"
#include "../syntax/syntax_node.hpp"
#include "../syntax/syntax_variable_declaration.hpp"
#include "../syntax/unary_expression_syntax.hpp"
#include "../syntax/while_statement_syntax.hpp"
#include "../syntax/for_statement_syntax.hpp"
#include "bind_node.hpp"
#include "bound_binary_expression.hpp"
#include "bound_block_statement.hpp"
#include "bound_expression_statement.hpp"
#include "bound_global_scope.hpp"
#include "bound_literal_expression.hpp"
#include "bound_scope.hpp"
#include "bound_unary_expression.hpp"
#include "bound_variable_declaration.hpp"
#include "bound_while_statement.hpp"
#include "bound_for_statement.hpp"

namespace simple_compiler {
class Binder {
 public:
  Binder(std::shared_ptr<BoundScope> parent);
  std::shared_ptr<BoundStatementNode> BindStatement(
      const std::shared_ptr<const StatementSyntax> syntax);
  const std::shared_ptr<const DiagnosticsBag> Diagnostics() const;
  std::shared_ptr<const BoundScope> Scope() const;

  static std::shared_ptr<const BoundGlobalScope> BindGlobalScope(
      std::shared_ptr<const BoundGlobalScope> previous,
      std::shared_ptr<const CompilationUnitSyntax> syntax);

  static std::shared_ptr<BoundScope> CreateParentScope(
      std::shared_ptr<const BoundGlobalScope> previous);

 private:
  const std::shared_ptr<DiagnosticsBag> diagnostics_ =
      std::make_shared<DiagnosticsBag>();

  std::shared_ptr<BoundScope> scope_ = nullptr;

  std::shared_ptr<BoundBlockStatementNode> bind_block_statement(
      const std::shared_ptr<const BlockStatementSyntax> syntax);
  std::shared_ptr<BoundExpressionStatementNode> bind_expression_statement(
      const std::shared_ptr<const ExpressionStatementSyntax> syntax);
  std::shared_ptr<BoundVariableDeclarationNode> bind_variable_declaration(
      const std::shared_ptr<const VariableDeclarationSyntax> syntax);
  std::shared_ptr<BoundStatementNode> bind_if_statement(
      const std::shared_ptr<const IfStatementSyntax> syntax);
  std::shared_ptr<BoundWhileStatementNode> bind_while_statement(
      const std::shared_ptr<const WhileStatementSyntax> syntax);
  std::shared_ptr<BoundForStatementNode> bind_for_statement(
      const std::shared_ptr<const ForStatementSyntax> syntax);

  std::shared_ptr<BoundExpressionNode> bind_expression(
      const std::shared_ptr<const ExpressionSyntax> syntax);
  std::shared_ptr<BoundExpressionNode> bind_expression(
      const std::shared_ptr<const ExpressionSyntax> syntax,
      const ValueType& expected_type);

  std::shared_ptr<BoundExpressionNode> bind_literal_expression(
      const std::shared_ptr<const LiteralExpressionSyntax> syntax);
  std::shared_ptr<BoundExpressionNode> bind_binary_expression(
      const std::shared_ptr<const BinaryExpressionSyntax> syntax);
  std::shared_ptr<BoundExpressionNode> bind_unary_expression(
      const std::shared_ptr<const UnaryExpressionSyntax> syntax);
  std::shared_ptr<BoundUnaryOperatorKind> bind_unary_operator_kind(
      const SyntaxKind kind, const ValueType type);
  std::shared_ptr<BoundBinaryOperatorKind> bind_binary_operator_kind(
      const SyntaxKind kindl, const ValueType left_type,
      const ValueType right_type);
  std::shared_ptr<BoundExpressionNode> bind_parenthesized_expression(
      const std::shared_ptr<const ParenthesizedExpressionSyntax> syntax);
  std::shared_ptr<BoundExpressionNode> bind_name_expression(
      std::shared_ptr<const NameExpressionSyntax> identifier);
  std::shared_ptr<BoundExpressionNode> bind_assignment_expression(
      std::shared_ptr<const AssignmentExpressionSyntax> syntax);
};
}  // namespace simple_compiler