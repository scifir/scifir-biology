cmake_minimum_required(VERSION 3.7.1)

include_directories(.)
link_directories("${CMAKE_INSTALL_PREFIX}/lib")

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(TARGET_H
dna genes_collection taxonomy)

file(GLOB_RECURSE TARGET_SRC dna/*.cpp genes_collection/*.cpp species/*.cpp species_collection/*.cpp)

enable_testing()

project(scifir-biology VERSION 1.0.0)

add_library(scifir-biology ${TARGET_SRC})
#target_link_libraries(scifir-biology boost_locale-mt boost_system-mt boost_thread-mt iconv)

if(BUILD_TESTING)

	find_package(Catch2 CONFIG REQUIRED)

	if(!Catch2_FOUND)
		message("Catch2 not found, tests can't be build.")
	endif()

	if(Catch2_FOUND)
		enable_testing()

		add_executable(test_nbase tests/dna/test_nbase.cpp)
		target_link_libraries(test_nbase PRIVATE Catch2::Catch2WithMain scifir-biology)
		add_test(NAME test_nbase COMMAND test_nbase)
		set_tests_properties(test_nbase PROPERTIES LABELS tests)

		add_executable(test_extended_nbase tests/dna/test_extended_nbase.cpp)
		target_link_libraries(test_extended_nbase PRIVATE Catch2::Catch2WithMain scifir-biology)
		add_test(NAME test_extended_nbase COMMAND test_extended_nbase)
		set_tests_properties(test_extended_nbase PROPERTIES LABELS tests)

		add_executable(test_gene tests/dna/test_gene.cpp)
		target_link_libraries(test_gene PRIVATE Catch2::Catch2WithMain scifir-biology)
		add_test(NAME test_gene COMMAND test_gene)
		set_tests_properties(test_gene PROPERTIES LABELS tests)

		add_executable(benchmark_nbase tests/benchmark_nbase.cpp)
		target_link_libraries(benchmark_nbase PRIVATE Catch2::Catch2WithMain scifir-biology)
		add_test(NAME benchmark_nbase COMMAND benchmark_nbase)
		set_tests_properties(benchmark_nbase PROPERTIES LABELS benchmarks)

		include(CTest)
		include(Catch)

	endif()

endif()

install(TARGETS scifir-biology ARCHIVE DESTINATION lib)
install(FILES biology.hpp DESTINATION include/scifir)
install(DIRECTORY ${TARGET_H} DESTINATION include/scifir/biology
	FILES_MATCHING PATTERN "*.hpp")
