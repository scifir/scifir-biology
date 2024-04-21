#ifndef SCIFIR_BIOLOGY_GENES_COLLECTION_GENES_COLLECTION_HPP_INCLUDED
#define SCIFIR_BIOLOGY_GENES_COLLECTION_GENES_COLLECTION_HPP_INCLUDED

#include "genes_collection_source.hpp"
#include "genes_collection_genome.hpp"

#include "dna/generic_nbase.hpp"
#include "dna/genome.hpp"
#include "dna/genome_section.hpp"

#include <map>
#include <memory>
#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class genes_collection
	{
		public:
			genes_collection();

			void load_all_species() const;
			void load_species_from_domain(const string& domain) const;
			void load_species_from_kingdom(const string& kingdom) const;
			void load_species_from_phylum(const string& phylum) const;
			void load_species_from_class(const string& species_class) const;
			void load_species_from_order(const string& order) const;
			void load_species_from_family(const string& family) const;
			void load_species_from_genus(const string& genus) const;

			const vector<generic_nbase>& get_gene_sequence(const string&,const string&) const;

			const vector<unique_ptr<genes_collection_source>>& get_sources() const;

		private:
			vector<unique_ptr<genes_collection_source>> sources;
			mutable map<string,genome_section> chromosomes;
			vector<string> chromosomes_order;
			dna_type type;
			string file_name;
			rapidxml::xml_document<> xml_file;
	};

	extern map<string,genes_collection> all_genomes;
}

#endif // SCIFIR_BIOLOGY_GENES_COLLECTION_GENES_COLLECTION_HPP_INCLUDED
