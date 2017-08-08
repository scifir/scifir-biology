#ifndef AUTO_SCALAR_HPP_INCLUDED
#define AUTO_SCALAR_HPP_INCLUDED

#include "auto_unit.hpp"
#include "scalar_unit.hpp"

using namespace std;

namespace physics::units
{
	class auto_scalar : public auto_unit, public scalar_unit
	{
		public:
			explicit auto_scalar(math::topology::space_type, string = "");
			explicit auto_scalar(const unit&,string);
			explicit auto_scalar(string);
			auto_scalar(const auto_unit&);
			auto_scalar(const unit&);

			auto_scalar& operator =(const auto_unit&);
			auto_scalar& operator =(auto_unit&&);
			auto_scalar& operator =(const unit&);
	};

	template<typename U, typename>
	auto_scalar scalar_unit::operator +(U y)
	{
		auto_scalar z = *this;
		z += y;
		return z;
	}

	template<typename U, typename>
	auto_scalar scalar_unit::operator -(U y)
	{
		auto_scalar z = *this;
		z -= y;
		return z;
	}

	template<typename U, typename>
	auto_scalar scalar_unit::operator *(U y)
	{
		auto_scalar z = *this;
		z *= y;
		return z;
	}

	template<typename U, typename>
	auto_scalar scalar_unit::operator /(U y)
	{
		auto_scalar z = *this;
		z /= y;
		return z;
	}

	template<typename U, typename>
	auto_scalar scalar_unit::operator ^(U y)
	{
		auto_scalar a = unit::operator^(y);
		return a;
	}
}

#endif // AUTO_SCALAR_HPP_INCLUDED