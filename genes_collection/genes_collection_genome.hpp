#ifndef SCIFIR_BIOLOGY_GENES_COLLECTION_GENES_COLLECTION_GENOME_HPP_INCLUDED
#define SCIFIR_BIOLOGY_GENES_COLLECTION_GENES_COLLECTION_GENOME_HPP_INCLUDED

#include "../dna/chromosome.hpp"

#include "./genes_collection_data_source.hpp"

#include <map>
#include <memory>
#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class genes_collection;
	class genes_collection_genome_section;

	class genes_collection_genome
	{
		public:
			genes_collection_genome();

			const map<string,genes_collection_genome_section>& get_genome_sections() const;
			string get_species() const;
			const shared_ptr<genes_collection>& get_parent_gene_collection() const;

			const genes_collection_genome_section& operator [](const string&) const;

			const vector<unique_ptr<genes_collection_data_source>>& get_sources() const;

			void load_dna_sequence(const string& genome_section,const string& dna_sequence_name) const;
			void load_gene(const string& genome_section,const string& gene_name) const;
			void load_noncoding_sequence(const string& genome_section,const string& noncoding_sequence_name) const;

			void load_dna_sequences_from_genome_section(const string& genome_section) const;
			void load_dna_sequences_from_genome() const;
			void load_genes_from_genome_section(const string& genome_section) const;
			void load_genes_from_genome(const string&) const;
			void load_noncoding_sequences_from_genome_section(const string& genome_section) const;
			void load_noncoding_sequences_from_genome() const;

			void load_genome_sections() const;

		private:
			mutable map<string,genes_collection_genome_section> genome_sections;
			string species;
			shared_ptr<genes_collection> parent_gene_collection;
	};
}

#endif // SCIFIR_BIOLOGY_GENES_COLLECTION_GENES_COLLECTION_GENOME_HPP_INCLUDED
