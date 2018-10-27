#ifndef VEC2_HPP
#define VEC2_HPP

#include <iostream>

namespace math
{
	template<class T>
	class Vec2
	{
	public:
		T x;
		T y;

		template<typename T>
		Vec2();

		template<typename T>
		Vec2(T x, T y);
		
		template<typename T>
		Vec2<T>& operator+(const Vec2<T>& r);
		
		
		
		/*
		template<typename T>
		Vec2()
		: x(0), y(0)
		{}
		template<typename T>
		Vec2(T x, T y) { 
			this->x = x;
			this->y = y;
		}

		
		// ADDITION
		template<typename T>
		Vec2<T>& operator+(const Vec2<T>& r)
		{
			x += r.x;
			y += r.y;
			return *this;
		}
		template<typename T>
		Vec2<T>& operator+=(const Vec2<T>& r) const
		{
			x += r.x;
			y += r.y;
		}
		// SUBSTRACTION
		template<typename T>
		Vec2<T>& operator-(const Vec2<T>& r) const
		{
			Vec2<T> result = *this;
			result -= r;
			return result;
		}
		template<typename T>
		Vec2<T>& operator-=(const Vec2<T>& r) 
		{
			x -= r.x;
			y -= r.y;
			return *this;
		}
		// MULTIPLY
		template<typename T>
		Vec2<T>& operator*(const Vec2<T>& r) const
		{
			Vec2<T> result = *this;
			result *= r;
			return result;
		}
		
		template<typename T>
		Vec2<T>& operator*=(const Vec2<T>& r)
		{
			x *= r.x;
			y *= r.y;
			return *this;
		}
		
		//DIVIDE
		template<typename T>
		Vec2<T>& operator/(const Vec2<T>& r) const
		{
			Vec2<T> result = *this;
			result /= r;
			return result;
		}

		template<typename T>
		Vec2<T>& operator/=(const Vec2<T>& r)
		{
			x /= r.x;
			y /= r.y;
			return *this;
		}

		// output
		template<typename T>
		friend std::ostream& operator<<(std::ostream& stream, const Vec2<T>& vector)
		{
			stream << "vec2: (" << vector.x << ", " << vector.y << ")";
			return stream;
		}
		*/
	};
	

}

#endif;
