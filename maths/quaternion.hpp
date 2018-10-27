#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include "vec3.hpp"
#include "vec4.hpp"

namespace math
{
	template<class T>
	class Quaternion
	{
	public:
		T x;
		T y;
		T z;
		T w;

		template<typename T>
		Quaternion()
			: x(0), y(0), z(0), w(0)
		{}

		template<typename T>
		Quaternion(const Quaternion<T>& quaternion)
		{
		}

		template<typename T>
		Quaternion(T x, T y, T z, T w)
		{
		}

		template<typename T>
		Quaternion(const Vec3<T>& xyz, T w) {}

		template<typename T>
		Quaternion(const Vec4<T>& vec) {}

		template<typename T>
		Quaternion(T scalar) { }

		template<typename T>
		Quaternion<T>& operator=(const Quaternion<T>& quaternion) const {}

		template<typename T>
		Quaternion<T>& SetXYZ(const Vec3<T>& vec) {}

		template<typename T>
		const Quaternion<T>& GetXYZ() const {}

		tmeplate
	};

}

#endif