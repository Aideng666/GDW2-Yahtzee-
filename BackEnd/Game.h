#pragma once
#include "Dice.h"
#include "GenPlayer.h"
#include "BotPlayer.h"
#include "HumPlayer.h"
class Game
{
public:
	Dice dice;
	std::vector<GenPlayer*> players;
	void Setup(std::vector<int> c, std::vector<std::string> n)
	{
		players.resize(c.size());
		std::cout << '\n';
		for (int i = 0; i < c.size(); i++)
		{
			switch (c.at(i))
			{
			case 1:
				players.at(i) = new HumPlayer(dice, n.at(i));
				std::cout << 'p' << i + 1 << ", " << n.at(i) << ", is a human.\n";
				break;
			default:
				players.at(i) = new BotPlayer(dice, n.at(i));
				std::cout << 'p' << i + 1 << ", " << n.at(i) << ", is a bot.\n";
				break;
			}
		}
		std::cout << '\n';
	}
	void Setup()
	{
		std::vector<int> r;
		std::vector<std::string> n;
		bool cont(false);
		std::string s;
		int t = 0;
		std::cout << "Thank you for playing yahtzee!";
		while (!cont)
		{
			std::cout << "\nHow many players will be playing? - ";
			std::cin >> s;
			try
			{
				t = std::stoi(s);
				if (t > 0)
				{
					cont = true;
				}
				else
				{
					std::cout << "Please input an int greater than zero.";
				}
			}
			catch (std::invalid_argument& e)
			{
				std::cout << "Please input an int.";
			}
		}
		r.resize(t);
		n.resize(t);
		for (int i = 0; i < r.size(); i++)
		{
			cont = false;
			while (!cont)
			{
				std::cout << "If you would like player " << i + 1 << " to be a human player please input 1.\nOtherwise input any other int for a bot. - ";
				std::cin >> s;
				try
				{
					t = std::stoi(s);
					r.at(i) = t;
					std::cout << "What is this players name? - ";
					std::cin >> n.at(i);
					cont = true;
				}
				catch (std::invalid_argument& e)
				{
					std::cout << "Please input an int.\n";
				}
			}
		}
		Setup(r, n);
	}
	void Play()
	{
		bool end(false);
		int turnNum(0);
		while (!end)
		{
			for (int i = 0; i < players.size(); i++)
			{
				players.at(i)->takeTurn(i, turnNum);
			}
			for (int i = 0; i < players.size(); i++)
			{
				if (players.at(i)->scoreSheet.done)
					end = true;
			}
			turnNum++;
		}
		std::cout << "Game Over In " << turnNum << " Turns.\n\n";
		for (int i = 0; i < players.size(); i++)
		{
			players.at(i)->scoreSheet.getScore();
			std::cout << "Player " << i + 1 << ", " << players.at(i)->name << ", got a score of " << players.at(i)->scoreSheet.score << "!\n";
		}
		std::string z;
		std::cin >> z;
	}
	Game() { dice = Dice(); }
};

