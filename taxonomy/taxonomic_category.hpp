#ifndef SCIFIR_BIOLOGY_TAXONOMY_TAXONOMIC_CATEGORY_HPP_INCLUDED
#define SCIFIR_BIOLOGY_TAXONOMY_TAXONOMIC_CATEGORY_HPP_INCLUDED

#include <memory>
#include <string>

using namespace std;

namespace scifir
{
	class taxonomic_category
	{
		public:
			taxonomic_category();
			taxonomic_category(const taxonomic_category&);
			taxonomic_category(taxonomic_category&&);
			explicit taxonomic_category(const string&,const string&,const taxonomic_category&);

			string name;
			string value;
			shared_ptr<taxonomic_category> parent_category;
	};
}

#endif // SCIFIR_BIOLOGY_TAXONOMY_TAXONOMIC_CATEGORY_HPP_INCLUDED
