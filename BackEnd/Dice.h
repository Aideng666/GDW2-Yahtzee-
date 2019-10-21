#pragma once
#include <iostream>
#include <vector>
class Dice
{
public:
	int vals[5];
	void Roll()
	{
		for (int i = 0; i < 5; i++)
		{
			vals[i] = rand() % 6 + 1;
		}

	}
	void Roll(std::vector<bool> v)
	{
		for (int i = 0; i < 5; i++)
		{
			if (v.at(i))
			{
				vals[i] = rand() % 6 + 1;
			}
		}
	}

	void Display()
	{

		std::string list[7][5];

		for (int i = 0; i < 5; i++) {
			if (vals[i] == 1) {

				list[0][i] = " --------- ";
				list[1][i] = "|         |";
				list[2][i] = "|         |";
				list[3][i] = "|    0    |";
				list[4][i] = "|         |";
				list[5][i] = "|         |";
				list[6][i] = " --------- ";

			}
			else if (vals[i] == 2) {

				list[0][i] = " --------- ";
				list[1][i] = "|         |";
				list[2][i] = "|         |";
				list[3][i] = "| 0     0 |";
				list[4][i] = "|         |";
				list[5][i] = "|         |";
				list[6][i] = " --------- ";
			}
			else if (vals[i] == 3) {

				list[0][i] = " --------- ";
				list[1][i] = "|         |";
				list[2][i] = "|    0    |";
				list[3][i] = "|         |";
				list[4][i] = "| 0     0 |";
				list[5][i] = "|         |";
				list[6][i] = " --------- ";
			}
			else if (vals[i] == 4) {

				list[0][i] = " --------- ";
				list[1][i] = "|         |";
				list[2][i] = "| 0     0 |";
				list[3][i] = "|         |";
				list[4][i] = "| 0     0 |";
				list[5][i] = "|         |";
				list[6][i] = " --------- ";
			}
			else if (vals[i] == 5) {

				list[0][i] = " --------- ";
				list[1][i] = "|         |";
				list[2][i] = "| 0     0 |";
				list[3][i] = "|    0    |";
				list[4][i] = "| 0     0 |";
				list[5][i] = "|         |";
				list[6][i] = " --------- ";
			}
			else if (vals[i] == 6) {

				list[0][i] = " --------- ";
				list[1][i] = "| 0     0 |";
				list[2][i] = "|         |";
				list[3][i] = "| 0     0 |";
				list[4][i] = "|         |";
				list[5][i] = "| 0     0 |";
				list[6][i] = " --------- ";
			}

		} // End of For Loop

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 5; j++) {

				std::cout << list[i][j] << "\t";
			}
			std::cout << std::endl;
		}


	}
};