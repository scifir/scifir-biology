#ifndef SCIFIR_BIOLOGY_DNA_GENERIC_NONCODING_SEQUENCE_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_GENERIC_NONCODING_SEQUENCE_HPP_INCLUDED

#include "noncoding_sequence.hpp"

using namespace std;

namespace scifir
{
	class generic_noncoding_sequence : public noncoding_sequence
	{
		public:
			generic_noncoding_sequence();
			explicit generic_noncoding_sequence(const string&,const string&);

			virtual string get_base(int) const;
			virtual void switch_base(int,char);
			virtual void insert_base(int,char);
			virtual void remove_base(int);

			virtual string get_sequence() const;
			virtual void switch_sequence(int,const string&);
			virtual void insert_sequence(int,const string&);
			virtual void set_sequence(const string&);
			virtual void remove_sequence(int,int);

			virtual int number_of_bases() const;

		private:
			const vector<generic_nbase>& get_bases() const;

			vector<generic_nbase> bases;
	};
}

#endif // SCIFIR_BIOLOGY_DNA_GENERIC_NONCODING_SEQUENCE_HPP_INCLUDED
