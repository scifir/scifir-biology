#include "./gene_info_collection.hpp"

using namespace std;

namespace scifir
{
	gene_info_collection::gene_info_collection() : data_sources()
	{}

	gene_info_collection::gene_info_collection(const vector<shared_ptr<gene_info_collection_data_source>>& new_data_sources) : data_sources(new_data_sources)
	{}

	string gene_info_collection::get_description(const string& gene_name) const
	{
		for(const shared_ptr<gene_info_collection_data_source>& data_source : data_sources)
		{
			string description = data_source->get_description(gene_name);
			if (description != "")
			{
				return description;
			}
		}
		return "";
	}
	
	string gene_info_collection::get_chromosome_name(const string& gene_name) const
	{
		for(const shared_ptr<gene_info_collection_data_source>& data_source : data_sources)
		{
			string chromosome_name = data_source->get_chromosome_name(gene_name);
			if (chromosome_name != "")
			{
				return chromosome_name;
			}
		}
		return "";
	}
	
	string gene_info_collection::get_species(const string& gene_name) const
	{
		for(const shared_ptr<gene_info_collection_data_source>& data_source : data_sources)
		{
			string species = data_source->get_species(gene_name);
			if (species != "")
			{
				return species;
			}
		}
		return "";
	}
	
	string gene_info_collection::get_category(const string& gene_name) const
	{
		for(const shared_ptr<gene_info_collection_data_source>& data_source : data_sources)
		{
			string category = data_source->get_category(gene_name);
			if (category != "")
			{
				return category;
			}
		}
		return "";
	}
	
	vector<string> gene_info_collection::get_alleles(const string& gene_name) const
	{
		for(const shared_ptr<gene_info_collection_data_source>& data_source : data_sources)
		{
			vector<string> alleles = data_source->get_alleles(gene_name);
			if (alleles.size() != 0)
			{
				return alleles;
			}
		}
		return vector<string>();
	}
}
