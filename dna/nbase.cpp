#include "./nbase.hpp"

using namespace std;

namespace scifir
{
	nbase::nbase() : base(nbase::NONE)
	{}

	nbase::nbase(const nbase& x) : base(x.base)
	{}

	nbase::nbase(nbase&& x) : base(move(x.base))
	{}

	nbase::nbase(nbase::type new_type) : base(new_type)
	{}

	nbase::nbase(char new_type) : base()
	{
		if (new_type == 'A')
		{
			base = nbase::A;
		}
		else if (new_type == 'C')
		{
			base = nbase::C;
		}
		else if (new_type == 'G')
		{
			base = nbase::G;
		}
		else if (new_type == 'T')
		{
			base = nbase::T;
		}
		else if (new_type == 'U')
		{
			base = nbase::U;
		}
		else
		{
			base = nbase::NONE;
		}
	}

	nbase& nbase::operator=(const nbase& x)
	{
		base = x.base;
		return *this;
	}

	nbase& nbase::operator=(nbase&& x)
	{
		base = move(x.base);
		return *this;
	}

	nbase& nbase::operator=(nbase::type x)
	{
		base = x;
		return *this;
	}

	nbase& nbase::operator=(char new_type)
	{
		if (new_type == 'A')
		{
			base = nbase::A;
		}
		else if (new_type == 'C')
		{
			base = nbase::C;
		}
		else if (new_type == 'G')
		{
			base = nbase::G;
		}
		else if (new_type == 'T')
		{
			base = nbase::T;
		}
		else if (new_type == 'U')
		{
			base = nbase::U;
		}
		else
		{
			base = nbase::NONE;
		}
		return *this;
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
		else if (x == nbase::NONE)
		{
			return "0";
		}
		else if (x == nbase::CUSTOM)
		{
			return "X";
		}
	}

	string to_string(const nbase& x)
	{
		return to_string(x.base);
	}

	nbase::type to_complementary_nbase(nbase::type x_base)
	{
		if (x_base == nbase::T)
		{
			return nbase::A;
		}
		else if (x_base == nbase::A)
		{
			return nbase::T;
		}
		else if (x_base == nbase::C)
		{
			return nbase::G;
		}
		else if (x_base == nbase::G)
		{
			return nbase::C;
		}
		else
		{
			return nbase::NONE;
		}
	}

	nbase to_complementary_nbase(const nbase& x_base)
	{
		if (x_base.base == nbase::T)
		{
			return nbase(nbase::A);
		}
		else if (x_base.base == nbase::A)
		{
			return nbase(nbase::T);
		}
		else if (x_base.base == nbase::C)
		{
			return nbase(nbase::G);
		}
		else if (x_base.base == nbase::G)
		{
			return nbase(nbase::C);
		}
		else
		{
			return nbase();
		}
	}

	nbase::type to_dna_nbase(nbase::type x_base)
	{
		if (x_base == nbase::U)
		{
			return nbase::A;
		}
		else if (x_base == nbase::A)
		{
			return nbase::T;
		}
		else if (x_base == nbase::C)
		{
			return nbase::G;
		}
		else if (x_base == nbase::G)
		{
			return nbase::C;
		}
		else
		{
			return nbase::NONE;
		}
	}

	nbase to_dna_nbase(const nbase& x_base)
	{
		if (x_base.base == nbase::U)
		{
			return nbase(nbase::A);
		}
		else if (x_base.base == nbase::A)
		{
			return nbase(nbase::T);
		}
		else if (x_base.base == nbase::C)
		{
			return nbase(nbase::G);
		}
		else if (x_base.base == nbase::G)
		{
			return nbase(nbase::C);
		}
		else
		{
			return nbase();
		}
	}

	nbase::type to_rna_nbase(nbase::type x_base)
	{
		if (x_base == nbase::A)
		{
			return nbase::U;
		}
		else if (x_base == nbase::T)
		{
			return nbase::A;
		}
		else if (x_base == nbase::C)
		{
			return nbase::G;
		}
		else if (x_base == nbase::G)
		{
			return nbase::C;
		}
		else
		{
			return nbase::NONE;
		}
	}

	nbase to_rna_nbase(const nbase& x_base)
	{
		if (x_base.base == nbase::A)
		{
			return nbase(nbase::U);
		}
		else if (x_base.base == nbase::T)
		{
			return nbase(nbase::A);
		}
		else if (x_base.base == nbase::C)
		{
			return nbase(nbase::G);
		}
		else if (x_base.base == nbase::G)
		{
			return nbase(nbase::C);
		}
		else
		{
			return nbase();
		}
	}
}

void operator +=(string& x, const scifir::nbase& y)
{
	x += to_string(y.base);
}

string operator +(const string& x,const scifir::nbase& y)
{
	return (x + to_string(y.base));
}

string operator +(const scifir::nbase& x,const string& y)
{
	return (to_string(x.base) + y);
}

bool operator ==(const scifir::nbase& x,const scifir::nbase& y)
{
	return (x.base == y.base);
}

bool operator !=(const scifir::nbase& x,const scifir::nbase& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const scifir::nbase& x)
{
	return os << to_string(x.base);
}

istream& operator >>(istream& is, scifir::nbase& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	x = scifir::nbase(b.at(0));
	return is;
}