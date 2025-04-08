#include "./chromosome.hpp"
#include "./genome.hpp"
#include "./gene.hpp"

using namespace std;

namespace scifir
{
	chromosome::chromosome()
	{}

	chromosome::chromosome(const string& new_name,genome* new_genome) : genes(),genome_molecule(new_genome),name(new_name)
	{}

    chromosome::chromosome(const map<string,shared_ptr<gene>>& new_genes) : genes(new_genes)
    {}

    bool chromosome::is_gene_loaded(const string& x) const
    {
    	return (genes.count(x) > 0);
    }

    void chromosome::load_gene(const string& new_gen)
    {
    	if (!is_gene_loaded(new_gen))
    	{
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
    }

    shared_ptr<gene>& chromosome::operator[](const string& x)
    {
    	if (!is_gene_loaded(x))
		{
			load_gene(x);
		}
		return genes.at(x);
    }

	const shared_ptr<gene>& chromosome::operator[](const string& x) const
	{
		if (!is_gene_loaded(x))
		{
			//load_gene(x);
		}
		return genes.at(x);
	}

    void chromosome::switch_gene(const string& x,shared_ptr<gene> new_gene)
	{
		genes[x] = new_gene;
	}

	void chromosome::insert_gene(const string& x,shared_ptr<gene> new_gene)
	{
		//genes.insert(x - 1,new_gene);
	}

	void chromosome::insert_genes(const string& x,map<string,shared_ptr<gene>> new_genes)
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
			if (x_gene.second->name == gene_name)
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
			if (x_gene.second->get_sequence() == gene_sequence)
			{
				return true;
			}
		}
		return false;
	}
}
