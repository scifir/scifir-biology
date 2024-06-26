#ifndef SCIFIR_BIOLOGY_DNA_CHROMOSOME_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_CHROMOSOME_HPP_INCLUDED

#include "gene.hpp"

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "rapidxml/rapidxml.hpp"

using namespace std;

namespace scifir
{
	class genome;

	class genome_section
	{
		public:
			genome_section();
			explicit genome_section(const string&,genome*,rapidxml::xml_node<>*);
			explicit genome_section(const map<string,shared_ptr<gene>>&);

			inline const string& get_name() const
			{
				return name;
			}

			inline const map<string,shared_ptr<gene>>& get_genes() const
			{
				return genes;
			}

			inline const genome* get_genome() const
			{
				return genome_molecule;
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

			shared_ptr<gene>& operator[](const string&);
			const shared_ptr<gene>& operator[](const string&) const;

			inline int number_of_genes() const
			{
				return genes.size();
			}

			void switch_gene(const string&,shared_ptr<gene>);
			void insert_gene(const string&,shared_ptr<gene>);
			void insert_genes(const string&,map<string,shared_ptr<gene>>);
			void remove_gene(const string&);

			bool has_gene(const string&) const;
			bool has_gene_sequence(const string&) const;

		private:
			mutable map<string,shared_ptr<gene>> genes;
			genome* genome_molecule;
			rapidxml::xml_node<>* chromosome_node;
			string name;
	};
}

#endif // SCIFIR_BIOLOGY_DNA_CHROMOSOME_HPP_INCLUDED
