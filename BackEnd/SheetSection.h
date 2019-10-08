#pragma once
#include <vector>
#include "SheetSpot.h"
class SheetSection
{
public:
	int score;
	std::vector<SheetSpot*> spots;
	SheetSection(int s)
	{
		spots.resize(s);
		score = 0;
	}
	virtual int getScore()
	{
		return score;
	}
	virtual bool scratch(int p, int dice[5])
	{
		SheetSpot* t = spots.at(p);
		if (!t->taken)
		{
			score += t->points(dice);
			t->Strike();
			return true;
		}
		return false;
	}
	void ShutDown()
	{
		for (int i = 0; i < spots.size(); i++)
		{
			delete(spots.at(i));
		}
	}
	virtual std::string Display()
	{
		return "Section score = " + std::to_string(score) + '\n';
	}
};

