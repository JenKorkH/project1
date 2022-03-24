#pragma once
class Coordinate
{
private:
	int x;
	int y;

public:
	Coordinate(int aX, int aY):x(aX), y(aY){}
	Coordinate() { x = 0; y = 0; }
	Coordinate(Coordinate& aCoord)
	{
		x = aCoord.x;
		y = aCoord.y;
	}

	~Coordinate(){}
	
	int GetX() { return x; }
	int GetY() { return y; }
	void SetX(int aX) { x = aX; }
	void SetY(int aY) { y = aY; }

	void operator= (const Coordinate& aCoord)
	{
		x = aCoord.x;
		y = aCoord.y;
	}

	int operator== (Coordinate& c)
	{
		return(x == c.x && y == c.y);
	}

	int operator!=(Coordinate& c)
	{
		return(x != c.x || y != c.y);
	}
};

