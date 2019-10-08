#pragma once
#include "SheetSpot.h"
class CountOfAKindSpot :
	public SheetSpot
{
public: 
	int points(int dice[5])
	{
		if (!taken)
		{
			int t[6]{ 0,0,0,0,0,0 };
			for (int i = 0; i < 5; i++)
			{
				t[dice[i] - 1]++;
			}
			if (t[0] >= val || t[1] >= val || t[2] >= val || t[3] >= val || t[4] >= val || t[5] >= val)
			{
				return (dice[0] + dice[1] + dice[2] + dice[3] + dice[4]);
			}
		}
		return 0;
	}
	CountOfAKindSpot(int v) : SheetSpot((std::to_string(v) + " Of A Kind Spot"))
	{
		val = v;
	}
private:
	int val;
};

