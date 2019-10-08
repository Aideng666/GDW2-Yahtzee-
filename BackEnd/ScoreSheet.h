#pragma once
#include <vector>
#include "SheetSection.h"
#include "UpperSection.h"
#include "LowerSection.h"
class ScoreSheet
{
public:
	std::vector<SheetSection*> sections;
	int score;
	bool done;
	ScoreSheet()
	{
		sections.resize(2);
		score = 0;
		done = false;
		sections.at(0) = new UpperSection();
		sections.at(1) = new LowerSection();
	}
	void getScore()
	{
		score = sections.at(0)->getScore() + sections.at(1)->getScore();
	}
	void checkdone()
	{
		bool temp(false);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < sections.at(i)->spots.size(); j++)
			{
				if (!temp)
				{
					if (!sections.at(i)->spots.at(j)->taken)
					{
						temp = true;
					}
				}
			}
		}
		done = !temp;
	}
};

