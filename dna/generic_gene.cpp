#include "generic_gene.hpp"

#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

namespace scifir
{
	generic_gene::generic_gene() : gene(),bases()
	{}

	generic_gene::generic_gene(const string& new_name,const string& new_sequence) : gene(new_name),bases()
	{
		for (int i = 0; i < new_sequence.size(); i++)
		{
			bases.push_back(generic_nbase(new_sequence[i]));
		}
	}

	string generic_gene::get_base(int index) const
	{
		return get_bases()[index].display();
	}

	void generic_gene::switch_base(int index,char new_base)
	{
		bases[index] = new_base;
	}

	void generic_gene::insert_base(int index,char new_base)
	{
		bases.insert(bases.begin() + index,generic_nbase(new_base));
	}

	void generic_gene::remove_base(int index)
	{
		bases.erase(bases.begin() + index);
	}

	string generic_gene::get_sequence() const
	{
		ostringstream out;
		for (const generic_nbase& x_base : bases)
		{
			out << x_base;
		}
		return out.str();
	}

	void generic_gene::switch_sequence(int index,const string& new_sequence)
	{
		int total = index + new_sequence.length();
		for (int i = index; i < total; i++)
		{
			bases[i] = new_sequence[i];
		}
	}

	void generic_gene::insert_sequence(int index,const string& new_sequence)
	{
		vector<generic_nbase> new_bases = vector<generic_nbase>();
		for (int i = 0; i < new_sequence.length(); i++)
		{
			new_bases.push_back(generic_nbase(new_sequence[i]));
		}
		bases.insert(bases.begin() + index,new_bases.begin(),new_bases.end());
	}

	void generic_gene::set_sequence(const string& new_sequence)
	{
		bases.clear();
		for (int i = 0; i < new_sequence.size(); i++)
		{
			bases.push_back(generic_nbase(new_sequence[i]));
		}
	}

	void generic_gene::remove_sequence(int index,int total)
	{
		bases.erase(bases.begin() + index,bases.begin() + index + total);
	}

	int generic_gene::number_of_bases() const
	{
		return bases.size();
	}

	int generic_gene::number_of_codons() const
	{
		return floor(bases.size() / 3);
	}

	bool generic_gene::is_valid() const
	{
		if (!(bases[0].base == generic_nbase::T and bases[1].base == generic_nbase::A and bases[2].base == generic_nbase::C))
		{
			return false;
		}
		int total = bases.size();
		if (!(bases[total - 3].base == generic_nbase::A and bases[total - 2].base == generic_nbase::T and bases[total - 1].base == generic_nbase::T) and !(bases[total - 3].base == generic_nbase::A and bases[total - 2].base == generic_nbase::T and bases[total - 1].base == generic_nbase::C) and !(bases[total - 3].base == generic_nbase::A and bases[total - 2].base == generic_nbase::C and bases[total - 1].base == generic_nbase::T))
		{
			return false;
		}
		return ((bases.size() / 3) == floor(bases.size() / 3));
	}

	//protein generic_gene::get_protein() const

	string generic_gene::get_aminoacid_sequence() const
	{
		return "";
	}

	rna generic_gene::get_mrna() const
	{
		return rna();
	}

	const vector<generic_nbase>& generic_gene::get_bases() const
	{
		return bases;
		//return all_genomes[chromosome_molecule->get_dna()->get_species()].get_gene_sequence(chromosome_molecule->get_name(),name);
	}
}
