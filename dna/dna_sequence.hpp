#ifndef SCIFIR_BIOLOGY_DNA_DNA_SEQUENCE_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_DNA_SEQUENCE_HPP_INCLUDED

#include <string>
#include <vector>

#include "./nbase.hpp"
#include "./rna.hpp"

using namespace std;

namespace scifir
{
	class rna;

	class dna_sequence
	{
		public:
			enum type { GENE, NONCODING_SEQUENCE };

			dna_sequence();
			explicit dna_sequence(const string& new_name,const string& new_sequence);
			explicit dna_sequence(const string& new_name,const vector<nbase>& new_bases);

			virtual dna_sequence::type get_type() const;

			const vector<nbase>& get_bases() const;
			virtual nbase get_base(int index) const;
			
			virtual void switch_base(int index,char new_base);
			virtual void insert_base(int index,char new_base);
			virtual void remove_base(int index);

			virtual string get_sequence() const;
			virtual void switch_sequence(int index,const string& new_sequence);
			virtual void insert_sequence(int index,const string& new_sequence);
			virtual void set_sequence(const string& new_sequence);
			virtual void remove_sequence(int index,int total);

			virtual int number_of_bases() const;

			rna to_rna() const;

			string name;
		
		protected:
			vector<nbase> bases;
	};
}

ostream& operator <<(ostream& os,const scifir::dna_sequence& x);

#endif // SCIFIR_BIOLOGY_DNA_DNA_SEQUENCE_HPP_INCLUDED
