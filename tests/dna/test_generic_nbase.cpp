#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

#include "../../dna/nbase.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class nbase","Complete test of nbase class")
{
	SECTION("Initialization of nbase classes")
	{
		nbase a;
		CHECK(bool(to_string(a) == "0"));
		/*nbase b = nbase('C');
		nbase b2 = nbase(b);
		CHECK(bool(to_string(b2) == "C"));
		nbase c = nbase(nbase('T'));
		CHECK(bool(to_string(c) == "T"));
		nbase d = nbase(nbase::A);
		CHECK(bool(to_string(d) == "A"));
		nbase e = nbase('C');
		CHECK(bool(to_string(e) == "C"));*/
	}

	/*SECTION("Assignment operators of nbase classes")
	{
		nbase a = nbase(nbase::G);
		nbase a2 = nbase(nbase::T);
		a = a2;
		CHECK(bool(to_string(a) == "T"));
		nbase b = nbase(nbase::G);
		b = nbase(nbase::C);
		CHECK(bool(to_string(b) == "C"));
		nbase c = nbase('A');
		c = nbase::A;
		CHECK(bool(to_string(c) == "A"));
		nbase d = nbase('T');
		d = 'C';
		CHECK(bool(to_string(d) == "C"));
	}*/
}
