#include "taxonomic_category.hpp"

using namespace std;

namespace scifir
{
	taxonomic_category::taxonomic_category() : name(),value(),parent_category()
	{}

	taxonomic_category::taxonomic_category(const taxonomic_category& x) : name(x.name),value(x.value),parent_category(x.parent_category)
	{}

	taxonomic_category::taxonomic_category(taxonomic_category&& x) : name(move(x.name)),value(move(x.value)),parent_category(move(x.parent_category))
	{}

	taxonomic_category::taxonomic_category(const string& new_name,const string& new_value,const taxonomic_category& new_parent_category) : name(new_name),value(new_value),parent_category(make_shared<taxonomic_category>(new_parent_category))
	{}
}
