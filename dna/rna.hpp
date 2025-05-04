#ifndef SCIFIR_BIOLOGY_DNA_RNA_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_RNA_HPP_INCLUDED

#include "./nbase.hpp"
#include "./dna_sequence.hpp"

#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class dna_sequence;

	class rna
	{
		public:
			rna();
			explicit rna(const vector<nbase>&);
			explicit rna(const string&);

			dna_sequence to_dna() const;
			
			string get_sequence() const;

			vector<nbase> bases;
	};
}

#endif // SCIFIR_BIOLOGY_DNA_RNA_HPP_INCLUDED
