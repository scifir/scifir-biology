#ifndef SCIFIR_BIOLOGY_DNA_GENERIC_GENE_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_GENERIC_GENE_HPP_INCLUDED

#include "gene.hpp"
#include "generic_nbase.hpp"

#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class generic_gene : public gene
	{
		public:
			generic_gene();
			explicit generic_gene(const string&,const string&);

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
			virtual int number_of_codons() const;

			virtual bool is_valid() const;

			//virtual protein get_protein() const;
			virtual string get_aminoacid_sequence() const;

			virtual rna get_mrna() const;

		private:
			const vector<generic_nbase>& get_bases() const;

			vector<generic_nbase> bases;
	};
}

#endif // SCIFIR_BIOLOGY_DNA_GENERIC_GENE_HPP_INCLUDED
