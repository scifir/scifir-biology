#ifndef SCIFIR_BIOLOGY_CELLS_TISSUE_HPP
#define SCIFIR_BIOLOGY_CELLS_TISSUE_HPP

#include "./cell.hpp"

#include <string>
#include <vector>

using namespace std;

namespace scifir
{
    class tissue
	{
		public:
			tissue();
            tissue(const tissue&);
            tissue(tissue&&);

            vector<cell> cells;
	};
}

ostream& operator <<(ostream&,const scifir::tissue&);

#endif // SCIFIR_BIOLOGY_CELLS_TISSUE_HPP