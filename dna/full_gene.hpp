#ifndef MSCI_GENETICS_DNA_FULL_GENE_HPP_INCLUDED
#define MSCI_GENETICS_DNA_FULL_GENE_HPP_INCLUDED

#include "msci/genetics/dna/gene.hpp"
#include "msci/genetics/dna/nbase.hpp"

using namespace std;

namespace msci
{
	class full_gene : public gene
	{
		public:
			full_gene();
			explicit full_gene(const string&,chromosome*,const string&);

			void switch_base(int,char);
			void insert_base(int,char);
			void remove_base(int);

			virtual const vector<nbase>& get_bases() const;

		private:
			vector<nbase> bases;
	};
}

#endif // MSCI_GENETICS_DNA_FULL_GENE_HPP_INCLUDED
