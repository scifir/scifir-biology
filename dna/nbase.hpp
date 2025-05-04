#ifndef SCIFIR_BIOLOGY_DNA_NBASE_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_NBASE_HPP_INCLUDED

#include <iostream>
#include <string>

#include "scifir/chemistry.hpp"

using namespace std;

namespace scifir
{
	class nbase
	{
		public:
			enum type {NONE, A, G, T, C, U, CUSTOM};

			nbase();
			nbase(const nbase&);
			nbase(nbase&&);
			explicit nbase(nbase::type);
			explicit nbase(char);

			nbase& operator=(const nbase&);
			nbase& operator=(nbase&&);
			nbase& operator=(nbase::type);
			nbase& operator=(char);

			nbase::type base;
	};

	string to_string(nbase::type x);
	string to_string(const nbase& x);

	nbase::type to_complementary_nbase(nbase::type x_base);
	nbase to_complementary_nbase(const nbase& x_base);

	nbase::type to_dna_nbase(nbase::type x_base);
	nbase to_dna_nbase(const nbase& x_base);

	nbase::type to_rna_nbase(nbase::type x_base);
	nbase to_rna_nbase(const nbase& x_base);

	aminoacid mrna_to_aminoacid(nbase::type x_base1, nbase::type x_base2, nbase::type x_base3);
	aminoacid mrna_to_aminoacid(const nbase& x_base1, const nbase& x_base2, const nbase& x_base3);
}

void operator +=(string&, const scifir::nbase&);
string operator +(const string&,const scifir::nbase&);
string operator +(const scifir::nbase&,const string&);

bool operator ==(const scifir::nbase::type&,const scifir::nbase&);
bool operator !=(const scifir::nbase::type&,const scifir::nbase&);
bool operator ==(const scifir::nbase&,const scifir::nbase::type&);
bool operator !=(const scifir::nbase&,const scifir::nbase::type&);

bool operator ==(const scifir::nbase&,const scifir::nbase&);
bool operator !=(const scifir::nbase&,const scifir::nbase&);

ostream& operator <<(ostream& os,const scifir::nbase& x);
istream& operator >>(istream& is, scifir::nbase& x);

#endif // SCIFIR_BIOLOGY_DNA_NBASE_HPP_INCLUDED
