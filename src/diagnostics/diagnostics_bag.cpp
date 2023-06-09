#include "diagnostics_bag.hpp"

#include <memory>
#include <string>

#include "../syntax/syntax_node.hpp"
#include "../syntax/value_type.hpp"
namespace simple_compiler {
DiagnosticsBag::DiagnosticsBag() {}
void DiagnosticsBag::AddRange(const DiagnosticsBag& diagnostic) {
  diagnostics_.insert(diagnostics_.begin(), diagnostic.Diagnostics().begin(),
                      diagnostic.Diagnostics().end());
}
void DiagnosticsBag::Report(const TextSpan& span, std::string message) {
  diagnostics_.emplace_back(span, message);
}
void DiagnosticsBag::ReportBadCharacter(const size_t position,
                                        const char character) {
  diagnostics_.emplace_back(TextSpan(position, 1),
                            "Lexer ERROR: bad character input: " + character);
}
void DiagnosticsBag::ReportUnexpectedToken(const TextSpan& span,
                                           const SyntaxKind actual_kind,
                                           const SyntaxKind expected_kind) {
  diagnostics_.emplace_back(
      span, "Parser ERROR: Unexpected token: " + ToString(actual_kind) +
                ". Expected: " + ToString(expected_kind));
}
void DiagnosticsBag::ReportUndefinedBinaryOperator(
    const TextSpan& span, const OperatorSyntax& op, const ValueType& left_type,
    const ValueType& right_type) {
  diagnostics_.emplace_back(
      span, "Binary operator " + op.ValueText() + " is not defined for types " +
                ToString(left_type) + " and " + ToString(right_type) + ".");
}
void DiagnosticsBag::ReportUndefinedUnaryOperator(
    const TextSpan& span, const OperatorSyntax& op,
    const ValueType& operand_type) {
  diagnostics_.emplace_back(span, "Unary operator " + op.ValueText() +
                                      " is not defined for type " +
                                      ToString(operand_type) + ".");
}
void DiagnosticsBag::ReportUndefinedName(const TextSpan& span,
                                         const std::string& name) {
  diagnostics_.emplace_back(span, "Variable " + name + " is not defined.");
}
void DiagnosticsBag::ReportVariableAlreadyDeclared(const TextSpan& span,
                                                   const std::string& name) {
  diagnostics_.emplace_back(span, "Variable " + name + " is already declared.");
}
void DiagnosticsBag::ReportCannotConvert(const TextSpan& span,
                                         const ValueType& from_type,
                                         const ValueType& to_type) {
  diagnostics_.emplace_back(span, "Cannot convert type " + ToString(from_type) +
                                      " to " + ToString(to_type) + ".");
}
void DiagnosticsBag::ReportCannotAssign(const TextSpan& span,
                                        const std::string& name) {
  diagnostics_.emplace_back(
      span, "Variable " + name + " is read-only and cannot be assigned to.");
}
const std::vector<simple_compiler::Diagnostics>& DiagnosticsBag::Diagnostics()
    const {
  return diagnostics_;
}
}  // namespace simple_compiler
