cmake_minimum_required(VERSION 3.13)
project(spl_run)
set(CMAKE_CXX_STANDARD 14)
set(CXX_FLAGS
    -g
)
set(CMAKE_BUILD_TYPE "Debug")

include_directories(${CMAKE_SOURCE_DIR}/include)

find_package(BISON)
find_package(FLEX)
BISON_TARGET(spl_run_parser ${CMAKE_SOURCE_DIR}/src/parser/SyntaxAnalysis.y ${CMAKE_SOURCE_DIR}/src/parser/parser.cpp
            COMPILE_FLAGS -v
            DEFINES_FILE ${CMAKE_SOURCE_DIR}/include/parser.h
            )

FLEX_TARGET(spl_run_lexer ${CMAKE_SOURCE_DIR}/src/parser/LexicalAnalysis.l ${CMAKE_SOURCE_DIR}/src/parser/lexer.cpp)

ADD_FLEX_BISON_DEPENDENCY(spl_run_lexer spl_run_parser)

add_library(spl_parser SHARED ${BISON_spl_run_parser_OUTPUTS} ${FLEX_spl_run_lexer_OUTPUTS})
target_include_directories(spl_parser PUBLIC /usr/include/llvm-14/ /usr/include/llvm-c-14/)

set(
    SOURCES_FILE
    ${CMAKE_SOURCE_DIR}/src/generator/TargetGenerator.cc
    ${CMAKE_SOURCE_DIR}/src/generator/IRGenerator.cc
    ${CMAKE_SOURCE_DIR}/src/AbstractSyntaxTree.cc
    ${CMAKE_SOURCE_DIR}/src/Visualization.cc
    ${CMAKE_SOURCE_DIR}/src/demo.cc
)

add_executable(demo ${SOURCES_FILE})
target_include_directories(demo PUBLIC /usr/include/llvm-14/ /usr/include/llvm-c-14/)
target_link_directories(demo PUBLIC /usr/lib/llvm-14/lib/ ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(demo LLVM spl_parser cjson)
find_library(LEX_LIB l)
target_link_libraries(demo ${LEX_LIB})