cmake_minimum_required(VERSION 3.7.1)

find_package(Catch2 REQUIRED)

include_directories(.)
link_directories("${CMAKE_INSTALL_PREFIX}/lib")

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#set(CMAKE_CXX_COMPILER C:/Programas/MSYS2/mingw64/bin/g++.exe)

set(TARGET_H
dna genes_collection taxonomy)

file(GLOB_RECURSE TARGET_SRC dna/*.cpp genes_collection/*.cpp taxonomy/*.cpp)

enable_testing()

project(scifir-biology VERSION 1.0.0)

add_library(scifir-biology ${TARGET_SRC})
#target_link_libraries(scifir-biology boost_locale-mt boost_system-mt boost_thread-mt iconv)

add_executable(test_generic_nbase tests/test_generic_nbase.cpp)
target_link_libraries(test_generic_nbase PRIVATE Catch2::Catch2 scifir-biology)
add_test(NAME test_generic_nbase COMMAND test_generic_nbase)
set_tests_properties(test_generic_nbase PROPERTIES LABELS tests)

add_executable(test_custom_nbase tests/test_custom_nbase.cpp)
target_link_libraries(test_custom_nbase PRIVATE Catch2::Catch2 scifir-biology)
add_test(NAME test_custom_nbase COMMAND test_custom_nbase)
set_tests_properties(test_custom_nbase PROPERTIES LABELS tests)

add_executable(test_generic_gene tests/test_generic_gene.cpp)
target_link_libraries(test_generic_gene PRIVATE Catch2::Catch2 scifir-biology)
add_test(NAME test_generic_gene COMMAND test_generic_gene)
set_tests_properties(test_generic_gene PROPERTIES LABELS tests)

add_executable(benchmark_nbase tests/benchmark_nbase.cpp)
target_link_libraries(benchmark_nbase PRIVATE Catch2::Catch2 scifir-biology)
add_test(NAME benchmark_nbase COMMAND benchmark_nbase)
set_tests_properties(benchmark_nbase PROPERTIES LABELS benchmarks)

include(CTest)
include(Catch)

install(TARGETS scifir-biology ARCHIVE DESTINATION lib)
install(FILES biology.hpp DESTINATION include/scifir)
install(DIRECTORY ${TARGET_H} DESTINATION include/scifir/biology
	FILES_MATCHING PATTERN "*.hpp")
