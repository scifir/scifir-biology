#ifndef SCIFIR_BIOLOGY_DNA_DNA_SEQUENCE_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_DNA_SEQUENCE_HPP_INCLUDED

#include <string>

using namespace std;

namespace scifir
{
	class dna_sequence
	{
		public:
			dna_sequence();

			virtual string get_base(int) const = 0;
			virtual void switch_base(int,char) = 0;
			virtual void insert_base(int,char) = 0;
			virtual void remove_base(int) = 0;

			virtual string get_sequence() const = 0;
			virtual void switch_sequence(int,const string&) = 0;
			virtual void insert_sequence(int,const string&) = 0;
			virtual void set_sequence(const string&) = 0;
			virtual void remove_sequence(int,int) = 0;

			virtual int number_of_bases() const = 0;
	};
}

#endif // SCIFIR_BIOLOGY_DNA_DNA_SEQUENCE_HPP_INCLUDED
