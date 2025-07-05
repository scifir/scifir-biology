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
		return int(floor(int(bases.size()) / 3));
	}

	bool gene::is_valid() const
	{
		if (!(bases[0].base == nbase::T and bases[1].base == nbase::A and bases[2].base == nbase::C))
		{
			return false;
		}
		int total = int(bases.size());
		if (!(bases[total - 3].base == nbase::A and bases[total - 2].base == nbase::T and bases[total - 1].base == nbase::T) and !(bases[total - 3].base == nbase::A and bases[total - 2].base == nbase::T and bases[total - 1].base == nbase::C) and !(bases[total - 3].base == nbase::A and bases[total - 2].base == nbase::C and bases[total - 1].base == nbase::T))
		{
			return false;
		}
		return ((bases.size() / 3) == floor(bases.size() / 3));
	}

	protein gene::get_protein() const
	{
		rna mrna = get_mrna();
		vector<aminoacid> new_aminoacids = vector<aminoacid>();
		if (is_valid() and (mrna.bases[0] == nbase::A and mrna.bases[1] == nbase::U and mrna.bases[2] == nbase::G) or (mrna.bases[0] == nbase::U and mrna.bases[1] == nbase::U and mrna.bases[2] == nbase::G) or (mrna.bases[0] == nbase::G and mrna.bases[1] == nbase::U and mrna.bases[2] == nbase::G))
		{
			for (int i = 3; mrna.bases.size(); i += 3)
			{
				if ((mrna.bases[i] == nbase::U and mrna.bases[i + 1] == nbase::A and mrna.bases[i + 2] == nbase::A) or (mrna.bases[i] == nbase::U and mrna.bases[i + 1] == nbase::A and mrna.bases[i + 2] == nbase::G) or (mrna.bases[i] == nbase::U and mrna.bases[i + 1] == nbase::G and mrna.bases[i + 2] == nbase::A))
				{
					break;
				}
				else
				{
					new_aminoacids.push_back(mrna_to_aminoacid(mrna.bases[i],mrna.bases[i + 1],mrna.bases[i + 2]));
				}
			}
		}
		return protein("",new_aminoacids);
	}

	string gene::get_aminoacid_sequence() const
	{
		rna mrna = get_mrna();
		vector<aminoacid> new_aminoacids = vector<aminoacid>();
		if (is_valid() and (mrna.bases[0] == nbase::A and mrna.bases[1] == nbase::U and mrna.bases[2] == nbase::G) or (mrna.bases[0] == nbase::U and mrna.bases[1] == nbase::U and mrna.bases[2] == nbase::G) or (mrna.bases[0] == nbase::G and mrna.bases[1] == nbase::U and mrna.bases[2] == nbase::G))
		{
			ostringstream out;
			for (int i = 3; mrna.bases.size(); i += 3)
			{
				if ((mrna.bases[i] == nbase::U and mrna.bases[i + 1] == nbase::A and mrna.bases[i + 2] == nbase::A) or (mrna.bases[i] == nbase::U and mrna.bases[i + 1] == nbase::A and mrna.bases[i + 2] == nbase::G) or (mrna.bases[i] == nbase::U and mrna.bases[i + 1] == nbase::G and mrna.bases[i + 2] == nbase::A))
				{
					break;
				}
				else
				{
					out << mrna_to_aminoacid(mrna.bases[i],mrna.bases[i + 1],mrna.bases[i + 2]).get_abbreviation();
				}
			}
			return out.str();
		}
		else
		{
			return "";
		}
	}

	rna gene::get_mrna() const
	{
		vector<nbase> new_bases;
		for (const nbase& x_base : bases)
		{
			new_bases.push_back(to_rna_nbase(x_base));
		}
		return rna(new_bases);
	}	
}

ostream& operator <<(ostream& os,const scifir::gene& x)
{
	return os << x.name;
}
