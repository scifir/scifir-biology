#ifndef SCIFIR_BIOLOGY_GENES_COLLECTION_GENE_INFO_COLLECTION_HPP_INCLUDED
#define SCIFIR_BIOLOGY_GENES_COLLECTION_GENE_INFO_COLLECTION_HPP_INCLUDED

#include <memory>
#include <string>
#include <vector>

#include "./gene_info_collection_data_source.hpp"

using namespace std;

namespace scifir
{
	class gene_info_collection
	{
		public:
			gene_info_collection();
			explicit gene_info_collection(const vector<shared_ptr<gene_info_collection_data_source>>& new_data_sources);

			string get_description(const string& gene_name) const;
			string get_chromosome_name(const string& gene_name) const;
			string get_species(const string& gene_name) const;
			string get_category(const string& gene_name) const;
			vector<string> get_alleles(const string& gene_name) const;

			vector<shared_ptr<gene_info_collection_data_source>> data_sources;
	};
}

#endif // SCIFIR_BIOLOGY_GENES_COLLECTION_GENE_INFO_COLLECTION_HPP_INCLUDED
