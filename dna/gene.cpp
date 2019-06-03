#include "msci/genetics/dna/gene.hpp"
#include "msci/genetics/dna/chromosome.hpp"
#include "msci/genetics/dna/genome.hpp"

#include <cmath>

using namespace std;

namespace msci
{
	gene::gene() : name(),chromosome_molecule()
	{
	}

	gene::gene(const string& new_name,chromosome* new_chromosome) : name(new_name),chromosome_molecule(new_chromosome)
	{
	}

	const vector<nbase>& gene::get_bases() const
	{
		return all_genomes[chromosome_molecule->get_dna()->get_species()].get_gene_sequence(chromosome_molecule->get_name(),name);
	}

	/*molecule gene::operator[](int x) const
	{

	}*/

	bool gene::is_valid() const
	{
		return true;
		//return ((bases.size() / 3) == floor(bases.size() / 3));
	}
}
