#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

#include "../../dna/dna_sequence.hpp"

using namespace std;

TEST_CASE("class dna_sequence","Complete test of dna_sequence class")
{
	SECTION("Initialization of dna_sequence classes")
	{
		scifir::dna_sequence a;
		CHECK(bool(a.get_sequence() == ""));
		scifir::dna_sequence b = scifir::dna_sequence("try_gene","TCGA");
		CHECK(bool(b.get_sequence() == "TCGA"));
		scifir::dna_sequence c = scifir::dna_sequence("try_gene2","TCRGAY");
		CHECK(bool(c.get_sequence() == "TC0GA0"));
	}
}
