#include "Predator.h"

void Predator::Process()
{
	Coordinate toCoord;
	if (--timeToFeed <= 0)
	{
		AssignCellAt(offset, new Cell(offset));
		Ocean1->SetNumPredators(Ocean1->GetNumPredators() - 1);
		delete this;
	}
	else
	{
		toCoord = GetPreyNeighborCoord();
		if (toCoord != offset)
		{
			Ocean1->SetNumPrey(Ocean1->GetNumPrey() - 1);
			timeToFeed = TimeToFeed;
			MoveFrom(offset, toCoord);
		}
		else
		{
			Prey::Process();
		}
	}
}

Cell* Predator::Reproduce(Coordinate anOffset)
{
	Predator* temp = new Predator(anOffset);
	Ocean1->SetNumPredators(Ocean1->GetNumPredators());
	return /*(Cell*)*/ temp;
}