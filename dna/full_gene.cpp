#include "msci/genetics/dna/full_gene.hpp"

using namespace std;

namespace msci
{
	full_gene::full_gene() : gene(),bases()
	{
	}

	full_gene::full_gene(const string& new_name,chromosome* new_chromosome,const string& new_bases) : gene(new_name,new_chromosome),bases()
	{
		for (int i = 0; i < new_bases.size(); i++)
		{
			nbase new_base = create_nbase(new_bases[i]);
			bases.push_back(new_base);
		}
	}

	void full_gene::switch_base(int i,char x)
	{
		nbase new_base = create_nbase(x);
		bases[i] = new_base;
	}

	void full_gene::insert_base(int i,char x)
	{
		nbase new_base = create_nbase(x);
		bases.insert(bases.begin() + i,new_base);
	}

	void full_gene::remove_base(int i)
	{
		bases.erase(bases.begin() + i);
	}

	const vector<nbase>& full_gene::get_bases() const
	{
		return bases;
	}
}
