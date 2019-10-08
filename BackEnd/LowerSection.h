#pragma once
#include "SheetSection.h"
#include "CountOfAKindSpot.h"
#include "StraightSpot.h"
#include "ChanceSpot.h"
#include "YahtzeeSpot.h"
#include "YahtzeeBonusSpot.h"
#include "FullHouseSpot.h"
class LowerSection :
	public SheetSection
{
public:
	LowerSection() : SheetSection(8)
	{
		spots.at(0) = new CountOfAKindSpot(3);
		spots.at(1) = new CountOfAKindSpot(4);
		spots.at(2) = new FullHouseSpot();
		spots.at(3) = new StraightSpot(4);
		spots.at(4) = new StraightSpot(5);
		spots.at(5) = new YahtzeeSpot();
		spots.at(6) = new ChanceSpot();
		spots.at(7) = new YahtzeeBonusSpot(false);
	}
	bool scratch(int p, int dice[5])
	{
		SheetSpot* t = spots.at(p);
		if (!t->taken)
		{
			if (p == 5)
			{
				if (t->points(dice) != 0)
					spots.at(7) = new YahtzeeBonusSpot(true);
			}
			if (p != 7)
			{
				score += t->points(dice);
				t->Strike();
			}
			else
			{
				if (t->points(dice) != 0)
				{
					score += t->points(dice);
				}
				else
				{
					t->Strike();
				}
			}
			return true;
		}
		return false;
	}
};

