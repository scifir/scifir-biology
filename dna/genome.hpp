#ifndef SCIFIR_BIOLOGY_DNA_GENOME_HPP_INCLUDED
#define SCIFIR_BIOLOGY_DNA_GENOME_HPP_INCLUDED

#include "./chromosome.hpp"

#include <map>
#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	enum dna_type {natural_dna,extraterrestrial_dna,artificial_dna,ultimate_dna};

	class genome
	{
		public:
			genome();
			explicit genome(const string&);

			inline const map<string,chromosome>& get_chromosomes() const
			{
				return chromosomes;
			}

			inline const dna_type& get_type() const
			{
				return type;
			}

			inline const string& get_filename() const
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
			string species;
	};
}

#endif // SCIFIR_BIOLOGY_DNA_GENOME_HPP_INCLUDED
