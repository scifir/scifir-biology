#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "biology.hpp"

using namespace std;

TEST_CASE("class generic_gene","Complete test of generic_gene class")
{
	SECTION("Initialization of generic_gene classes")
	{
		scifir::generic_gene a;
		REQUIRE(bool(a.get_sequence() == ""));
		scifir::generic_gene b = scifir::generic_gene("try_gene","TCGA");
		REQUIRE(bool(b.get_sequence() == "TCGA"));
		scifir::generic_gene c = scifir::generic_gene("try_gene2","TCRGAY");
		REQUIRE(bool(c.get_sequence() == "TC0GA0"));
	}
}
