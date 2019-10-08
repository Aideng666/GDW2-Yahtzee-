#pragma once
#include "SheetSpot.h"
class NumSpot :
	public SheetSpot
{
public:
	int points(int dice[5])
	{
		if (!taken)
		{
			int t = 0;
			for (int i = 0; i < 5; i++)
			{
				if (dice[i] == val)
				{
					t += val;
				}
			}
			return t;
		}
		return 0;
	}
	NumSpot(int v) : SheetSpot((std::to_string(v) + " Spot"))
	{
		val = v;
	}
private:
	int val;
};

