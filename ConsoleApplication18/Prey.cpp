#include "Prey.h"

void Prey::MoveFrom(Coordinate from, Coordinate to)
{
	Cell* toCell;
	--timeToReproduce;
	if (to != from)
	{
		toCell = GetCellAt(to);
		delete toCell;
		SetOffset(to);
		AssignCellAt(to, this);
		
		if (timeToReproduce <= 0)
		{
			timeToReproduce = TimeToReproduce;
			AssignCellAt(from, Reproduce(from));
		}
		else
		{
			AssignCellAt(from, new Cell(from));
		}
	}
}

Cell* Prey::Reproduce(Coordinate anOffset)
{
	Prey* temp = new Prey(anOffset);
	Ocean1->SetNumPrey(Ocean1->GetNumPrey() + 1);
	return (Cell*)temp;
}