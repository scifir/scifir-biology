#include "msci/genetics.hpp"

#include <iostream>

using namespace std;

int main()
{
	cout << "Genetics test" << endl;

	scifir::nbase base_a = nbase(nbase::A);
	scifir::nbase base_g = nbase(nbase::G);
	scifir::nbase base_c = nbase(nbase::C);
	scifir::nbase base_t = nbase(nbase::T);
	scifir::nbase base_u = nbase(nbase::U);

	cout << "base a: " << base_a << endl;
	cout << "base g: " << base_g << endl;
	cout << "base c: " << base_c << endl;
	cout << "base t: " << base_t << endl;
	cout << "base u: " << base_u << endl;

	scifir::generic_gene generic_gene_a = generic_gene("AGCT4","AGCT");

	cout << "gene a: " << generic_gene_a << endl;

	scifir::dna dna_a("dna_example");

	cout << "number of chromosomes: " << dna_a.number_of_chromosomes() << endl;

	cout << "gene sequence: " << dna_a["1"]["AGCTGATC8"]->get_sequence() << endl;
}

