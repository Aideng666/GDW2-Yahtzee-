#pragma once
#include "GenPlayer.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <mmsystem.h>
class HumPlayer :
	public GenPlayer
{
public:
	HumPlayer(Dice d, std::string n) : GenPlayer(d, n) 
	{
		scoreSheet.done = false;
	}
	void takeTurn(int j, int i)
	{
		scoreSheet.checkdone();
		if (!scoreSheet.done)
		{
			std::string s;
			int t0 = 0;
			int t1 = 0;
			bool cont = false;
			std::cout << "Player " << j + 1 << ", " << name << ", enter anything to play! - ";
			std::string z;
			std::cin >> z;
			PlaySound(TEXT("MenuCursor.wav"), NULL, SND_FILENAME);
			std::cout << std::string(100, '\n');
			std::cout << name << ", Player " << j + 1 << " this is your turn " << i + 1 << "\n\n";

			ShowSheet(true);

			dice.Roll();
			dice.Display();

			while (!cont)
			{
				std::cout << "Would you like to re roll any dice? If yes, enter 1. - ";
				std::cin >> s;
				PlaySound(TEXT("MenuCursor.wav"), NULL, SND_FILENAME);
				try
				{
					t0 = std::stoi(s);
					if (t0 > 0)
					{
						cont = true;
					}
					else
					{
						std::cout << "Please input an int greater than zero.\n";
					}
				}
				catch (std::invalid_argument& e)
				{
					std::cout << "Please input an int.\n";
				}
			}
			if (t0 == 1)
			{
				dice.Roll(GetRolls());
				dice.Display();
				cont = false;

				while (!cont)
				{
					std::cout << "Would you like to re roll any dice? If yes, enter 1. - ";
					std::cin >> s;
					PlaySound(TEXT("MenuCursor.wav"), NULL, SND_FILENAME);
					try
					{
						t1 = std::stoi(s);
						if (t1 > 0)
						{
							cont = true;
						}
						else
						{
							std::cout << "Please input an int greater than zero.\n";
						}
					}
					catch (std::invalid_argument& e)
					{
						std::cout << "Please input an int.\n";
					}
				}
				if (t1 == 1)
				{
					dice.Roll(GetRolls());
					dice.Display();
				}
			}

			ShowSheet(false);

			std::vector<int> r;
			r = GetScratch();
			
			std::cout << "\nYou got " << scoreSheet.sections.at(r.at(0))->spots.at(r.at(1))->points(dice.vals) << " points!\nYour new score is " << scoreSheet.score + scoreSheet.sections.at(r.at(0))->spots.at(r.at(1))->points(dice.vals) << ".\n";
			scoreSheet.sections.at(r.at(0))->scratch(r.at(1), dice.vals);

			AmDone(i);
		}
	}
	std::vector<bool> GetRolls()
	{
		std::vector<bool> reRolls;
		reRolls.resize(5);
		for (int k = 0; k < 5; k++)
		{
			bool cont(false);
			std::string s;
			int t;
			while (!cont)
			{
				std::cout << "Would you like to re roll die number " << k + 1 << "? if so enter one. - ";
				std::cin >> s;
				PlaySound(TEXT("MenuCursor.wav"), NULL, SND_FILENAME);
				try
				{
					t = std::stoi(s);
					cont = true;
				}
				catch (std::invalid_argument& e)
				{
					std::cout << "Please input an int.\n";
				}
			}
			reRolls[k] = t == 1;
		}
		std::cout << '\n';
		return reRolls;
	}
	std::vector<int> GetScratch()
	{
		std::string s;
		std::vector<int> t;
		t.resize(2);
		bool end(false);
		while (!end)
		{
			bool cont(false);
			while (!cont)
			{
				std::cout << "Would you like to claim a spot from section 1 or 2? - ";
				std::cin >> s;
				PlaySound(TEXT("MenuCursor.wav"), NULL, SND_FILENAME);
				try
				{
					t.at(0) = std::stoi(s) - 1;
					if (t.at(0) != 0 && t.at(0) != 1)
					{
						std::cout << "Please input either 1 or 2.\n";
					}
					else
					{
						cont = true;
					}
				}
				catch (std::invalid_argument& e)
				{
					std::cout << "Please input an int.\n";
				}
			}
			cont = !cont;
			while (!cont)
			{
				std::cout << "Would you like to claim spot 1 through " << scoreSheet.sections.at(t.at(0))->spots.size() << "? - ";
				std::cin >> s;
				PlaySound(TEXT("MenuCursor.wav"), NULL, SND_FILENAME);
				try
				{
					t.at(1) = std::stoi(s) - 1;
					if (t.at(1) > -1 && t.at(1) < scoreSheet.sections.at(t.at(0))->spots.size())
					{
						cont = true;
					}
					else
					{
						std::cout << "Please input between 1 and " << scoreSheet.sections.at(t.at(0))->spots.size() << ".\n";
					}
				}
				catch (std::invalid_argument& e)
				{
					std::cout << "Please input an int.\n";
				}
			}
			if (scoreSheet.sections.at(t.at(0))->spots.at(t.at(1))->taken)
			{
				std::cout << "That Spot is already taken!\n";
			}
			else
			{
				end = true;
			}
		}
		return t;
	}
};

