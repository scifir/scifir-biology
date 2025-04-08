#include "./extended_nbase.hpp"

using namespace std;

namespace scifir
{
	extended_nbase::extended_nbase() : base('0')
	{}

	extended_nbase::extended_nbase(const extended_nbase& x) : base(x.base)
	{}

	extended_nbase::extended_nbase(extended_nbase&& x) : base(move(x.base))
	{}

	extended_nbase::extended_nbase(nbase::type x) : base(to_string(x)[0])
	{}

	extended_nbase::extended_nbase(char new_base) : base(new_base)
	{}

	extended_nbase& extended_nbase::operator=(const extended_nbase& x)
	{
		base = x.base;
		return *this;
	}

	extended_nbase& extended_nbase::operator=(extended_nbase&& x)
	{
		base = move(x.base);
		return *this;
	}

	extended_nbase& extended_nbase::operator=(nbase::type x)
	{
		base = to_string(x)[0];
		return *this;
	}

	extended_nbase& extended_nbase::operator=(char x)
	{
		base = x;
		return *this;
	}

	string extended_nbase::display() const
	{
		return string(1,base);
	}
}

void operator +=(string& x,const scifir::extended_nbase& y)
{
	x += y.base;
}

string operator +(const string& x,const scifir::extended_nbase& y)
{
	return (x + y.base);
}

string operator +(const scifir::extended_nbase& x,const string& y)
{
	return (x.base + y);
}

bool operator ==(const scifir::extended_nbase& x,const scifir::extended_nbase& y)
{
	return (x.base == y.base);
}

bool operator !=(const scifir::extended_nbase& x,const scifir::extended_nbase& y)
{
	return !(x == y);
}

bool operator ==(const scifir::extended_nbase& x,const scifir::nbase& y)
{
	return (to_string(x.base) == to_string(y.base));
}

bool operator !=(const scifir::extended_nbase& x,const scifir::nbase& y)
{
	return !(x == y);
}

bool operator ==(const scifir::nbase& x,const scifir::extended_nbase& y)
{
	return (to_string(x.base) == to_string(y.base));
}

bool operator !=(const scifir::nbase& x,const scifir::extended_nbase& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const scifir::extended_nbase& x)
{
	return os << x.base;
}
