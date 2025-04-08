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
		nbase b = nbase('C');
		nbase b2 = nbase(b);
		CHECK(bool(to_string(b2) == "C"));
		nbase c = nbase(nbase('T'));
		CHECK(bool(to_string(c) == "T"));
		nbase d = nbase(nbase::A);
		CHECK(bool(to_string(d) == "A"));
		nbase e = nbase('C');
		CHECK(bool(to_string(e) == "C"));
	}

	SECTION("Assignment operators of nbase classes")
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
	}

	SECTION("to_string() function of nbase class and nbase::type enum")
	{
		CHECK(to_string(nbase::A) == "A");
		CHECK(to_string(nbase::G) == "G");
		CHECK(to_string(nbase::T) == "T");
		CHECK(to_string(nbase::C) == "C");
		CHECK(to_string(nbase::U) == "U");
		CHECK(to_string(nbase::NONE) == "0");
		CHECK(to_string(nbase::CUSTOM) == "X");
		CHECK(to_string(nbase(nbase::A)) == "A");
	}

	SECTION("Functions that map nbase to other nbase based on some logic of biology")
	{
		CHECK((to_complementary_nbase(nbase::A) == nbase::T));
		CHECK((to_complementary_nbase(nbase::T) == nbase::A));
		CHECK((to_complementary_nbase(nbase::C) == nbase::G));
		CHECK((to_complementary_nbase(nbase::G) == nbase::C));
		CHECK((to_complementary_nbase(nbase::U) == nbase::NONE));
		CHECK((to_complementary_nbase(nbase(nbase::A)) == nbase(nbase::T)));
		CHECK((to_complementary_nbase(nbase(nbase::T)) == nbase(nbase::A)));
		CHECK((to_complementary_nbase(nbase(nbase::C)) == nbase(nbase::G)));
		CHECK((to_complementary_nbase(nbase(nbase::G)) == nbase(nbase::C)));
		CHECK((to_complementary_nbase(nbase(nbase::U)) == nbase()));

		CHECK((to_dna_nbase(nbase::A) == nbase::T));
		CHECK((to_dna_nbase(nbase::U) == nbase::A));
		CHECK((to_dna_nbase(nbase::C) == nbase::G));
		CHECK((to_dna_nbase(nbase::G) == nbase::C));
		CHECK((to_dna_nbase(nbase::T) == nbase::NONE));
		CHECK((to_dna_nbase(nbase(nbase::A)) == nbase(nbase::T)));
		CHECK((to_dna_nbase(nbase(nbase::U)) == nbase(nbase::A)));
		CHECK((to_dna_nbase(nbase(nbase::C)) == nbase(nbase::G)));
		CHECK((to_dna_nbase(nbase(nbase::G)) == nbase(nbase::C)));
		CHECK((to_dna_nbase(nbase(nbase::T)) == nbase()));

		CHECK((to_rna_nbase(nbase::A) == nbase::U));
		CHECK((to_rna_nbase(nbase::T) == nbase::A));
		CHECK((to_rna_nbase(nbase::C) == nbase::G));
		CHECK((to_rna_nbase(nbase::G) == nbase::C));
		CHECK((to_rna_nbase(nbase::U) == nbase::NONE));
		CHECK((to_rna_nbase(nbase(nbase::A)) == nbase(nbase::U)));
		CHECK((to_rna_nbase(nbase(nbase::T)) == nbase(nbase::A)));
		CHECK((to_rna_nbase(nbase(nbase::C)) == nbase(nbase::G)));
		CHECK((to_rna_nbase(nbase(nbase::G)) == nbase(nbase::C)));
		CHECK((to_rna_nbase(nbase(nbase::U)) == nbase()));
	}

	SECTION("Operators of nbase class with strings")
	{
		CHECK(bool((nbase(nbase::A) + " nbase") == "A nbase"));
		CHECK(bool(("nbase " + nbase(nbase::A)) == "nbase A"));
		string a = "nbase ";
		a += nbase(nbase::A);
		CHECK(bool(a == "nbase A"));
	}

	SECTION("Operators of nbase class with other nbase class")
	{
		CHECK(bool(nbase(nbase::A) == nbase(nbase::A)));
		CHECK(bool((nbase(nbase::A) == nbase(nbase::G)) == false));
		CHECK(bool((nbase(nbase::A) != nbase(nbase::A)) == false));
		CHECK(bool(nbase(nbase::A) != nbase(nbase::G)));
	}

	SECTION("Stream operators of nbase class")
    {
        ostringstream a;
        a << nbase(nbase::T);
        CHECK(a.str() == "T");
        stringstream b;
        b << "A";
        nbase b2;
        b >> b2;
        CHECK(b2.base == nbase::A);
    }
}
