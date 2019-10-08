#pragma once
#include "SheetSpot.h"
class FullHouseSpot :
	public SheetSpot
{
public:
	int points(int dice[5]) 
	{ 
		if (!taken)
		{
			int t[6]{ 0, 0, 0, 0, 0, 0 };
			for (int i = 0; i < 5; i++)
			{
				t[dice[i] - 1]++;
			}
			if ((t[0] == 2 || t[1] == 2 || t[2] == 2 || t[3] == 2 || t[4] == 2 || t[5] == 2) && (t[0] == 3 || t[1] == 3 || t[2] == 3 || t[3] == 3 || t[4] == 3 || t[5] == 3))
			{
				return 25;
			}
		}
		return 0;
	}
	FullHouseSpot() : SheetSpot(("Full House Spot")) { }
};

