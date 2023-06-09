cmake_minimum_required(VERSION 3.0.0)
project(my_compiler VERSION 0.1.0)

include(CTest)
enable_testing()

set (CMAKE_CXX_STANDARD 17)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(SOURCES
  ${SRC_DIR}/main.cpp
  ${SRC_DIR}/io.cpp
  ${SRC_DIR}/syntax/syntax_kind.cpp
  ${SRC_DIR}/syntax/syntax_token.cpp
  ${SRC_DIR}/syntax/lexer.cpp
  ${SRC_DIR}/syntax/parser.cpp
  ${SRC_DIR}/syntax/syntax_node.cpp
  ${SRC_DIR}/syntax/syntax_tree.cpp
  ${SRC_DIR}/syntax/syntax_fact.cpp
  ${SRC_DIR}/syntax/value_type.cpp
  ${SRC_DIR}/syntax/literal_expression_syntax.cpp
  ${SRC_DIR}/syntax/operator_syntax.cpp
  ${SRC_DIR}/syntax/binary_expression_syntax.cpp
  ${SRC_DIR}/syntax/unary_expression_syntax.cpp
  ${SRC_DIR}/syntax/open_parenthesis_syntax.cpp
  ${SRC_DIR}/syntax/close_parenthesis_syntax.cpp
  ${SRC_DIR}/syntax/parenthesis_expression_syntax.cpp
  ${SRC_DIR}/syntax/name_expression_syntax.cpp
  ${SRC_DIR}/syntax/assignment_expression_syntax.cpp
  ${SRC_DIR}/syntax/identifier_syntax.cpp
  ${SRC_DIR}/syntax/if_statement_syntax.cpp
  ${SRC_DIR}/syntax/compilation_unit_syntax.cpp
  ${SRC_DIR}/syntax/variable_symbol.cpp
  ${SRC_DIR}/syntax/block_statement_syntax.cpp
  ${SRC_DIR}/syntax/close_brace_syntax.cpp
  ${SRC_DIR}/syntax/open_brace_syntax.cpp
  ${SRC_DIR}/syntax/expression_statement_syntax.cpp
  ${SRC_DIR}/syntax/syntax_variable_declaration.cpp
  ${SRC_DIR}/syntax/while_statement_syntax.cpp
  ${SRC_DIR}/syntax/for_statement_syntax.cpp

  ${SRC_DIR}/binding/bind_node.cpp
  ${SRC_DIR}/binding/binder.cpp
  ${SRC_DIR}/binding/bound_literal_expression.cpp
  ${SRC_DIR}/binding/bound_binary_expression.cpp
  ${SRC_DIR}/binding/bound_unary_expression.cpp
  ${SRC_DIR}/binding/bound_unary_operator.cpp
  ${SRC_DIR}/binding/bound_binary_operator.cpp
  ${SRC_DIR}/binding/bound_assignment_expression.cpp
  ${SRC_DIR}/binding/bound_variable_expression.cpp
  ${SRC_DIR}/binding/bound_scope.cpp
  ${SRC_DIR}/binding/bound_global_scope.cpp
  ${SRC_DIR}/binding/bound_if_statement.cpp
  ${SRC_DIR}/binding/bound_block_statement.cpp
  ${SRC_DIR}/binding/bound_expression_statement.cpp
  ${SRC_DIR}/binding/bound_variable_declaration.cpp
  ${SRC_DIR}/binding/bound_while_statement.cpp
  ${SRC_DIR}/binding/bound_for_statement.cpp


  ${SRC_DIR}/evaluation/evaluator.cpp
  ${SRC_DIR}/evaluation/evaluation_result.cpp

  ${SRC_DIR}/compilation/compilation.cpp

  ${SRC_DIR}/diagnostics/diagnostics.cpp
  ${SRC_DIR}/diagnostics/diagnostics_bag.cpp

  ${SRC_DIR}/text/text_span.cpp
  ${SRC_DIR}/text/text_line.cpp
  ${SRC_DIR}/text/text_source.cpp
)

set(TARGET_NAME my_compiler)
add_executable(${TARGET_NAME} ${SOURCES})
target_include_directories(${TARGET_NAME} PRIVATE ${SRC_DIR})
target_link_libraries(${TARGET_NAME} PRIVATE glog)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
