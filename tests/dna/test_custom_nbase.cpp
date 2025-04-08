#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

#include "../../dna/extended_nbase.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class custom_nbase","Complete test of custom_nbase class")
{
	SECTION("Initialization of custom_nbase classes")
	{
		extended_nbase a;
		REQUIRE(bool(a.display() == "0"));
		extended_nbase b = extended_nbase('D');
		extended_nbase b2 = extended_nbase(b);
		REQUIRE(bool(b2.display() == "D"));
		extended_nbase c = extended_nbase(extended_nbase('Y'));
		REQUIRE(bool(c.display() == "Y"));
		extended_nbase d = extended_nbase(nbase::A);
		REQUIRE(bool(d.display() == "A"));
		extended_nbase e = extended_nbase('H');
		REQUIRE(bool(e.display() == "H"));
	}

	SECTION("Assignment operators of custom_nbase classes")
	{
		extended_nbase a = extended_nbase(nbase::G);
		extended_nbase a2 = extended_nbase('K');
		a = a2;
		REQUIRE(bool(a.display() == "K"));
		extended_nbase b = extended_nbase(nbase::G);
		b = extended_nbase('P');
		REQUIRE(bool(b.display() == "P"));
		extended_nbase c = extended_nbase('R');
		c = nbase::A;
		REQUIRE(bool(c.display() == "A"));
		extended_nbase d = extended_nbase('W');
		d = 'Q';
		REQUIRE(bool(d.display() == "Q"));
	}
}

