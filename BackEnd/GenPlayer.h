#pragma once
#include "ScoreSheet.h"
#include "Dice.h"
#include <iostream>
class GenPlayer
{
public:
	Dice dice;
	std::string name;
	ScoreSheet scoreSheet;
	GenPlayer(Dice d, std::string n)
	{
		dice = d;
		name = n;
		scoreSheet = ScoreSheet();
		scoreSheet.done = true;
	}
	GenPlayer() { dice = Dice(); }
	virtual void takeTurn(int j,int i) { }
	void ShowSheet(bool state)
	{
		if (state)
		{
			for (int i = 0; i < 2; i++)
			{
				std::cout << "Section " << i + 1 << ")\n";
				std::cout << scoreSheet.sections.at(i)->Display();
				for (int j = 0; j < scoreSheet.sections.at(i)->spots.size(); j++)
				{
					std::cout << j + 1 << ") " << scoreSheet.sections.at(i)->spots.at(j)->name;
					if (scoreSheet.sections.at(i)->spots.at(j)->taken)
						std::cout << " - Taken\n";
					else
						std::cout << " - Open\n";
				}
			}
			scoreSheet.getScore();
			std::cout << "Total Score " << scoreSheet.score << ":\n\n";
		}
		else
		{
			for (int i = 0; i < 2; i++)
			{
				std::cout << "Section " << i + 1 << ")\n";
				std::cout << scoreSheet.sections.at(i)->Display();
				for (int j = 0; j < scoreSheet.sections.at(i)->spots.size(); j++)
				{
					std::cout << j + 1 << ") " << scoreSheet.sections.at(i)->spots.at(j)->name << " - ";
					if (!scoreSheet.sections.at(i)->spots.at(j)->taken)
						std::cout << scoreSheet.sections.at(i)->spots.at(j)->points(dice.vals) << '\n';
					else
						std::cout << "Taken\n";
				}
			}
			scoreSheet.getScore();
			std::cout << "Total Score " << scoreSheet.score << ":\n\n";
		}
	}
	void AmDone(int i)
	{
		scoreSheet.checkdone();
		if (scoreSheet.done)
		{
			std::cout << name << " has finished in " << i + 1 << " turns, with a score of " << scoreSheet.score << "!\n";
		}
		std::cout << '\n';
	}
private:
};

