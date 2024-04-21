#include "generic_noncoding_sequence.hpp"

using namespace std;

namespace scifir
{
	generic_noncoding_sequence::generic_noncoding_sequence() : noncoding_sequence(),bases()
	{}

	generic_noncoding_sequence::generic_noncoding_sequence(const string& new_name,const string& new_sequence) : noncoding_sequence(new_name),bases()
	{
		for (int i = 0; i < new_sequence.size(); i++)
		{
			bases.push_back(generic_nbase(new_sequence[i]));
		}
	}

	string generic_noncoding_sequence::get_base(int index) const
	{
		return get_bases()[index].display();
	}

	void generic_noncoding_sequence::switch_base(int index,char new_base)
	{
		bases[index] = new_base;
	}

	void generic_noncoding_sequence::insert_base(int index,char new_base)
	{
		bases.insert(bases.begin() + index,generic_nbase(new_base));
	}

	void generic_noncoding_sequence::remove_base(int index)
	{
		bases.erase(bases.begin() + index);
	}

	string generic_noncoding_sequence::get_sequence() const
	{
		ostringstream out;
		for (const generic_nbase& x_base : bases)
		{
			out << x_base;
		}
		return out.str();
	}

	void generic_noncoding_sequence::switch_sequence(int index,const string& new_sequence)
	{
		int total = index + new_sequence.length();
		for (int i = index; i < total; i++)
		{
			bases[i] = new_sequence[i];
		}
	}

	void generic_noncoding_sequence::insert_sequence(int index,const string& new_sequence)
	{
		vector<generic_nbase> new_bases = vector<generic_nbase>();
		for (int i = 0; i < new_sequence.length(); i++)
		{
			new_bases.push_back(generic_nbase(new_sequence[i]));
		}
		bases.insert(bases.begin() + index,new_bases.begin(),new_bases.end());
	}

	void generic_noncoding_sequence::set_sequence(const string& new_sequence)
	{
		bases.clear();
		for (int i = 0; i < new_sequence.size(); i++)
		{
			bases.push_back(generic_nbase(new_sequence[i]));
		}
	}

	void generic_noncoding_sequence::remove_sequence(int index,int total)
	{
		bases.erase(bases.begin() + index,bases.begin() + index + total);
	}

	int generic_noncoding_sequence::number_of_bases() const
	{
		return bases.size();
	}
}
