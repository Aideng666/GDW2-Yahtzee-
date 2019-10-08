#pragma once
#include <iostream>
#include <string>
class SheetSpot
{
public:
	std::string name;
	bool taken;
	virtual int points(int dice[5]) { return 0; }
	SheetSpot(std::string n)
	{
		taken = false;
		name = n;
	}
	void Strike()
	{
		taken = true;
	}
};

