#include "./gene.hpp"

#include <cmath>

using namespace std;

namespace scifir
{
	gene::gene() : dna_sequence()
	{}

	gene::gene(const string& new_name,const string& new_sequence) : dna_sequence(new_name,new_sequence)
	{}

	dna_sequence::type gene::get_type() const
	{
		return dna_sequence::GENE;
	}

	int gene::number_of_codons() const
	{
		return floor(bases.size() / 3);
	}

	bool gene::is_valid() const
	{
		if (!(bases[0].base == nbase::T and bases[1].base == nbase::A and bases[2].base == nbase::C))
		{
			return false;
		}
		int total = bases.size();
		if (!(bases[total - 3].base == nbase::A and bases[total - 2].base == nbase::T and bases[total - 1].base == nbase::T) and !(bases[total - 3].base == nbase::A and bases[total - 2].base == nbase::T and bases[total - 1].base == nbase::C) and !(bases[total - 3].base == nbase::A and bases[total - 2].base == nbase::C and bases[total - 1].base == nbase::T))
		{
			return false;
		}
		return ((bases.size() / 3) == floor(bases.size() / 3));
	}

	//protein gene::get_protein() const

	string gene::get_aminoacid_sequence() const
	{
		return "";
	}

	rna gene::get_mrna() const
	{
		return rna();
	}	
}

ostream& operator <<(ostream& os,const scifir::gene& x)
{
	return os << x.name;
}
