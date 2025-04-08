#ifndef SCIFIR_BIOLOGY_GENES_COLLECTION_GENES_COLLECTION_DATA_SOURCE_HPP_INCLUDED
#define SCIFIR_BIOLOGY_GENES_COLLECTION_GENES_COLLECTION_DATA_SOURCE_HPP_INCLUDED

#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class genes_collection_data_source
	{
		public:
			genes_collection_data_source();

			virtual string get_dna_sequence(const string& genome_section,const string& dna_sequence_name) const = 0;
			virtual string get_gene_sequence(const string& genome_section,const string& gene_name) const = 0;
			virtual string get_noncoding_sequence(const string& genome_section,const string& noncoding_sequence_name) const = 0;

			virtual vector<string> get_dna_sequences_from_genome_section(const string& genome_section) const = 0;
			virtual vector<string> get_dna_sequences_from_genome() const = 0;
			virtual vector<string> get_genes_from_genome_section(const string& genome_section) const = 0;
			virtual vector<string> get_genes_from_genome(const string&) const = 0;
			virtual vector<string> get_noncoding_sequences_from_genome_section(const string& genome_section) const = 0;
			virtual vector<string> get_noncoding_sequences_from_genome() const = 0;

			virtual vector<string> get_genome_sections_from_species(const string& species) const = 0;

			virtual vector<string> get_all_species() const = 0;
			virtual vector<string> get_species_from_domain(const string& domain) const = 0;
			virtual vector<string> get_species_from_kingdom(const string& kingdom) const = 0;
			virtual vector<string> get_species_from_phylum(const string& phylum) const = 0;
			virtual vector<string> get_species_from_class(const string& species_class) const = 0;
			virtual vector<string> get_species_from_order(const string& order) const = 0;
			virtual vector<string> get_species_from_family(const string& family) const = 0;
			virtual vector<string> get_species_from_genus(const string& genus) const = 0;
	};
}

#endif // SCIFIR_BIOLOGY_GENES_COLLECTION_GENES_COLLECTION_DATA_SOURCE_HPP_INCLUDED
