#include <math.h>

namespace math
{

	inline float toRadians(float degrees)
	{
		return degrees * (M_PI / 180.0f);
	}

}