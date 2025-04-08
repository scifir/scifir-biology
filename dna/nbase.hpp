#ifndef SCIFIR_BIOLOGY_DNA_NBASE_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_NBASE_HPP_INCLUDED

#include <iostream>
#include <string>

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

	string to_string(nbase::type);
	string to_string(const nbase&);

	nbase::type to_complementary_nbase(nbase::type);
	nbase to_complementary_nbase(const nbase&);

	nbase::type to_dna_nbase(nbase::type);
	nbase to_dna_nbase(const nbase&);

	nbase::type to_rna_nbase(nbase::type);
	nbase to_rna_nbase(const nbase&);
}

void operator +=(string&, const scifir::nbase&);
string operator +(const string&,const scifir::nbase&);
string operator +(const scifir::nbase&,const string&);

bool operator ==(const scifir::nbase&,const scifir::nbase&);
bool operator !=(const scifir::nbase&,const scifir::nbase&);

ostream& operator <<(ostream&,const scifir::nbase&);

#endif // SCIFIR_BIOLOGY_DNA_NBASE_HPP_INCLUDED
