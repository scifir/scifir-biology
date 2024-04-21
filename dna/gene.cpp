#include "gene.hpp"
#include "genome_section.hpp"
#include "generic_gene.hpp"

#include <cmath>

using namespace std;

namespace scifir
{
	gene::gene() : name()
	{}

	gene::gene(const string& new_name) : name(new_name)
	{}

	/*string gene::get_sequence() const
	{
		ostringstream out;
		vector<generic_nbase> bases;
		gene* gene_a = const_cast<gene*>(this);
		generic_gene* generic_gene_a = dynamic_cast<generic_gene*>(gene_a);
		if (generic_gene_a)
		{
			bases = generic_gene_a->get_bases();
		}
		else
		{
			bases = gene_a->gene::get_bases();
		}
		if (bases.size() > 0)
		{
			for (const generic_nbase& x_base : bases)
			{
				out << x_base;
			}
			return out.str();
		}
		else
		{
			return "";
		}
	}*/
}

ostream& operator <<(ostream& os,const scifir::gene& x)
{
	return os << x.name;
}
