#ifndef SCIFIR_BIOLOGY_DNA_extended_nbase_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_extended_nbase_HPP_INCLUDED

#include "./nbase.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace scifir
{
	class extended_nbase : public nbase
	{
		public:
			extended_nbase();
			extended_nbase(const extended_nbase&);
			extended_nbase(extended_nbase&&);
			explicit extended_nbase(nbase::type);
			explicit extended_nbase(char);

			extended_nbase& operator=(const extended_nbase&);
			extended_nbase& operator=(extended_nbase&&);
			extended_nbase& operator=(nbase::type);
			extended_nbase& operator=(char);

			string display() const;

			char base;
	};
}

void operator +=(string&,const scifir::extended_nbase&);
string operator +(const string&,const scifir::extended_nbase&);
string operator +(const scifir::extended_nbase&,const string&);

bool operator ==(const scifir::extended_nbase&,const scifir::extended_nbase&);
bool operator !=(const scifir::extended_nbase&,const scifir::extended_nbase&);

bool operator ==(const scifir::extended_nbase&,const scifir::nbase&);
bool operator !=(const scifir::extended_nbase&,const scifir::nbase&);
bool operator ==(const scifir::nbase&,const scifir::extended_nbase&);
bool operator !=(const scifir::nbase&,const scifir::extended_nbase&);

ostream& operator <<(ostream&,const scifir::extended_nbase&);

#endif // SCIFIR_BIOLOGY_DNA_extended_nbase_HPP_INCLUDED
