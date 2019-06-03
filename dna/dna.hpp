#ifndef BIOLOGY_DNA_DNA_HPP_INCLUDED
#define BIOLOGY_DNA_DNA_HPP_INCLUDED

#include "msci/genetics/dna/chromosome.hpp"

#include <map>
#include <string>
#include <vector>

#include "rapidxml/rapidxml.hpp"

using namespace std;

namespace msci
{
	enum dna_type {natural_dna,extraterrestrial_dna,artificial_dna,ultimate_dna};

	class dna
	{
		public:
			dna();
			explicit dna(const string&);

			inline const map<string,chromosome>& get_cromosomes() const
			{
				return chromosomes;
			}

			inline const dna_type& get_type() const
			{
				return type;
			}

			inline const string& get_file_name() const
			{
				return file_name;
			}

			inline const string& get_species() const
			{
				return species;
			}

			chromosome& operator [](const string&);
			const chromosome& operator [](const string&) const;

			inline bool is_natural_dna() const
			{
				return (type == natural_dna);
			}

			inline bool is_extraterrestrial_dna() const
			{
				return (type == extraterrestrial_dna);
			}

			inline bool is_artificial_dna() const
			{
				return (type == artificial_dna);
			}

			inline bool is_ultimate_dna() const
			{
				return (type == ultimate_dna);
			}

			bool is_chromosome_loaded(const string&) const;
			void load_chromosome(const string&) const;
			void unload_chromosome(const string&) const;
			void load_all_chromosomes() const;
			void load_chromosomes(const vector<string>&) const;
			void unload_chromosomes(const vector<string>&) const;

			void add_chromosome(const chromosome&);
			void remove_chromosome(const string&);

			void switch_chromosome(const string&,const string&);
			void position_chromosome(const string&,int);

			inline int number_of_chromosomes() const
			{
				return chromosomes.size();
			}

			bool has_gene(const string&);
			bool has_gene_sequence(const string&);

		private:
			mutable map<string,chromosome> chromosomes;
			vector<string> chromosomes_order;
			dna_type type;
			string file_name;
			rapidxml::xml_document<> xml_file;
			string species;
	};
}

#endif // BIOLOGY_DNA_DNA_HPP_INCLUDED
