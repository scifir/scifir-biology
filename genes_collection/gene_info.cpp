#include "./gene_info.hpp"

using namespace std;

namespace scifir
{
	gene_info::gene_info() : name(),description(),chromosome(),species(),category(),alleles()
	{}

	gene_info::gene_info(const string& new_name,const string& new_description,const string& new_chromosome,const string& new_species,const string& new_category,const vector<string>& new_alleles) : name(new_name),description(new_description),chromosome(new_chromosome),species(new_species),category(new_category),alleles(new_alleles)
	{}
}
