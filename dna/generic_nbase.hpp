#ifndef SCIFIR_BIOLOGY_DNA_GENERIC_NBASE_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_GENERIC_NBASE_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

namespace scifir
{
	class generic_nbase
	{
		public:
			enum type {NONE,A,G,T,C,U};

			generic_nbase();
			generic_nbase(const generic_nbase&);
			generic_nbase(generic_nbase&&);
			explicit generic_nbase(generic_nbase::type);
			explicit generic_nbase(char);

			generic_nbase& operator=(const generic_nbase&);
			generic_nbase& operator=(generic_nbase&&);
			generic_nbase& operator=(generic_nbase::type);
			generic_nbase& operator=(char);

			string display() const;

			generic_nbase::type base;
	};

	string to_string(generic_nbase::type);
}

void operator +=(string&, const scifir::generic_nbase&);
string operator +(const string&,const scifir::generic_nbase&);
string operator +(const scifir::generic_nbase&,const string&);

bool operator ==(const scifir::generic_nbase&,const scifir::generic_nbase&);
bool operator !=(const scifir::generic_nbase&,const scifir::generic_nbase&);

ostream& operator <<(ostream&,const scifir::generic_nbase&);

#endif // SCIFIR_BIOLOGY_DNA_GENERIC_NBASE_HPP_INCLUDED
