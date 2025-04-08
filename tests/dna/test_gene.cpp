#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

#include "../../dna/gene.hpp"

using namespace std;

TEST_CASE("class gene","Complete test of gene class")
{
	SECTION("Initialization of gene classes")
	{
		scifir::gene a;
		CHECK(bool(a.get_sequence() == ""));
		scifir::gene b = scifir::gene("try_gene","TCGA");
		CHECK(bool(b.get_sequence() == "TCGA"));
		scifir::gene c = scifir::gene("try_gene2","TCRGAY");
		CHECK(bool(c.get_sequence() == "TC0GA0"));
	}
}
