#include "genome_section.hpp"
#include "genome.hpp"
#include "generic_gene.hpp"

using namespace std;

namespace scifir
{
	genome_section::genome_section()
	{}

	genome_section::genome_section(const string& new_name,genome* new_genome,rapidxml::xml_node<>* new_chromosome_node) : genes(),genome_molecule(new_genome),chromosome_node(new_chromosome_node),name(new_name)
	{}

    genome_section::genome_section(const map<string,shared_ptr<gene>>& new_genes) : genes(new_genes)
    {}

    bool genome_section::is_gene_loaded(const string& x) const
    {
    	return (genes.count(x) > 0);
    }

    void genome_section::load_gene(const string& new_gen)
    {
    	if (!is_gene_loaded(new_gen))
    	{
			for (rapidxml::xml_node<>* gene_node = chromosome_node->first_node("gene"); gene_node; gene_node = gene_node->next_sibling())
			{
				string gene_name = gene_node->first_attribute("name")->value();
				if (new_gen == gene_name)
				{
					string gene_bases = gene_node->value();
					shared_ptr<gene> new_gene = make_shared<generic_gene>(gene_name,gene_bases);
					genes[gene_name] = new_gene;
				}
			}
    	}
    }

    void genome_section::load_genes(const vector<string>& new_genes)
    {
		vector<string> loadable_genes;
		for (const string& new_gene : new_genes)
		{
			if (!is_gene_loaded(new_gene))
			{
				loadable_genes.push_back(new_gene);
			}
		}
		for (rapidxml::xml_node<>* gene_node = chromosome_node->first_node("gene"); gene_node; gene_node = gene_node->next_sibling())
		{
			for (const string& loadable_gene : loadable_genes)
			{
				string gene_name = gene_node->first_attribute("name")->value();
				if (loadable_gene == gene_name)
				{
					string gene_bases = gene_node->value();
					shared_ptr<gene> new_gene = make_shared<generic_gene>(gene_name,gene_bases);
					genes[gene_name] = new_gene;
				}
			}
		}
    }

    shared_ptr<gene>& genome_section::operator[](const string& x)
    {
    	if (!is_gene_loaded(x))
		{
			load_gene(x);
		}
		return genes.at(x);
    }

	const shared_ptr<gene>& genome_section::operator[](const string& x) const
	{
		if (!is_gene_loaded(x))
		{
			//load_gene(x);
		}
		return genes.at(x);
	}

    void genome_section::switch_gene(const string& x,shared_ptr<gene> new_gene)
	{
		genes[x] = new_gene;
	}

	void genome_section::insert_gene(const string& x,shared_ptr<gene> new_gene)
	{
		//genes.insert(x - 1,new_gene);
	}

	void genome_section::insert_genes(const string& x,map<string,shared_ptr<gene>> new_genes)
	{
		//genes.insert(x - 1,new_genes,new_genes.size());
	}

	void genome_section::remove_gene(const string& x)
	{
		//genes.erase(x - 1);
	}

	bool genome_section::has_gene(const string& gene_name) const
	{
		for (const auto& x_gene : genes)
		{
			if (x_gene.second->name == gene_name)
			{
				return true;
			}
		}
		return false;
	}

	bool genome_section::has_gene_sequence(const string& gene_sequence) const
	{
		for (const auto& x_gene : genes)
		{
			if (x_gene.second->get_sequence() == gene_sequence)
			{
				return true;
			}
		}
		return false;
	}
}
