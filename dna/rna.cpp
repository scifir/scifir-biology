#include "rna.hpp"
#include "dna.hpp"

namespace scifir
{
	rna::rna() : bases()
	{}

	rna::rna(const vector<generic_nbase>& new_bases) : bases(new_bases)
	{}

	rna::rna(const string& new_sequence) : bases()
	{
		for (int i = 0; i < new_sequence.size(); i++)
		{
			bases.push_back(generic_nbase(new_sequence[i]));
		}
	}

	dna rna::to_dna() const
	{
		vector<generic_nbase> new_bases = vector<generic_nbase>();
		for (const generic_nbase& x_base : bases)
		{
			new_bases.push_back(to_dna_nbase(x_base));
		}
		return dna(new_bases);
	}

	generic_nbase::type to_rna_nbase(generic_nbase::type x_base)
	{
		if (x_base == generic_nbase::A)
		{
			return generic_nbase::U;
		}
		else if (x_base == generic_nbase::T)
		{
			return generic_nbase::A;
		}
		else if (x_base == generic_nbase::C)
		{
			return generic_nbase::G;
		}
		else if (x_base == generic_nbase::G)
		{
			return generic_nbase::C;
		}
		else
		{
			return generic_nbase::NONE;
		}
	}

	generic_nbase to_rna_nbase(const generic_nbase& x_base)
	{
		if (x_base.base == generic_nbase::A)
		{
			return generic_nbase(generic_nbase::U);
		}
		else if (x_base.base == generic_nbase::T)
		{
			return generic_nbase(generic_nbase::A);
		}
		else if (x_base.base == generic_nbase::C)
		{
			return generic_nbase(generic_nbase::G);
		}
		else if (x_base.base == generic_nbase::G)
		{
			return generic_nbase(generic_nbase::C);
		}
		else
		{
			return generic_nbase();
		}
	}
}
