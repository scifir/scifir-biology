#ifndef SCIFIR_BIOLOGY_DNA_CHROMOSOME_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_CHROMOSOME_HPP_INCLUDED

#include "./gene.hpp"

#include <map>
#include <memory>
#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class chromosome
	{
		public:
			chromosome();
			explicit chromosome(const string&,const map<string,gene>&);

			inline const string& get_name() const
			{
				return name;
			}

			inline const map<string,gene>& get_genes() const
			{
				return genes;
			}

			bool is_gene_loaded(const string&) const;
			void load_gene(const string&);
			void unload_gene(const string&);
			void load_all_genes() const;
			void load_genes(const vector<string>&);
			void unload_genes(const vector<string>&);

			gene& operator[](const string&);
			const gene& operator[](const string&) const;

			inline int number_of_genes() const
			{
				return int(genes.size());
			}

			void switch_gene(const string&,const gene&);
			void insert_gene(const string&,const gene&);
			void insert_genes(const string&,map<string,gene>);
			void remove_gene(const string&);

			bool has_gene(const string&) const;
			bool has_gene_sequence(const string&) const;

		private:
			mutable map<string,gene> genes;
			string name;
	};
}

#endif // SCIFIR_BIOLOGY_DNA_CHROMOSOME_HPP_INCLUDED
