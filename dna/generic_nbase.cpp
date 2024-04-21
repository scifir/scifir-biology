#include "generic_nbase.hpp"

using namespace std;

namespace scifir
{
	generic_nbase::generic_nbase() : base(generic_nbase::NONE)
	{}

	generic_nbase::generic_nbase(const generic_nbase& x) : base(x.base)
	{}

	generic_nbase::generic_nbase(generic_nbase&& x) : base(move(x.base))
	{}

	generic_nbase::generic_nbase(generic_nbase::type new_type) : base(new_type)
	{}

	generic_nbase::generic_nbase(char new_type) : base()
	{
		if (new_type == 'A')
		{
			base = generic_nbase::A;
		}
		else if (new_type == 'C')
		{
			base = generic_nbase::C;
		}
		else if (new_type == 'G')
		{
			base = generic_nbase::G;
		}
		else if (new_type == 'T')
		{
			base = generic_nbase::T;
		}
		else if (new_type == 'U')
		{
			base = generic_nbase::U;
		}
		else
		{
			base = generic_nbase::NONE;
		}
	}

	generic_nbase& generic_nbase::operator=(const generic_nbase& x)
	{
		base = x.base;
		return *this;
	}

	generic_nbase& generic_nbase::operator=(generic_nbase&& x)
	{
		base = move(x.base);
		return *this;
	}

	generic_nbase& generic_nbase::operator=(generic_nbase::type x)
	{
		base = x;
		return *this;
	}

	generic_nbase& generic_nbase::operator=(char new_type)
	{
		if (new_type == 'A')
		{
			base = generic_nbase::A;
		}
		else if (new_type == 'C')
		{
			base = generic_nbase::C;
		}
		else if (new_type == 'G')
		{
			base = generic_nbase::G;
		}
		else if (new_type == 'T')
		{
			base = generic_nbase::T;
		}
		else if (new_type == 'U')
		{
			base = generic_nbase::U;
		}
		else
		{
			base = generic_nbase::NONE;
		}
		return *this;
	}

	string generic_nbase::display() const
	{
		return to_string(base);
	}

	string to_string(generic_nbase::type x)
	{
		if (x == generic_nbase::A)
		{
			return "A";
		}
		else if (x == generic_nbase::C)
		{
			return "C";
		}
		else if (x == generic_nbase::G)
		{
			return "G";
		}
		else if (x == generic_nbase::T)
		{
			return "T";
		}
		else if (x == generic_nbase::U)
		{
			return "U";
		}
		else if (x == generic_nbase::NONE)
		{
			return "0";
		}
	}
}

void operator +=(string& x, const scifir::generic_nbase& y)
{
	x += to_string(y.base);
}

string operator +(const string& x,const scifir::generic_nbase& y)
{
	return (x + to_string(y.base));
}

string operator +(const scifir::generic_nbase& x,const string& y)
{
	return (to_string(x.base) + y);
}

bool operator ==(const scifir::generic_nbase& x,const scifir::generic_nbase& y)
{
	return (x.base == y.base);
}

bool operator !=(const scifir::generic_nbase& x,const scifir::generic_nbase& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const scifir::generic_nbase& x)
{
	return os << to_string(x.base);
}
