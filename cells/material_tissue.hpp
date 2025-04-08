#ifndef SCIFIR_BIOLOGY_CELLS_MATERIAL_TISSUE_HPP
#define SCIFIR_BIOLOGY_CELLS_MATERIAL_TISSUE_HPP

#include "./tissue.hpp"

#include <string>
#include <vector>

using namespace std;

namespace scifir
{
    class material_tissue : public tissue
	{
		public:
			material_tissue();
            material_tissue(const material_tissue&);
            material_tissue(material_tissue&&);

            
	};
}

ostream& operator <<(ostream&,const scifir::material_tissue&);

#endif // SCIFIR_BIOLOGY_CELLS_MATERIAL_TISSUE_HPP