#include "Ocean.h"
#include "Cell.h"
#include "Obstacle.h"
#include "Predator.h"
#include "Prey.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
Ocean* Cell::Ocean1 = NULL;

void Ocean::Initialize()
{
	random.Initialize();
	numRows = MaxRows;
	numCols = MaxCols;
	size = numRows * numCols;

	numObstacles = DefaultNumObstacles;
	numPredators = DefaultNumPredators;
	numPrey = DefaultNumPrey;

	InitCells();
}

void Ocean::InitCells()
{
	AddEmptyCells();

	cout << "\n\nEnter number of obstacles (default = 75): ";
	cout.flush();
	cin >> numObstacles;
	if (numObstacles == size)
	{
		numObstacles = size;
	}
	cout << "\nNumber obstacles accepted = " << numObstacles;
	cout.flush();

	cout << "\n\nEnter number of predators (default = 20): ";
	cout.flush();
	cin >> numPredators;
	if (numPredators == (size - numObstacles))
	{
		numPredators = size - numObstacles;
	}
	cout << "\nNumber predators accepted = " << numPredators;
	cout.flush();

	cout << "\n\nEnter number of prey (default = 150): ";
	cout.flush();
	cin >> numPrey;
	if (numPrey == (size - numObstacles - numPredators))
	{
		numPrey = size - numObstacles - numPredators;
	}
	cout << "\nNumber prey accepted = " << numPrey << "\n\n";
	cout.flush();

	AddObstacles();
	AddPredators();
	AddPrey();
	DisplayStats(-1);
	DisplayCells();
	DisplayBorder();

	Cell::Ocean1 = this;

}

void Ocean::AddEmptyCells()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			Coordinate temp(col, row);
			cells[row][col] = new Cell(temp);
		}
	}
}

void Ocean::AddObstacles()
{
	Coordinate empty;
	for (int count = 0; count < numObstacles; count++)
	{
		empty = GetEmptyCellCoord();
		cells[empty.GetY()][empty.GetX()] = new Obstacle(empty);
	}
}

void Ocean::AddPredators()
{
	Coordinate empty;
	for (int count = 0; count < numPredators; count++)
	{
		empty = GetEmptyCellCoord();
		cells[empty.GetY()][empty.GetX()] = new Predator(empty);
	}
}

void Ocean::AddPrey()
{
	Coordinate empty;
	for (int count = 0; count < numPrey; count++)
	{
		empty = GetEmptyCellCoord();
		cells[empty.GetY()][empty.GetX()] = new Prey(empty);
	}
}

Coordinate Ocean::GetEmptyCellCoord()
{
	int x = -1;
	int y = -1;
	Coordinate empty;
	do
	{
		x = random.NextIntBetween(0, numCols - 1);
		y = random.NextIntBetween(0, numRows - 1);
	} while (cells[y][x]->GetImage() != DefaultImage);
	
	empty = cells[y][x]->GetOffset();
	delete cells[y][x];

	return empty;
}

void Ocean::DisplayBorder()
{
	for (int col = 0; col < numCols; col++)
	{
		cout << "*";
	}
	cout << "\n";
}

void Ocean::DisplayCells()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			cells[row][col]->Display();
		}
		cout << "\n";
	}
}



void Ocean::DisplayStats(int iteration)
{
	cout << "\n\n";
	cout << "Iteration number: " << ++iteration;
	cout << "Obstacles: " << numObstacles;
	cout << "Predators: " << numPredators;
	cout << "Prey: " << numPrey << "\n";
	cout.flush();
	DisplayBorder();
}

void Ocean::Run()
{
	int numIterations = DefaultNumIterations;

	cout << endl << endl << "Enter number of iterations (default max = 1000): ";
	cout.flush();
	cin >> numIterations;

	if (numIterations > 1000)
	{
		numIterations = 1000;
	}

	cout << endl << "Number iterations = " << numIterations << endl << "begin run..." << endl;
	cout.flush();

	for (int i = 0; i < numIterations; i++)
	{
		if (numPredators > 0 && numPrey > 0)
		{
			for (int row = 0; row < numRows; row++)
			{
				for (int col = 0; col < numCols; col++)
				{
					cells[row][col]->Process();
				}
			}
			DisplayStats(i);
			DisplayCells();
			DisplayBorder();
			cout.flush();
		}

		cout << endl << endl << "End of Simulation" << endl;
		cout.flush();
	}
}