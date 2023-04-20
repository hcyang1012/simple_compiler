cmake_minimum_required(VERSION 3.0.0)
project(my_compiler VERSION 0.1.0)

include(CTest)
enable_testing()


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
  ${SRC_DIR}/evaluator.cpp
)

set(TARGET_NAME my_compiler)
add_executable(${TARGET_NAME} ${SOURCES})
target_include_directories(${TARGET_NAME} PRIVATE ${SRC_DIR})
target_link_libraries(${TARGET_NAME} PRIVATE glog)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
