#ifndef SCIFIR_BIOLOGY_DNA_RNA_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_RNA_HPP_INCLUDED

#include "generic_nbase.hpp"

#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class dna;

	class rna
	{
		public:
			rna();
			explicit rna(const vector<generic_nbase>&);
			explicit rna(const string&);

			dna to_dna() const;

		private:
			vector<generic_nbase> bases;
	};

	generic_nbase::type to_rna_nbase(generic_nbase::type);
	generic_nbase to_rna_nbase(const generic_nbase&);
}

#endif // SCIFIR_BIOLOGY_DNA_RNA_HPP_INCLUDED
