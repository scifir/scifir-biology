#include "./genes_collection.hpp"

using namespace std;

namespace scifir
{
	genes_collection::genes_collection() : sources(),chromosomes(),chromosomes_order(),type(),file_name()
	{}

	const vector<nbase>& genes_collection::get_gene_sequence(const string& chromosome_name,const string& gene_name) const
	{
		return vector<nbase>();
		//return chromosomes[chromosome_name][gene_name]->get_bases();
	}

	const vector<unique_ptr<genes_collection_data_source>>& genes_collection::get_sources() const
	{
		return sources;
	}

	map<string,genes_collection> all_genomes = map<string,genes_collection>();
}
