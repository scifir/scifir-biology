#include "./rna.hpp"

#include <sstream>

namespace scifir
{
	rna::rna() : bases()
	{}

	rna::rna(const vector<nbase>& new_bases) : bases(new_bases)
	{}

	rna::rna(const string& new_sequence) : bases()
	{
		for (int i = 0; i < new_sequence.size(); i++)
		{
			bases.push_back(nbase(new_sequence[i]));
		}
	}

	dna_sequence rna::to_dna() const
	{
		vector<nbase> new_bases = vector<nbase>();
		for (const nbase& x_base : bases)
		{
			new_bases.push_back(to_dna_nbase(x_base));
		}
		return dna_sequence("from_rna",new_bases);
	}

	string rna::get_sequence() const
	{
		ostringstream out;
		for (const nbase& x_base : bases)
		{
			out << x_base;
		}
		return out.str();
	}
}
