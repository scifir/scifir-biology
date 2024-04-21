#ifndef SCIFIR_BIOLOGY_SPECIES_SPECIES_INFO_HPP
#define SCIFIR_BIOLOGY_SPECIES_SPECIES_INFO_HPP

#include "taxonomic_category.hpp"

#include <string>
#include <vector>

using namespace std;

namespace scifir
{
    class species_info
	{
		public:
			species_info();
            species_info(const species_info&);
            species_info(species_info&&);
			explicit species_info(const taxonomic_category&);

            string get_abbreviated_name(bool) const;
            const string& get_taxonomic_category_value(const string&) const;

            string display_info() const;

			taxonomic_category category;
	};
}

ostream& operator <<(ostream&,const scifir::species_info&);

#endif // SCIFIR_BIOLOGY_SPECIES_SPECIES_INFO_HPP