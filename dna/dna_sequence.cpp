#include "./dna_sequence.hpp"

#include <sstream>

using namespace std;

namespace scifir
{
	dna_sequence::dna_sequence() : name(),bases()
	{}

	dna_sequence::dna_sequence(const string& new_name,const string& new_sequence) : name(new_name),bases()
	{
		for (int i = 0; i < new_sequence.size(); i++)
		{
			bases.push_back(nbase(new_sequence[i]));
		}
	}
	
	dna_sequence::dna_sequence(const string& new_name,const vector<nbase>& new_bases) : name(new_name),bases(new_bases)
	{}

	dna_sequence::type dna_sequence::get_type() const
	{
		return dna_sequence::NONCODING_SEQUENCE;
	}

	const vector<nbase>& dna_sequence::get_bases() const
	{
		return bases;
	}

	nbase dna_sequence::get_base(int index) const
	{
		return bases[index];
	}

	void dna_sequence::switch_base(int index,char new_base)
	{
		bases[index] = new_base;
	}

	void dna_sequence::insert_base(int index,char new_base)
	{
		bases.insert(bases.begin() + index,nbase(new_base));
	}

	void dna_sequence::remove_base(int index)
	{
		bases.erase(bases.begin() + index);
	}

	string dna_sequence::get_sequence() const
	{
		ostringstream out;
		for (const nbase& x_base : bases)
		{
			out << x_base;
		}
		return out.str();
	}

	void dna_sequence::switch_sequence(int index,const string& new_sequence)
	{
		int total = index + new_sequence.length();
		for (int i = index; i < total; i++)
		{
			bases[i] = new_sequence[i];
		}
	}

	void dna_sequence::insert_sequence(int index,const string& new_sequence)
	{
		vector<nbase> new_bases = vector<nbase>();
		for (int i = 0; i < new_sequence.length(); i++)
		{
			new_bases.push_back(nbase(new_sequence[i]));
		}
		bases.insert(bases.begin() + index,new_bases.begin(),new_bases.end());
	}

	void dna_sequence::set_sequence(const string& new_sequence)
	{
		bases.clear();
		for (int i = 0; i < new_sequence.size(); i++)
		{
			bases.push_back(nbase(new_sequence[i]));
		}
	}

	void dna_sequence::remove_sequence(int index,int total)
	{
		bases.erase(bases.begin() + index,bases.begin() + index + total);
	}

	int dna_sequence::number_of_bases() const
	{
		return bases.size();
	}

	rna dna_sequence::to_rna() const
	{
		vector<nbase> new_bases = vector<nbase>();
		for (const nbase& x_base : bases)
		{
			new_bases.push_back(to_rna_nbase(x_base));
		}
		return rna(new_bases);
	}
}

ostream& operator <<(ostream& os,const scifir::dna_sequence& x)
{
	return os << x.name;
}