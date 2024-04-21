#ifndef SCIFIR_BIOLOGY_DNA_NONCODING_SEQUENCE_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_NONCODING_SEQUENCE_HPP_INCLUDED

#include "generic_nbase.hpp"
#include "dna_sequence.hpp"
#include "rna.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class noncoding_sequence : public dna_sequence
	{
		public:
			noncoding_sequence();
			explicit noncoding_sequence(const string&);

			string name;
	};
}

ostream& operator <<(ostream&,const scifir::noncoding_sequence&);

#endif // SCIFIR_BIOLOGY_DNA_NONCODING_SEQUENCE_HPP_INCLUDED
