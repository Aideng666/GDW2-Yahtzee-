#pragma once
#include"Game.h";
#include <iostream>;
#include <ctime>;
#include <string>;
using namespace std;
class TitleScreen
{
public:
	void Title() {
		Game game;
		int select(0);
		cout << "Welcome to:\n" << " | __   __    _     _ | \n";
		cout << "|	    \\ \\ / /   | |   | |                       |\n";
		cout << "|	     \\ V /__ _| |__ | |_ _______  ___         |\n";
		cout << "|	      \\ // _` | '_ \\| __|_  / _ \\/ _ \\        |\n";
		cout << "|	      | | (_| | | | | |_ / /  __/  __/        |\n";
		cout << "|	      \\_/\\__,_|_| |_|\\__/___\\___|\\___|        |\n";
		cout << "1. Start Game\n2. Rules\n3. End Game"
			cin >> select;
		while (count = 0, count < 1) {
			if (select == 1) {
				srand(unsigned(time(NULL)));

				game = Game();
				game.Setup();
				game.Play();
				count = 1;
			}
			else if (select == 2) {
				cout << "Yahtzee is fairly simple in concept, but can sometimes be a little hard to explain.\nTo win in Yahtzee, players compete to get a higher score than each other,\nWhich is done by rolling dice to get certain patterns and sets of dice, very similarly to Poker.\nYahtzee is split into 2 sections; the upper and lower sections.\nThe upper section consists of getting as many of a single number on the dice and reaching the bonus minimun of 63 rewards bonus points,\nso be sure to aim for the reward!\n The Lower section contains the poker sets, such as Three/Four-of-a-kind, Full House, and Straights.\nGetting five of the same number is a super rare set called a Yahtzee, and it awards 50 points. getting a Yahtzee again awards the 100 point \"Bonus Yahtzee\"\n If you have no set to take points, you have to scratch a spot and can no longer take points for that spot even if you score it later on.\nYou also have a chance spot, which adds up the points from your roll without needing any pattern. this is a second chance that you get once a game if you mess up a roll.\nOnce all spots have either a score or have been scratched, all players will add together their upper and lower sections together.\nWhoever has the highest score at the end of the game wins!";
			}
			else if (select == 3) {
				cout << "Thank You for using Yahtzee.";
				count = 1;
			}
			else {
				cout << "That is an invalid input, please try again.";
				count = 0;
			}
		}
	}
} 