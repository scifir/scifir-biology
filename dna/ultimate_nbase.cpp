#include "msci/genetics/dna/ultimate_nbase.hpp"

using namespace std;

namespace msci
{
	ultimate_nbase::ultimate_nbase() : nbase(),ultimate_type()
	{

	}

	ultimate_nbase::ultimate_nbase(char new_ultimate_type) : nbase(nbase::other),ultimate_type(new_ultimate_type)
	{

	}
}

void operator +=(string& x,const msci::ultimate_nbase& y)
{
	x += y.get_ultimate_type();
}

string operator +(const string& x,const msci::ultimate_nbase& y)
{
	return (x + y.get_ultimate_type());
}

string operator +(const msci::ultimate_nbase& x,const string& y)
{
	return (x.get_ultimate_type() + y);
}

bool operator ==(const msci::ultimate_nbase& x,const msci::ultimate_nbase& y)
{
	return (x.get_ultimate_type() == y.get_ultimate_type());
}

bool operator !=(const msci::ultimate_nbase& x,const msci::ultimate_nbase& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const msci::ultimate_nbase& x)
{
	return os << x.get_ultimate_type();
}
