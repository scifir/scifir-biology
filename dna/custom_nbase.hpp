#ifndef SCIFIR_BIOLOGY_DNA_CUSTOM_NBASE_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_CUSTOM_NBASE_HPP_INCLUDED

#include "generic_nbase.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace scifir
{
	class custom_nbase
	{
		public:
			custom_nbase();
			custom_nbase(const custom_nbase&);
			custom_nbase(custom_nbase&&);
			explicit custom_nbase(generic_nbase::type);
			explicit custom_nbase(char);

			custom_nbase& operator=(const custom_nbase&);
			custom_nbase& operator=(custom_nbase&&);
			custom_nbase& operator=(generic_nbase::type);
			custom_nbase& operator=(char);

			string display() const;

			char base;
	};
}

void operator +=(string&,const scifir::custom_nbase&);
string operator +(const string&,const scifir::custom_nbase&);
string operator +(const scifir::custom_nbase&,const string&);

bool operator ==(const scifir::custom_nbase&,const scifir::custom_nbase&);
bool operator !=(const scifir::custom_nbase&,const scifir::custom_nbase&);

bool operator ==(const scifir::custom_nbase&,const scifir::generic_nbase&);
bool operator !=(const scifir::custom_nbase&,const scifir::generic_nbase&);
bool operator ==(const scifir::generic_nbase&,const scifir::custom_nbase&);
bool operator !=(const scifir::generic_nbase&,const scifir::custom_nbase&);

ostream& operator <<(ostream&,const scifir::custom_nbase&);

#endif // SCIFIR_BIOLOGY_DNA_CUSTOM_NBASE_HPP_INCLUDED
