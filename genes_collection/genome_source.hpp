#ifndef SCIFIR_BIOLOGY_GENES_COLLECTION_GENOME_SOURCE_HPP_INCLUDED
#define SCIFIR_BIOLOGY_GENES_COLLECTION_GENOME_SOURCE_HPP_INCLUDED

#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class genome_source
	{
		public:
			genome_source();

			virtual string get_dna_sequence(const string&,const string&) const = 0;
			virtual string get_gene_sequence(const string&,const string&) const = 0;
			virtual string get_noncoding_sequence(const string&,const string&) const = 0;

			virtual vector<string> get_dna_sequences_from_chromosome(const string&) const = 0;
			virtual vector<string> get_dna_sequences_from_genome() const = 0;
			virtual vector<string> get_genes_from_chromosome(const string&) const = 0;
			virtual vector<string> get_genes_from_genome() const = 0;
			virtual vector<string> get_noncoding_sequences_from_chromosome(const string&) const = 0;
			virtual vector<string> get_noncoding_sequences_from_genome() const = 0;

			virtual vector<string> get_genome_sections() const = 0;
	};
}

#endif // SCIFIR_BIOLOGY_GENES_COLLECTION_GENOME_SOURCE_HPP_INCLUDED
