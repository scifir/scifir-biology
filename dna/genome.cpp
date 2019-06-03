#include "msci/genetics/dna/genome.hpp"

using namespace std;

namespace msci
{
	genome::genome() : chromosomes(),chromosomes_order(),type(),file_name(),xml_file()
	{
	}

	const vector<nbase>& genome::get_gene_sequence(const string& chromosome_name,const string& gene_name) const
	{
		return chromosomes[chromosome_name][gene_name].get_bases();
	}

	map<string,genome> all_genomes = map<string,genome>();
}
