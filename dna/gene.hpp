#ifndef SCIFIR_BIOLOGY_DNA_GENE_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_GENE_HPP_INCLUDED

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
	class gene : public dna_sequence
	{
		public:
			gene();
			explicit gene(const string&);

			virtual int number_of_codons() const = 0;

			virtual bool is_valid() const = 0;

			//virtual protein get_protein() const = 0;
			virtual string get_aminoacid_sequence() const = 0;

			virtual rna get_mrna() const = 0;

			string name;
	};
}

ostream& operator <<(ostream&,const scifir::gene&);

#endif // SCIFIR_BIOLOGY_DNA_GENE_HPP_INCLUDED
