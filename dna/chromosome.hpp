#ifndef BIOLOGY_DNA_CHROMOSOME_HPP_INCLUDED
#define BIOLOGY_DNA_CHROMOSOME_HPP_INCLUDED

#include "msci/genetics/dna/gene.hpp"

#include <map>
#include <string>
#include <vector>

#include "rapidxml/rapidxml.hpp"

using namespace std;

namespace msci
{
	class dna;

	class chromosome
	{
		public:
			chromosome();
			explicit chromosome(const string&,dna*,rapidxml::xml_node<>*);
			explicit chromosome(map<string,gene>);

			inline const string& get_name() const
			{
				return name;
			}

			inline const map<string,gene>& get_genes() const
			{
				return genes;
			}

			inline const dna* get_dna() const
			{
				return dna_molecule;
			}

			inline const rapidxml::xml_node<>* get_chromosome_node() const
			{
				return chromosome_node;
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
				return genes.size();
			}

			void switch_gene(const string&,gene);
			void insert_gene(const string&,gene);
			void insert_genes(const string&,map<string,gene>);
			void remove_gene(const string&);

			bool has_gene(const string&) const;
			bool has_gene_sequence(const string&) const;

		private:
			mutable map<string,gene> genes;
			dna* dna_molecule;
			rapidxml::xml_node<>* chromosome_node;
			string name;
	};
}

#endif // BIOLOGY_DNA_CHROMOSOME_HPP_INCLUDED
