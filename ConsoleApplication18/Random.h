#pragma once
class Random
{
private:
	int seed1,
		seed2;

public:
	void Initialize()
	{
		seed1 = 3797;
		seed2 = 2117;
	}

	void Init(int s1, int s2)
	{
		seed1 = s1;
		seed2 = s2;
	}

	float RandReal();
	int NextIntBetween(int low, int high);
};

