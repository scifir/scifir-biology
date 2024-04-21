#include "species_info.hpp"

#include <sstream>

using namespace std;

namespace scifir
{
	species_info::species_info() : category()
	{}

    species_info::species_info(const species_info& x) : category(x.category)
    {}

    species_info::species_info(species_info&& x) : category(move(x.category))
    {}

	species_info::species_info(const taxonomic_category& new_category) : category(new_category)
	{}

    string species_info::get_abbreviated_name(bool single_letter) const
    {
        if (single_letter)
        {
            return get_taxonomic_category_value("genus").at(0) + " " + get_taxonomic_category_value("species");
        }
        else
        {
            return get_taxonomic_category_value("genus") + " " + get_taxonomic_category_value("species");
        }
    }

    const string& species_info::get_taxonomic_category_value(const string& x_taxonomic_category_name) const
    {
        return "";
        /*const taxonomic_category& x_category = get_taxonomic_category(x_taxonomic_category_name);
        return x_category.value;*/
    }

	string species_info::display_info() const
	{
        ostringstream out;
        out << get_abbreviated_name(false) << " (" << get_abbreviated_name(true) << ")" << endl;
        if (category.value != "")
        {
            out << category.get_name() << ": " << category.value << endl;
            shared_ptr<taxonomic_category> current_category = category.child_category;
            while (current_category != nullptr)
            {
                out << current_category->get_name() << ": " << current_category->value << endl;
                current_category = current_category->child_category;
            }
        }
        return out.str();
    }
}

ostream& operator <<(ostream& os,const scifir::species_info& x)
{
    os << x.display_info();
    return os;
}