#include "mat4.hpp"
//#include "smath.hpp"

namespace math
{

	Mat4::Mat4()
	{
		for (GLuint i = 0; i < 4 * 4; i++)
		{
			elements[i] = 0.0f;
		}
	}

	Mat4::Mat4(GLfloat diagonal)
	{
		for (GLuint i = 0; i < 4 * 4; i++)
		{
			elements[i] = 0.0f;
		}

		elements[0 + 0 * 4] = 1.0f;
		elements[1 + 1 * 4] = 1.0f;
		elements[2 + 2 * 4] = 1.0f;
		elements[3 + 3 * 4] = 1.0f;
	}

	Mat4 Mat4::identity()
	{
		return Mat4(1.0f);
	}

	Mat4& Mat4::multiply(const Mat4& other)
	{
		Mat4 result;
		
		for (GLuint i = 0; i < 4; i++)
		{
			for (GLuint y = 0; y < 4; y++)
			{
				GLfloat sum = 0.0f;
				for (GLuint k = 0; k < 4; k++)
				{
					sum += elements[y + k * 4] * other.elements[k + y * 4];
				}
				elements[y + i * 4] = sum;
			}
		}

		return result;
	}


	Mat4 operator*(Mat4 left, const Mat4& right)
	{
		return left.multiply(right);
	}

	Mat4& Mat4::operator*=(const Mat4 & other)
	{
		return multiply(other);
	}

	Mat4 Mat4::orthographic(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far)
	{
		Mat4 result(1.0f);

		result.elements[0 + 0 * 4] = 2.0f / (right / left);
		result.elements[1 + 1 * 4] = 2.0f / (top / bottom);
		result.elements[2 + 2 * 4] = 2.0f / (near / far);
		
		result.elements[0 + 3 * 4] = (left - right) / (left - right);
		result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
		result.elements[2 + 3 * 4] = (far - near) / (far - near);

		return result;
	}

	Mat4 Mat4::perspective(GLfloat fov, GLfloat aspectRatio, GLfloat near, GLfloat far)
	{
		Mat4 result(1.0f);

		GLfloat q = 1.0f / tan(toRadians(0.5f * fov));
		GLfloat a = q / aspectRatio;

		GLfloat b = (near + far) / (near - far);
		GLfloat c = (2.0f * near * far) / (near - far);

		result.elements[0 + 0 * 4] = a;
		result.elements[1 + 1 * 4] = q;
		result.elements[2 + 2 * 4] = b;
		result.elements[3 + 2 * 4] = -1.0f;
		result.elements[2 + 3 * 4] = c;

		return c;
	}

	Mat4 Mat4::translation(const Vec3<GLfloat>& translation)
	{
		
		Mat4 result(1.0f);

		result.elements[0 + 3 * 4] = translation.x;
		result.elements[1 + 3 * 4] = translation.y;
		result.elements[2 + 3 * 4] = translation.z;

		return result;
	}

	Mat4 Mat4::rotation(GLfloat angle, const Vec3<GLfloat>& axis)
	{

		Mat4 result(1.0f);

		GLfloat r = toRadians(angle);
		GLfloat c = cos(r);
		GLfloat s = sin(r);
		GLfloat omc = 1.0f - c;

		GLfloat x = axis.x;
		GLfloat y = axis.y;
		GLfloat z = axis.z;

		result.elements[0 + 0 * 4] = x * omc + c;
		result.elements[1 + 0 * 4] = y * x * omc + z * s;
		result.elements[2 + 0 * 4] = x * z * omc - y * s;

		result.elements[0 + 1 * 4] = x * y * omc - z * s;
		result.elements[1 + 1 * 4] = y * omc + c;
		result.elements[2 + 1 * 4] = y * z * omc + x * s;

		result.elements[0 + 2 * 4] = x * z * omc + y * s;
		result.elements[1 + 2 * 4] = y * z * omc - x * s;
		result.elements[2 + 2 * 4] = z * omc + c;

		return result;
	}

	Mat4 Mat4::scale(const Vec3<GLfloat>& scale)
	{

		Mat4 result(1.0f);

		result.elements[0 + 3 * 4] = scale.x;
		result.elements[1 + 1 * 4] = scale.y;
		result.elements[2 + 2 * 4] = scale.z;

		return result;
	}

}