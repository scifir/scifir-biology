#ifndef SCIFIR_BIOLOGY_DNA_DNA_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_DNA_HPP_INCLUDED

#include "generic_nbase.hpp"
#include "rna.hpp"

#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class dna
	{
		public:
			dna();
			explicit dna(const vector<generic_nbase>&);
			explicit dna(const string&);

			rna to_rna() const;

		private:
			vector<generic_nbase> bases;
	};

	generic_nbase::type to_complementary_nbase(generic_nbase::type);
	generic_nbase to_complementary_nbase(const generic_nbase&);

	generic_nbase::type to_dna_nbase(generic_nbase::type);
	generic_nbase to_dna_nbase(const generic_nbase&);
}

#endif // SCIFIR_BIOLOGY_DNA_DNA_HPP_INCLUDED

