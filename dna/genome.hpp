#ifndef MSCI_GENETICS_DNA_GENOME_HPP_INCLUDED
#define MSCI_GENETICS_DNA_GENOME_HPP_INCLUDED

#include "msci/genetics/dna/nbase.hpp"
#include "msci/genetics/dna/dna.hpp"

#include <map>
#include <string>
#include <vector>

using namespace std;

namespace msci
{
	class genome
	{
		public:
			genome();

			const vector<nbase>& get_gene_sequence(const string&,const string&) const;

		private:
			mutable map<string,chromosome> chromosomes;
			vector<string> chromosomes_order;
			dna_type type;
			string file_name;
			rapidxml::xml_document<> xml_file;
	};

	extern map<string,genome> all_genomes;
}

#endif // MSCI_GENETICS_DNA_GENOME_HPP_INCLUDED
