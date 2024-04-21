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
			enum type { TAXONOMY_DOMAIN, KINGDOM, PHYLUM, CLASS, ORDER, FAMILY, GENUS, SPECIES, OTHER, NONE };

			taxonomic_category();
			taxonomic_category(const taxonomic_category&);
			taxonomic_category(taxonomic_category&&);
			explicit taxonomic_category(const taxonomic_category::type&,const string&,const string&,const taxonomic_category&);

			string get_name() const;

			bool is_basal_category() const;

			string value;
			shared_ptr<taxonomic_category> child_category;

		private:
			string custom_type;

		public:
			taxonomic_category::type taxonomic_type;
	};

	string to_string(const taxonomic_category::type&);
}

#endif // SCIFIR_BIOLOGY_TAXONOMY_TAXONOMIC_CATEGORY_HPP_INCLUDED
