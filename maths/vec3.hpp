#ifndef VEC3_HPP
#define VEC3_HPP

#include <iostream>

namespace math
{
	template<class T>
	class Vec3
	{
	public:
		
		T x;
		T y;
		T z;

		template<typename T>
		Vec3()
			:x(0), y(0), z(0)
		{
		}
		template<typename T>
		Vec3(T x, T y, T z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
		// ADDITION
		template<typename T>
		Vec3<T>& operator+(const Vec3<T>& r) const
		{
			Vec3<T> result = *this;
			result += r;
			return result;
		}
		template<typename T>
		Vec3<T>& operator+=(const Vec3<T>& r) 
		{
			x += r.x;
			y += r.y;
			z += r.z;
			return *this;
		}
		// SUBSTRACTION
		template<typename T>
		Vec3<T>& operator-(const Vec3<T>& r) const
		{
			Vec3<T> result = *this;
			result -= r;
			return result;
		}
		template<typename T>
		Vec3<T>& operator-=(const Vec3<T>& r)
		{
			x -= r.x;
			y -= r.y;
			z -= r.z;
			return *this;
		}
		// MULTIPLY
		template<typename T>
		Vec3<T>& operator*(const Vec3<T>& r) const
		{
			Vec3<T> result = *this;
			result *= r;
			return result;
		}

		template<typename T>
		Vec3<T>& operator*=(const Vec3<T>& r) 
		{
			x *= r.x;
			y *= r.y;
			z *= r.z;
			return *this;
		}

		//DIVIDE
		template<typename T>
		Vec3<T>& operator/(const Vec3<T>& r) const
		{
			Vec3<T> result = *this;
			result /= r;
			return result;
		}

		template<typename T>
		Vec3<T>& operator/=(const Vec3<T>& r) 
		{
			x /= r.x;
			y /= r.y;
			z /= r.z;
			return *this;
		}

		template<typename T>
		friend std::ostream& operator<<(std::ostream& stream, const Vec3<T>& vector)
		{
			stream << "vec3: (" << vector.x << ", " << vector.y <<  ", " << vector.z << ")";
			return stream;
		}

	};

}


#endif