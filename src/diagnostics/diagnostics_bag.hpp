#pragma once
#include <memory>
#include <vector>

#include "../syntax/operator_syntax.hpp"
#include "../syntax/syntax_node.hpp"
#include "../syntax/value_type.hpp"
#include "../text/text_span.hpp"
#include "diagnostics.hpp"

namespace simple_compiler {
class DiagnosticsBag {
 public:
  DiagnosticsBag();
  void AddRange(const DiagnosticsBag& diagnostic);

  void Report(const TextSpan& span, std::string message);
  void ReportBadCharacter(const size_t position, const char character);
  void ReportUnexpectedToken(const TextSpan& span, const SyntaxKind actual_kind,
                             const SyntaxKind expected_kind);
  void ReportUndefinedBinaryOperator(const TextSpan& span,
                                     const OperatorSyntax& op,
                                     const ValueType& left_type,
                                     const ValueType& right_type);

  void ReportUndefinedUnaryOperator(const TextSpan& span,
                                    const OperatorSyntax& op,
                                    const ValueType& operand_type);
  void ReportUndefinedName(const TextSpan& span, const std::string& name);

  void ReportVariableAlreadyDeclared(const TextSpan& span,
                                     const std::string& name);
  void ReportCannotConvert(const TextSpan& span, const ValueType& from_type,
                           const ValueType& to_type);
  const std::vector<simple_compiler::Diagnostics>& Diagnostics() const;

 private:
  std::vector<simple_compiler::Diagnostics> diagnostics_;
};
}  // namespace simple_compiler