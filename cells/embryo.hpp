#ifndef SCIFIR_BIOLOGY_CELLS_CELL_HPP
#define SCIFIR_BIOLOGY_CELLS_CELL_HPP

#include <string>
#include <vector>

using namespace std;

namespace scifir
{
    class embryo
	{
		public:
			embryo();
            embryo(const embryo&);
            embryo(embryo&&);
	};
}

ostream& operator <<(ostream&,const scifir::cell&);

#endif // SCIFIR_BIOLOGY_CELLS_CELL_HPP