#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch2/catch_all.hpp"

#include "../dna/nbase.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

class nbase_char
{
	public:
		nbase_char(char);

		char base_type2;
};

nbase_char::nbase_char(char new_char) : base_type2(new_char)
{}

TEST_CASE("generic_nbase class","Full test of generic_nbase") {
	BENCHMARK("generic_nbase with enum") {
		scifir::nbase a = scifir::nbase(nbase::A);
		string b = to_string(a.base);
    };

	BENCHMARK("generic_nbase with char") {
        nbase_char a = nbase_char('A');
		string b = to_string(a.base_type2);
    };
}
