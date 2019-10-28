#pragma once
#include "SheetSpot.h"
#include <windows.h>
#include <mmsystem.h>
class YahtzeeSpot :
	public SheetSpot
{
public:
	int points(int dice[5])
	{
		if (!taken)
		{
			bool t(true);
			for (int i = 1; i < 5; i++)
			{
				if (t)
					t = dice[i] == dice[i - 1];
			}
			if (t) {
				PlaySound(TEXT("Yahtzee.wav"), NULL, SND_FILENAME);
				return (50);
			}
		}
		return (0);
	}
	YahtzeeSpot() : SheetSpot(("Yahtzee Spot")) { }
};

