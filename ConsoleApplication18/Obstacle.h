#include "Predator.h"

#pragma once
class Obstacle : public Cell
{
public:
	Obstacle(Coordinate& aCoord) : Cell(aCoord)
	{
		image = ObstacleImage;
	}

	virtual ~Obstacle() {}

	virtual void Process()
	{
	}
};

