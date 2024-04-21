#ifndef SCIFIR_BIOLOGY_GENES_COLLECTION_GENE_INFO_HPP_INCLUDED
#define SCIFIR_BIOLOGY_GENES_COLLECTION_GENE_INFO_HPP_INCLUDED

#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class gene_info
	{
		public:
			gene_info();
			gene_info(const string&,const string&,const string&,const string&,const string&,const vector<string>&);

			string name;
			string description;
			string chromosome;
			string species;
			string category;
			vector<string> alleles;
	};
}

#endif // SCIFIR_BIOLOGY_GENES_COLLECTION_GENE_INFO_HPP_INCLUDED
