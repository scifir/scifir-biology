#ifndef SPHERICAL_HPP_INCLUDED
#define SPHERICAL_HPP_INCLUDED

#include "math/number/angle_number.hpp"
#include "coordinates_3d.hpp"

using namespace std;

namespace msci
{
	class spherical_coordinates : public coordinates_3d
	{
		public:
			spherical_coordinates(function<space_type()>, angle_type, angle_type);

			space_type get_r() const;
			const msci::angle_number& get_angle1() const;
			const msci::angle_number& get_angle2() const;

			virtual space_type get_value() const;
			virtual const space_type x_projection() const;
			virtual const space_type y_projection() const;
			virtual const space_type z_projection() const;

		private:
			function<space_type()> r;
			msci::angle_number angle1;
			msci::angle_number angle2;
	};
}

#endif // SPHERICAL_HPP_INCLUDED
