#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

#include "../../dna/gene.hpp"

using namespace std;

TEST_CASE("class generic_gene","Complete test of generic_gene class")
{
	SECTION("Initialization of gene classes")
	{
		scifir::gene a;
		REQUIRE(bool(a.get_sequence() == ""));
		scifir::gene b = scifir::gene("try_gene","TCGA");
		REQUIRE(bool(b.get_sequence() == "TCGA"));
		scifir::gene c = scifir::gene("try_gene2","TCRGAY");
		REQUIRE(bool(c.get_sequence() == "TC0GA0"));
	}
}
