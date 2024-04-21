#ifndef SCIFIR_BIOLOGY_GENES_COLLECTION_GENES_COLLECTION_GENOME_SECTION_HPP_INCLUDED
#define SCIFIR_BIOLOGY_GENES_COLLECTION_GENES_COLLECTION_GENOME_SECTION_HPP_INCLUDED

#include "dna/dna_sequence.hpp"

#include "genes_collection_genome.hpp"
#include "genes_collection_source.hpp"

#include <map>
#include <memory>
#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class genes_collection_genome_section
	{
		public:
			genes_collection_genome_section();
			genes_collection_genome_section(const genes_collection_genome_section&);
			genes_collection_genome_section(genes_collection_genome_section&&);
			explicit genes_collection_genome_section(const genes_collection_genome*,const string&);

			genes_collection_genome_section& operator =(const genes_collection_genome_section&);
			genes_collection_genome_section& operator =(genes_collection_genome_section&&);

			const vector<unique_ptr<genes_collection_source>>& get_sources() const;

			void load_gene(const string&) const;
			void load_noncoding_sequence(const string&) const;

		private:
			mutable map<string,shared_ptr<dna_sequence>> dna_sequences;
			shared_ptr<genes_collection_genome> parent_gene_genome;
			string genome_section_name;
	};
}

#endif // SCIFIR_BIOLOGY_GENES_COLLECTION_GENES_COLLECTION_GENOME_SECTION_HPP_INCLUDED
