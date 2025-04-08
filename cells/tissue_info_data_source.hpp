#ifndef SCIFIR_BIOLOGY_CELLS_TISSUE_INFO_DATA_SOURCE_HPP
#define SCIFIR_BIOLOGY_CELLS_TISSUE_INFO_DATA_SOURCE_HPP

#include <map>
#include <string>
#include <vector>

using namespace std;

namespace scifir
{
    class tissue_info_data_source
	{
		public:
            virtual map<string,float> get_percentage_cell_types(const string& tissue_name,int tissue_age) const = 0;
	};
}

#endif // SCIFIR_BIOLOGY_CELLS_TISSUE_INFO_DATA_SOURCE_HPP