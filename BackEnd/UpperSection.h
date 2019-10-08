#pragma once
#include "SheetSection.h"
#include "NumSpot.h"
class UpperSection :
	public SheetSection
{
public:
	int bonus;
	UpperSection() : SheetSection(6)
	{
		spots.at(0) = new NumSpot(1);
		spots.at(1) = new NumSpot(2);
		spots.at(2) = new NumSpot(3);
		spots.at(3) = new NumSpot(4);
		spots.at(4) = new NumSpot(5);
		spots.at(5) = new NumSpot(6);
		bonus = 0;
		minBonus = 63;
		bonusValue = 35;
	}
	int getScore()
	{
		return score + bonus;
	}
	bool scratch(int p, int dice[5])
	{
		SheetSpot* t = spots.at(p);
		if (!t->taken)
		{
			score += t->points(dice);
			t->Strike();
			CheckBonus();
			return true;
		}
		return false;
	}
	std::string Display()
	{
		return "Section score = " + std::to_string(score) + "\nBonus minimum is 63\nSectionBonus = " + std::to_string(bonus) + '\n';
	}
private:
	int minBonus;
	int bonusValue;
	void CheckBonus()
	{
		if (score >= minBonus)
		{
			bonus = bonusValue;
		}
	}
};

