#ifndef SCIFIR_BIOLOGY_GENES_COLLECTION_GENE_INFO_COLLECTION_DATA_SOURCE_HPP_INCLUDED
#define SCIFIR_BIOLOGY_GENES_COLLECTION_GENE_INFO_COLLECTION_DATA_SOURCE_HPP_INCLUDED

#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class gene_info_collection_data_source
	{
		public:
			virtual string get_description(const string& gene_name) const = 0;
			virtual string get_chromosome_name(const string& gene_name) const = 0;
			virtual string get_species(const string& gene_name) const = 0;
			virtual string get_category(const string& gene_name) const = 0;
			virtual vector<string> get_alleles(const string& gene_name) const = 0;
	};
}

#endif // SCIFIR_BIOLOGY_GENES_COLLECTION_GENE_INFO_COLLECTION_DATA_SOURCE_HPP_INCLUDED

