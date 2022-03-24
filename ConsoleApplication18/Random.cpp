#include "Random.h"
#define MAX 32767

float Random::RandReal()
{
	int c;
	static int first = 1;

	if (first == 1)
	{
		seed1 *= 2;
		seed2 *= 2;

		if (seed1 > MAX)
		{
			seed1 -= MAX;
		}

		if (seed2 > MAX)
		{
			seed2 -= MAX;
		}
		first = 0;
		
		for (int index = 1; index <= 30; index++)
		{
			RandReal();
		}
	}

	c = seed1 + seed2;
	
	if (c > MAX)
	{
		c -= MAX;
	}
	c *= 2;
	if (c > MAX)
	{
		c -= MAX;
	}

	seed1 = seed2;
	seed2 = c;
	return (float)c / 32767.0;
}

int Random::NextIntBetween(int low, int high)
{
	float r, t;
	int c;

	r = float(high) - (float)low + 1.0;
	t = r * RandReal();
	c = (int)t;
	return (low + c);
}