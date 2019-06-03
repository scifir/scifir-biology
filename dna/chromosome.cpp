#include "msci/genetics/dna/chromosome.hpp"
#include "msci/genetics/dna/dna.hpp"
#include "msci/genetics/dna/full_gene.hpp"

using namespace std;

namespace msci
{
	chromosome::chromosome()
	{
	}

	chromosome::chromosome(const string& new_name,dna* new_dna,rapidxml::xml_node<>* new_chromosome_node) : genes(),dna_molecule(new_dna),chromosome_node(new_chromosome_node),name(new_name)
	{
	}

    chromosome::chromosome(map<string,gene> new_genes) : genes(new_genes)
    {
    }

    bool chromosome::is_gene_loaded(const string& x) const
    {
    	return (genes.count(x) > 0);
    }

    void chromosome::load_gene(const string& new_gen)
    {
    	if (!is_gene_loaded(new_gen))
    	{
			for (rapidxml::xml_node<>* gene_node = chromosome_node->first_node("gene"); gene_node; gene_node = gene_node->next_sibling())
			{
				string gene_name = gene_node->first_attribute("name")->value();
				if (new_gen == gene_name)
				{
					string gene_bases = gene_node->value();
					full_gene new_gene(gene_name,this,gene_bases);
					genes[gene_name] = new_gene;
				}
			}
    	}
    }

    void chromosome::load_genes(const vector<string>& new_genes)
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
					full_gene new_gene(gene_name,this,gene_bases);
					genes[gene_name] = new_gene;
				}
			}
		}
    }

    gene& chromosome::operator[](const string& x)
    {
    	if (!is_gene_loaded(x))
		{
			load_gene(x);
		}
		return genes.at(x);
    }

	const gene& chromosome::operator[](const string& x) const
	{
		if (!is_gene_loaded(x))
		{
			//load_gene(x);
		}
		return genes.at(x);
	}

    void chromosome::switch_gene(const string& x,gene new_gene)
	{
		genes[x] = new_gene;
	}

	void chromosome::insert_gene(const string& x,gene new_gene)
	{
		//genes.insert(x - 1,new_gene);
	}

	void chromosome::insert_genes(const string& x,map<string,gene> new_genes)
	{
		//genes.insert(x - 1,new_genes,new_genes.size());
	}

	void chromosome::remove_gene(const string& x)
	{
		//genes.erase(x - 1);
	}

	bool chromosome::has_gene(const string& gene_name) const
	{
		for (const auto& x_gene : genes)
		{
			if (x_gene.second.get_name() == gene_name)
			{
				return true;
			}
		}
		return false;
	}

	bool chromosome::has_gene_sequence(const string& gene_sequence) const
	{
		for (const auto& x_gene : genes)
		{
			if (x_gene.second.get_sequence() == gene_sequence)
			{
				return true;
			}
		}
		return false;
	}
}
