#include "genes_collection_genome_section.hpp"

#include "dna/generic_gene.hpp"
#include "dna/generic_noncoding_sequence.hpp"
#include "genes_collection.hpp"

using namespace std;

namespace scifir
{
	genes_collection_genome_section::genes_collection_genome_section() : dna_sequences(),parent_gene_genome(),genome_section_name()
	{}

	genes_collection_genome_section::genes_collection_genome_section(const genes_collection_genome_section& x) : dna_sequences(x.dna_sequences),parent_gene_genome(x.parent_gene_genome),genome_section_name(x.genome_section_name)
	{}

	genes_collection_genome_section::genes_collection_genome_section(genes_collection_genome_section&& x) : dna_sequences(move(x.dna_sequences)),parent_gene_genome(move(x.parent_gene_genome)),genome_section_name(move(x.genome_section_name))
	{}

	genes_collection_genome_section::genes_collection_genome_section(const genes_collection_genome* new_parent_gene_genome,const string& new_genome_section_name) : dna_sequences(),parent_gene_genome(make_shared<genes_collection_genome>(*new_parent_gene_genome)),genome_section_name(new_genome_section_name)
	{}

	genes_collection_genome_section& genes_collection_genome_section::operator =(const genes_collection_genome_section& x)
	{
		dna_sequences = x.dna_sequences;
		parent_gene_genome = x.parent_gene_genome;
		genome_section_name = x.genome_section_name;
		return *this;
	}

	genes_collection_genome_section& genes_collection_genome_section::operator =(genes_collection_genome_section&& x)
	{
		dna_sequences = move(x.dna_sequences);
		parent_gene_genome = move(x.parent_gene_genome);
		genome_section_name = move(x.genome_section_name);
		return *this;
	}

	const vector<unique_ptr<genes_collection_source>>& genes_collection_genome_section::get_sources() const
	{
		return parent_gene_genome->get_parent_gene_collection()->get_sources();
	}

	void genes_collection_genome_section::load_gene(const string& gene_name) const
	{
		const vector<unique_ptr<genes_collection_source>>& sources = get_sources();
		for (int i = 0; i < sources.size(); i++)
		{
			string new_gene_sequence = sources[i]->get_gene_sequence(genome_section_name,gene_name);
			if (new_gene_sequence != "")
			{
				dna_sequences[gene_name] = make_shared<generic_gene>(generic_gene(gene_name,new_gene_sequence));
				break;
			}
		}
	}

	void genes_collection_genome_section::load_noncoding_sequence(const string& noncoding_sequence_name) const
	{
		const vector<unique_ptr<genes_collection_source>>& sources = get_sources();
		for (int i = 0; i < sources.size(); i++)
		{
			string new_gene_sequence = sources[i]->get_noncoding_sequence(genome_section_name,noncoding_sequence_name);
			if (new_gene_sequence != "")
			{
				dna_sequences[noncoding_sequence_name] = make_shared<generic_noncoding_sequence>(generic_noncoding_sequence(noncoding_sequence_name,new_gene_sequence));
				break;
			}
		}
	}
}
