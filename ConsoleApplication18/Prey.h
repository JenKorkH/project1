#include "Cell.h"

#pragma once
class Prey : public Cell
{
protected:
	int timeToReproduce;

	void MoveFrom(Coordinate from, Coordinate to);
	virtual Cell* Reproduce(Coordinate anOffset);

public:
	Prey(Coordinate& aCoord) :Cell(aCoord)
	{
		timeToReproduce = TimeToReproduce;
		image = DefaultPreyImage;
	}

	virtual ~Prey() {}

	virtual void Process()
	{
		Coordinate toCoord;
		toCoord = GetEmptyNeighborCoord();
		MoveFrom(offset, toCoord);
	}
};

