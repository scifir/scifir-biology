#ifndef BIOLOGY_DNA_GENE_HPP_INCLUDED
#define BIOLOGY_DNA_GENE_HPP_INCLUDED

#include "boost/variant.hpp"

#include "msci/chemistry.hpp"
#include "msci/genetics/dna/nbase.hpp"

#include <vector>

using namespace std;

namespace msci
{
	typedef int gen_index_type;

	class chromosome;

	class gene
	{
		public:
			gene();
			explicit gene(const string&,chromosome*);

			inline string& get_name()
			{
				return name;
			}

			inline const string& get_name() const
			{
				return name;
			}

			inline chromosome* get_chromosome()
			{
				return chromosome_molecule;
			}

			inline const chromosome* get_chromosome() const
			{
				return chromosome_molecule;
			}

			inline string get_sequence() const
			{
				return "";
			}

			virtual const vector<nbase>& get_bases() const;

			inline int number_of_bases() const
			{
				return 1;
				//return bases.size();
			}

			//molecule operator[](int) const;

			void switch_base(gen_index_type,uint8_t);
			void insert_base(gen_index_type,uint8_t);
			void remove_base(gen_index_type);

			//vector<protein> get_codons_protein() const;

			bool is_valid() const;

		private:
			string name;
			chromosome* chromosome_molecule;
	};
}

#endif // BIOLOGY_DNA_GENE_HPP_INCLUDED
