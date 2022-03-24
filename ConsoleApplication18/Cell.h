#include "Ocean.h"

#pragma once
class Cell
{
protected:
	static Ocean* Ocean1;
	Coordinate offset;
	char image;

	Cell* GetCellAt(Coordinate aCoord);
	void AssignCellAt(Coordinate aCoord, Cell* aCell);
	Cell* GetNeighborWithImage(char anImage);
	Coordinate GetEmptyNeighborCoord();
	Coordinate GetPreyNeighborCoord();
	Cell* North();
	Cell* South(); 
	Cell* East();
	Cell* West();

	virtual Cell* Reproduce(Coordinate anOffset);

public:
	Cell(Coordinate& aCoord) 
		: offset(aCoord) 
	{ 
		image = DefaultImage; 
	}

	Cell()
	{
		// ...
	}

	virtual ~Cell() 
	{
	}

	Coordinate& GetOffset() 
	{ 
		return offset; 
	}

	void SetOffset(Coordinate& anOffset) { offset = anOffset; }
	char GetImage() { return image; }
	
	Ocean* GetOcean();
	void SetOcean(Ocean*);
	void Display();
	virtual void Process() {}
};

