#pragma once

namespace MathUtility
{
	template <typename T>
	inline static void Wrap(T& value, T min, T max)
	{
		T range_size = max - min + 1;

		if (value < min)
			value += range_size * ((min - value) / range_size + 1);

		value = min + (value - min) % range_size;
	}

	template <typename T>
	inline static void Clamp(T& value, T min, T max)
	{
		if (value < min)
		{
			value = min;
		}
		else if (value > max)
		{
			value = max;
		}
	}
};