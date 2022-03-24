#include "Cell.h"
#include <iostream>
Cell* Cell::GetCellAt(Coordinate aCoord)
{
	return Ocean1->cells[aCoord.GetY()][aCoord.GetX()];
}

void Cell::AssignCellAt(Coordinate aCoord, Cell* aCell)
{
	Ocean1->cells[aCoord.GetY()][aCoord.GetX()] = aCell;
}

Cell* Cell::GetNeighborWithImage(char anImage)
{
	Cell* neighbors[4];
	int count = 0;

	if (North()->GetImage() == anImage)
	{
		neighbors[count++] = North();
	}

	if (South()->GetImage() == anImage)
	{
		neighbors[count++] = South();
	}

	if (East()->GetImage() == anImage)
	{
		neighbors[count++] = East();
	}

	if (West()->GetImage() == anImage)
	{
		neighbors[count++] = West();
	}

	if (count == 0)
	{
		return this;
	}
	else
	{
		return neighbors[Ocean1->random.NextIntBetween(0, count - 1)];
	}
}

Coordinate Cell::GetEmptyNeighborCoord()
{
	return GetNeighborWithImage(DefaultImage)->GetOffset();
}

Coordinate Cell::GetPreyNeighborCoord()
{
	return GetNeighborWithImage(DefaultPreyImage)->GetOffset();
}

Cell* Cell::North()
{
	int yvalue = (offset.GetY() > 0) ? (offset.GetY() - 1) : (Ocean1->numRows - 1);
	return Ocean1->cells[yvalue][offset.GetX()];
}

Cell* Cell::South()
{
	int yvalue = (offset.GetY()+1) % (Ocean1->numRows);
	return Ocean1->cells[yvalue][offset.GetX()];
}

Cell* Cell::East()
{
	int xvalue = (offset.GetX()+1) % (Ocean1->numCols);
	return Ocean1->cells[offset.GetY()][xvalue];
}

Cell* Cell::West()
{
	int xvalue = (offset.GetX() > 0) ? (offset.GetX() - 1) : (Ocean1->numCols - 1);
	return Ocean1->cells[offset.GetY()][xvalue];
}

Cell* Cell::Reproduce(Coordinate anOffset)
{
	return new Cell(anOffset);;
}

void Cell::Display()
{
	std::cout << image;
}