#pragma once
#include "SheetSpot.h"

class YahtzeeBonusSpot :
	public SheetSpot
{
public:
	int points(int dice[5])
	{
		if (active)
		{
			if (!taken)
			{
				bool t(true);
				for (int i = 1; i < 5; i++)
				{
					if (t)
						t = dice[i] == dice[i - 1];
				}
				if (t)
					return (100);
			}
		}
		return (0);
	}
	YahtzeeBonusSpot(bool state) : SheetSpot(("Yahtzee Bonus Spot"))
	{
		active = state;
	}
private:
	bool active;
};

