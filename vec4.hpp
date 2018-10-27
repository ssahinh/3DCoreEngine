#ifndef VEC4_HPP
#define VEC4_HPP

#include <iostream>

namespace math
{
	template<class T>
	class Vec4
	{
	public:

		T x;
		T y;
		T z;
		T w;

		template<typename T>
		Vec4()
			:x(0), y(0), z(0), w(0)
		{
		}
		template<typename T>
		Vec4(T x, T y, T z, T w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}
		// ADDITION
		template<typename T>
		Vec4<T>& operator+(const Vec4<T>& r) const
		{
			Vec4<T> result = *this;
			result += r;
			return result;
		}
		template<typename T>
		Vec4<T>& operator+=(const Vec4<T>& r)
		{
			x += r.x;
			y += r.y;
			z += r.z;
			w += r.w;
			return *this;
		}
		// SUBSTRACTION
		template<typename T>
		Vec4<T>& operator-(const Vec4<T>& r) const
		{
			Vec4<T> result = *this;
			result -= r;
			return result;
		}
		template<typename T>
		Vec4<T>& operator-=(const Vec4<T>& r)
		{
			x -= r.x;
			y -= r.y;
			z -= r.z;
			w -= r.w;
			return *this;
		}
		// MULTIPLY
		template<typename T>
		Vec4<T>& operator*(const Vec4<T>& r) const
		{
			Vec4<T> result = *this;
			result *= r;
			return result;
		}

		template<typename T>
		Vec4<T>& operator*=(const Vec4<T>& r)
		{
			x *= r.x;
			y *= r.y;
			z *= r.z;
			w *= r.w;
			return *this;
		}

		//DIVIDE
		template<typename T>
		Vec4<T>& operator/(const Vec4<T>& r) const
		{
			Vec4<T> result = *this;
			result /= r;
			return result;
		}

		template<typename T>
		Vec4<T>& operator/=(const Vec4<T>& r)
		{
			x /= r.x;
			y /= r.y;
			z /= r.z;
			w /= r.w;
			return *this;
		}

		template<typename T>
		friend std::ostream& operator<<(std::ostream& stream, const Vec4<T>& vector)
		{
			stream << "Vec4: (" << vector.x << ", " << vector.y << ", " << vector.z <<", " << vector.w <<")";
			return stream;
		}

	};

}


#endif