#ifndef SCIFIR_BIOLOGY_DNA_GENE_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_GENE_HPP_INCLUDED

#include "./nbase.hpp"
#include "./dna_sequence.hpp"
#include "./rna.hpp"

#include "scifir/chemistry.hpp"

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
			explicit gene(const string&,const string&);

			virtual dna_sequence::type get_type() const;

			virtual int number_of_codons() const;

			virtual bool is_valid() const;

			virtual protein get_protein() const;
			virtual string get_aminoacid_sequence() const;

			virtual rna get_mrna() const;
	};
}

ostream& operator <<(ostream&,const scifir::gene&);

#endif // SCIFIR_BIOLOGY_DNA_GENE_HPP_INCLUDED
