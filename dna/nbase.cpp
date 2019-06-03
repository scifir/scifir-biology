#include "msci/genetics/dna/nbase.hpp"
#include "msci/genetics/dna/ultimate_nbase.hpp"
#include "msci/genetics/dna/genome.hpp"

using namespace std;

namespace msci
{
	nbase::nbase() : base_type()
	{
	}

	nbase::nbase(nbase::type new_type) : base_type(new_type)
	{
	}

	nbase::nbase(char new_type) : base_type()
	{
		if (new_type == 'A')
		{
			base_type = nbase::A;
		}
		else if (new_type == 'C')
		{
			base_type = nbase::C;
		}
		else if (new_type == 'G')
		{
			base_type = nbase::G;
		}
		else if (new_type == 'T')
		{
			base_type = nbase::T;
		}
		else if (new_type == 'U')
		{
			base_type = nbase::U;
		}
		else
		{
			base_type = nbase::other;
		}
	}

	string to_string(nbase::type x)
	{
		if (x == nbase::A)
		{
			return "A";
		}
		else if (x == nbase::C)
		{
			return "C";
		}
		else if (x == nbase::G)
		{
			return "G";
		}
		else if (x == nbase::T)
		{
			return "T";
		}
		else if (x == nbase::U)
		{
			return "U";
		}
		else if (x == nbase::other)
		{
			return "0";
		}
	}

	nbase create_nbase(char x)
	{
		nbase new_base;
		if (x == 'A' || x == 'C' || x == 'G' || x == 'T' || x == 'U')
		{
			new_base = nbase(x);
		}
		else
		{
			new_base = ultimate_nbase(x);
		}
		return new_base;
	}
}

void operator +=(string& x, const msci::nbase& y)
{
	x += to_string(y.get_type());
}

string operator +(const string& x,const msci::nbase& y)
{
	return (x + to_string(y.get_type()));
}

string operator +(const msci::nbase& x,const string& y)
{
	return (to_string(x.get_type()) + y);
}

bool operator == (const msci::nbase& x,const msci::nbase& y)
{
	return (x.get_type() == y.get_type());
}

bool operator != (const msci::nbase& x,const msci::nbase& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const msci::nbase& x)
{
	return os << to_string(x.get_type());
}
