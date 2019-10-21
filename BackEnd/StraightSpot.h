#pragma once
#include "SheetSpot.h"
class StraightSpot :
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
			bool r = false;
			for (int i = 0; i < 7 - val; i++)
			{
				if (!r)
				{
					bool s = true;
					for (int j = 0; j < val; j++)
					{
						if (s && t[j + i] == 0)
						{
							s = false;
						}
					}
					if (s)
					{
						r = s;
					}
				}
			}
			if (r)
			{
				return (10 * val) - 10;
			}
		}
		return 0;
	}
	StraightSpot(int v) : SheetSpot((std::to_string(v) + " Straight Spot"))
	{
		val = v;
	}
private:
	int val;
};

