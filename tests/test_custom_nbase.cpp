#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "biology.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class custom_nbase","Complete test of custom_nbase class")
{
	SECTION("Initialization of custom_nbase classes")
	{
		custom_nbase a;
		REQUIRE(bool(a.display() == "0"));
		custom_nbase b = custom_nbase('D');
		custom_nbase b2 = custom_nbase(b);
		REQUIRE(bool(b2.display() == "D"));
		custom_nbase c = custom_nbase(custom_nbase('Y'));
		REQUIRE(bool(c.display() == "Y"));
		custom_nbase d = custom_nbase(generic_nbase::A);
		REQUIRE(bool(d.display() == "A"));
		custom_nbase e = custom_nbase('H');
		REQUIRE(bool(e.display() == "H"));
	}

	SECTION("Assignment operators of custom_nbase classes")
	{
		custom_nbase a = custom_nbase(generic_nbase::G);
		custom_nbase a2 = custom_nbase('K');
		a = a2;
		REQUIRE(bool(a.display() == "K"));
		custom_nbase b = custom_nbase(generic_nbase::G);
		b = custom_nbase('P');
		REQUIRE(bool(b.display() == "P"));
		custom_nbase c = custom_nbase('R');
		c = generic_nbase::A;
		REQUIRE(bool(c.display() == "A"));
		custom_nbase d = custom_nbase('W');
		d = 'Q';
		REQUIRE(bool(d.display() == "Q"));
	}
}

