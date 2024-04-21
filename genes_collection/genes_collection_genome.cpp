#include "genes_collection_genome.hpp"

#include "genes_collection.hpp"
#include "genes_collection_genome_section.hpp"

using namespace std;

namespace scifir
{
	genes_collection_genome::genes_collection_genome() : genome_sections(),species(),parent_gene_collection()
	{}

	const map<string,genes_collection_genome_section>& genes_collection_genome::get_genome_sections() const
	{
		return genome_sections;
	}

	string genes_collection_genome::get_species() const
	{
		return species;
	}

	const shared_ptr<genes_collection>& genes_collection_genome::get_parent_gene_collection() const
	{
		return parent_gene_collection;
	}

	const genes_collection_genome_section& genes_collection_genome::operator [](const string& genome_section_name) const
	{
		return genome_sections[genome_section_name];
	}

	const vector<unique_ptr<genes_collection_source>>& genes_collection_genome::get_sources() const
	{
		return parent_gene_collection->get_sources();
	}

	void genes_collection_genome::load_dna_sequence(const string& genome_section,const string& dna_sequence_name) const
	{}

	void genes_collection_genome::load_gene(const string& genome_section,const string& gene_name) const
	{
		genome_sections[genome_section].load_gene(gene_name);
	}

	void genes_collection_genome::load_noncoding_sequence(const string& genome_section,const string& noncoding_sequence_name) const
	{
		genome_sections[genome_section].load_noncoding_sequence(noncoding_sequence_name);
	}

	void genes_collection_genome::load_genome_sections() const
	{
		const vector<unique_ptr<genes_collection_source>>& sources = get_sources();
		for (int i = 0; i < sources.size(); i++)
		{
			vector<string> new_genome_sections = sources[i]->get_genome_sections_from_species(species);
			if (new_genome_sections.size() > 0)
			{
				for (const string& new_genome_section : new_genome_sections)
				{
					genome_sections[new_genome_section] = genes_collection_genome_section(this,new_genome_section);
				}
				break;
			}
		}
	}
}
