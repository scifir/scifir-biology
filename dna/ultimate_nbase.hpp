#ifndef MSCI_GENETICS_DNA_ULTIMATE_NBASE_HPP_INCLUDED
#define MSCI_GENETICS_DNA_ULTIMATE_NBASE_HPP_INCLUDED

#include "msci/genetics/dna/nbase.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	class ultimate_nbase : public nbase
	{
		public:
			ultimate_nbase();
			ultimate_nbase(char);

			inline char& get_ultimate_type()
			{
				return ultimate_type;
			}

			inline const char& get_ultimate_type() const
			{
				return ultimate_type;
			}

		private:
			char ultimate_type;
	};
}

void operator +=(string&,const msci::ultimate_nbase&);
string operator +(const string&,const msci::ultimate_nbase&);
string operator +(const msci::ultimate_nbase&,const string&);

bool operator ==(const msci::ultimate_nbase&,const msci::ultimate_nbase&);
bool operator !=(const msci::ultimate_nbase&,const msci::ultimate_nbase&);

ostream& operator <<(ostream&,const msci::ultimate_nbase&);

#endif // MSCI_GENETICS_DNA_ULTIMATE_NBASE_HPP_INCLUDED
