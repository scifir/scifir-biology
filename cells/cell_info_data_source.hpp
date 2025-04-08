#ifndef SCIFIR_BIOLOGY_CELLS_CELL_INFO_DATA_SOURCE_HPP
#define SCIFIR_BIOLOGY_CELLS_CELL_INFO_DATA_SOURCE_HPP

#include <string>
#include <vector>

using namespace std;

namespace scifir
{
    class cell_info_data_source
	{
		public:
            virtual long double get_gene_expression(const string& cell_name,int cell_age,const string& gene_name) const = 0;
	};
}

#endif // SCIFIR_BIOLOGY_CELLS_CELL_INFO_DATA_SOURCE_HPP