#pragma once
#include "SheetSpot.h"
class ChanceSpot :
	public SheetSpot
{
public:
	int points(int dice[5])
	{
		if (!taken)
			return dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
		return 0;
	}
	ChanceSpot() : SheetSpot(("Chance Spot")) { }
};

