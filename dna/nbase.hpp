#ifndef MSCI_GENETICS_DNA_NBASE_HPP_INCLUDED
#define MSCI_GENETICS_DNA_NBASE_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	class nbase
	{
		public:
			enum type {A,G,T,C,U,other};

			nbase();
			nbase(nbase::type);
			nbase(char);

			inline nbase::type& get_type()
			{
				return base_type;
			}

			inline const nbase::type& get_type() const
			{
				return base_type;
			}

		private:
			nbase::type base_type;
	};

	string to_string(nbase::type);
	nbase create_nbase(char);
}

void operator +=(string&, const msci::nbase&);
string operator +(const string&,const msci::nbase&);
string operator +(const msci::nbase&,const string&);

bool operator == (const msci::nbase&,const msci::nbase&);
bool operator != (const msci::nbase&,const msci::nbase&);

ostream& operator <<(ostream&,const msci::nbase&);

#endif // MSCI_GENETICS_DNA_NBASE_HPP_INCLUDED
