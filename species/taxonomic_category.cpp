#include "./taxonomic_category.hpp"

using namespace std;

namespace scifir
{
	taxonomic_category::taxonomic_category() : custom_type(),value(),child_category(),taxonomic_type()
	{}

	taxonomic_category::taxonomic_category(const taxonomic_category& x) : custom_type(x.custom_type),value(x.value),child_category(x.child_category),taxonomic_type(x.taxonomic_type)
	{}

	taxonomic_category::taxonomic_category(taxonomic_category&& x) : custom_type(move(x.custom_type)),value(move(x.value)),child_category(move(x.child_category)),taxonomic_type(move(x.taxonomic_type))
	{}

	taxonomic_category::taxonomic_category(const taxonomic_category::type& new_taxonomic_type,const string& new_custom_type,const string& new_value,const taxonomic_category& new_child_category) : custom_type(new_custom_type),value(new_value),child_category(make_shared<taxonomic_category>(new_child_category)),taxonomic_type(new_taxonomic_type)
	{}

	string taxonomic_category::get_name() const
	{
		if (taxonomic_type != taxonomic_category::OTHER && taxonomic_type != taxonomic_category::NONE)
		{
			return to_string(taxonomic_type);
		}
		else
		{
			return custom_type;
		}
	}

	bool taxonomic_category::is_basal_category() const
	{
		if (taxonomic_type == taxonomic_category::TAXONOMY_DOMAIN || taxonomic_type == taxonomic_category::KINGDOM || taxonomic_type == taxonomic_category::PHYLUM || taxonomic_type == taxonomic_category::CLASS || taxonomic_type == taxonomic_category::ORDER || taxonomic_type == taxonomic_category::FAMILY || taxonomic_type == taxonomic_category::GENUS || taxonomic_type == taxonomic_category::SPECIES)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string to_string(const taxonomic_category::type& x)
	{
		if (x == taxonomic_category::TAXONOMY_DOMAIN)
		{
			return "domain";
		}
		else if (x == taxonomic_category::KINGDOM)
		{
			return "kingdom";
		}
		else if (x == taxonomic_category::PHYLUM)
		{
			return "phylum";
		}
		else if (x == taxonomic_category::CLASS)
		{
			return "class";
		}
		else if (x == taxonomic_category::ORDER)
		{
			return "order";
		}
		else if (x == taxonomic_category::FAMILY)
		{
			return "family";
		}
		else if (x == taxonomic_category::GENUS)
		{
			return "genus";
		}
		else if (x == taxonomic_category::SPECIES)
		{
			return "species";
		}
		else
		{
			return "";
		}
	}
}
