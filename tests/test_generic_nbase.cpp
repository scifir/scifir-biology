#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "biology.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class generic_nbase","Complete test of generic_nbase class")
{
	SECTION("Initialization of generic_nbase classes")
	{
		generic_nbase a;
		REQUIRE(bool(a.display() == "0"));
		generic_nbase b = generic_nbase('C');
		generic_nbase b2 = generic_nbase(b);
		REQUIRE(bool(b2.display() == "C"));
		generic_nbase c = generic_nbase(generic_nbase('T'));
		REQUIRE(bool(c.display() == "T"));
		generic_nbase d = generic_nbase(generic_nbase::A);
		REQUIRE(bool(d.display() == "A"));
		generic_nbase e = generic_nbase('C');
		REQUIRE(bool(e.display() == "C"));
	}

	SECTION("Assignment operators of generic_nbase classes")
	{
		generic_nbase a = generic_nbase(generic_nbase::G);
		generic_nbase a2 = generic_nbase(generic_nbase::T);
		a = a2;
		REQUIRE(bool(a.display() == "T"));
		generic_nbase b = generic_nbase(generic_nbase::G);
		b = generic_nbase(generic_nbase::C);
		REQUIRE(bool(b.display() == "C"));
		generic_nbase c = generic_nbase('A');
		c = generic_nbase::A;
		REQUIRE(bool(c.display() == "A"));
		generic_nbase d = generic_nbase('T');
		d = 'C';
		REQUIRE(bool(d.display() == "C"));
	}
}
