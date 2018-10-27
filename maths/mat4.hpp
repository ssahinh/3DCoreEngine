#ifndef MAT4_HPP
#define MAT4_HPP

#define GLEW_STATIC
#include <GL/glew.h>

#define _USE_MATH_DEFINES
#include <cmath>

#include "smath.hpp"

namespace math
{

	class Mat4
	{
	public:

		float elements[4 * 4];

		Mat4();
		Mat4(GLfloat diagonal);

		static Mat4 identity();
		
		Mat4& multiply(const Mat4& other);
		friend Mat4 operator*(Mat4 left, const Mat4& right);
		Mat4& operator*=(const Mat4& other);

		static Mat4 orthographic(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);
		static Mat4 perspective(GLfloat fov, GLfloat aspectRatio, GLfloat near, GLfloat far);

		static Mat4 translation(const Vec3<GLfloat>& translation);
		static Mat4 rotation(GLfloat angle, const Vec3<GLfloat>& axis);
		static Mat4 scale(const Vec3<GLfloat>& scale);
		

	};

}

#endif