#include "constants.h"
#include "Random.h"
#include "Coordinate.h"

class Cell;
#pragma once
class Ocean
{
	friend class cell;

private:
	
	int size;
	int numPrey;
	int numPredators;
	int numObstacles;

	void InitCells();
	void AddEmptyCells();
	void AddObstacles();
	void AddPredators();
	void AddPrey();
	Coordinate GetEmptyCellCoord();

	void DisplayBorder();
	void DisplayCells();
	void DisplayStats(int iteration);

public:
	Cell* cells[MaxRows][MaxCols];
	Random random;
	int numRows;
	int numCols;

	int GetNumPrey() { return numPrey; }
	int GetNumPredators() { return numPredators; }
	void SetNumPrey(int aNumber) { numPrey = aNumber; }
	void SetNumPredators(int aNumber) { numPredators = aNumber; }
	void Initialize();

	void Run();
};

