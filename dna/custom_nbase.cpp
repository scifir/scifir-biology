#include "custom_nbase.hpp"

using namespace std;

namespace scifir
{
	custom_nbase::custom_nbase() : base('0')
	{}

	custom_nbase::custom_nbase(const custom_nbase& x) : base(x.base)
	{}

	custom_nbase::custom_nbase(custom_nbase&& x) : base(move(x.base))
	{}

	custom_nbase::custom_nbase(generic_nbase::type x) : base(to_string(x)[0])
	{}

	custom_nbase::custom_nbase(char new_base) : base(new_base)
	{}

	custom_nbase& custom_nbase::operator=(const custom_nbase& x)
	{
		base = x.base;
		return *this;
	}

	custom_nbase& custom_nbase::operator=(custom_nbase&& x)
	{
		base = move(x.base);
		return *this;
	}

	custom_nbase& custom_nbase::operator=(generic_nbase::type x)
	{
		base = to_string(x)[0];
		return *this;
	}

	custom_nbase& custom_nbase::operator=(char x)
	{
		base = x;
		return *this;
	}

	string custom_nbase::display() const
	{
		return string(1,base);
	}
}

void operator +=(string& x,const scifir::custom_nbase& y)
{
	x += y.base;
}

string operator +(const string& x,const scifir::custom_nbase& y)
{
	return (x + y.base);
}

string operator +(const scifir::custom_nbase& x,const string& y)
{
	return (x.base + y);
}

bool operator ==(const scifir::custom_nbase& x,const scifir::custom_nbase& y)
{
	return (x.base == y.base);
}

bool operator !=(const scifir::custom_nbase& x,const scifir::custom_nbase& y)
{
	return !(x == y);
}

bool operator ==(const scifir::custom_nbase& x,const scifir::generic_nbase& y)
{
	return (x.display() == y.display());
}

bool operator !=(const scifir::custom_nbase& x,const scifir::generic_nbase& y)
{
	return !(x == y);
}

bool operator ==(const scifir::generic_nbase& x,const scifir::custom_nbase& y)
{
	return (x.display() == y.display());
}

bool operator !=(const scifir::generic_nbase& x,const scifir::custom_nbase& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const scifir::custom_nbase& x)
{
	return os << x.base;
}
