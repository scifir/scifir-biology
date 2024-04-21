#include "noncoding_sequence.hpp"

using namespace std;

namespace scifir
{
	noncoding_sequence::noncoding_sequence() : name()
	{}

	noncoding_sequence::noncoding_sequence(const string& new_name) : name(new_name)
	{}
}

ostream& operator <<(ostream& os,const scifir::noncoding_sequence& x)
{
	return os << x.name;
}
