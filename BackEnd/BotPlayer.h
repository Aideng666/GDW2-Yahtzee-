#pragma once
#include "GenPlayer.h"
#include <iostream>
class BotPlayer :
	public GenPlayer
{
public:
	BotPlayer(Dice d, std::string n) : GenPlayer(d, n) { }
	void takeTurn(int j, int i)
	{

		std::cout << "Player " << j + 1 << ", " << name << ", enter anything to play! - ";
		std::string z;
		std::cin >> z;

		std::cout << std::string(100, '\n');
		std::cout << name << ", Bot " << j + 1 << ", will now take turn " << i + 1 << "\n\n";

		ShowSheet(true);

		dice.Roll();
		std::cout << "Dice = " << dice.Display() << '\n';
		dice.Roll(getRolls(dice.vals));
		std::cout << "Dice = " << dice.Display() << '\n';
		dice.Roll(getRolls(dice.vals));
		std::cout << "Dice = " << dice.Display() << '\n';

		ShowSheet(false);

		int p = pickStrike();
		int s = 0;
		int t = 0;
		if (p > 5)
		{
			s = 1;
			t = p - 6;
		}
		else
		{
			s = 0;
			t = p;
		}

		scoreSheet.getScore();
		std::cout << name << " has picked " << scoreSheet.sections.at(s)->spots.at(t)->name << " and got " << scoreSheet.sections.at(s)->spots.at(t)->points(dice.vals) << ",\nthey now have " << scoreSheet.score + scoreSheet.sections.at(s)->spots.at(t)->points(dice.vals) << " points.\n";

		scoreSheet.sections.at(s)->scratch(t, dice.vals);

		AmDone(i);
	}
private:
	const float numScores[6]{ 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
	const float countScores[3]{ 0.5f, 0.55f, 0.6f};
	const float houseScore{ 0.8f };
	const float straightScores[2]{ 0.6f, 0.7f};
	const float chanceScore{ 0.3f };
	const float bias[14]{ 7.0f, 6.0f, 5.0f, 3.0f, 2.0f, 1.0f, 0.5f, 0.75f, 1.0f, 1.5f, 2.0f, 10.0f, 0.7f, 10.0f };
	int pick(int die[5])
	{
		std::vector<float> scores;
		scores.resize(14);
		scores.at(0) = numCheck(die, 1);
		scores.at(1) = numCheck(die, 2);
		scores.at(2) = numCheck(die, 3);
		scores.at(3) = numCheck(die, 4);
		scores.at(4) = numCheck(die, 5);
		scores.at(5) = numCheck(die, 6);
		scores.at(6) = countCheck(die, 3);
		scores.at(7) = countCheck(die, 4);
		scores.at(8) = houseCheck(die);
		scores.at(9) = straightCheck(die, 4);
		scores.at(10) = straightCheck(die, 5);
		scores.at(11) = yahtzeeCheck(die);
		scores.at(12) = chanceCheck();
		scores.at(13) = bonusCheck(die);
		int t = 0;
		float s = 0;
		for (int i = 0; i < 14; i++)
		{
			if (scores.at(i) > s)
			{
				s = scores[i];
				t = i;
			}
		}
		return t;
	}
	float numCheck(int die[5], int num)
	{
		if (!scoreSheet.sections.at(0)->spots.at(num - 1)->taken)
		{
			float t = 0;
			for (int i = 0; i < 5; i++)
			{
				if (die[i] == num)
				{
					t++;
				}
			}
			return ((t / 6) * numScores[num - 1]);
		}
		return 0;
	}
	float countCheck(int die[5], int count)
	{
		if (!scoreSheet.sections.at(1)->spots.at(count - 3)->taken)
		{
			float t = 0;
			int s[6] = { 0, 0, 0, 0, 0, 0 };
			for (int i = 0; i < 5; i++)
			{
				s[die[i] - 1] ++;
			}
			for (int i = 0; i < 6; i++)
			{
				if (t < s[i])
				{
					t = s[i];
				}
			}
			return ((t / count) * countScores[count - 3]);
		}
		return 0;
	}
	float houseCheck(int die[5])
	{
		if (!scoreSheet.sections.at(1)->spots.at(2)->taken)
		{
			float t = 0;
			int s[6] = { 0, 0, 0, 0, 0, 0 };
			for (int i = 0; i < 5; i++)
			{
				s[die[i] - 1] ++;
			}
			if ((s[0] == 2 || s[1] == 2 || s[2] == 2 || s[3] == 2 || s[4] == 2 || s[5] == 2) && (s[0] == 3 || s[1] == 3 || s[2] == 3 || s[3] == 3 || s[4] == 3 || s[5] == 3))
			{
				return houseScore;
			}
			return t;
		}
		return 0;
	}
	float straightCheck(int die[5], int length)
	{
		if (!scoreSheet.sections.at(1)->spots.at(length - 1)->taken)
		{
			float t = 0;
			int s[6] = { 0, 0, 0, 0, 0, 0 };
			for (int i = 0; i < 5; i++)
			{
				s[die[i] - 1] ++;
			}
			for (int i = 0; i < 6; i++)
			{
				if (s[i] == 1)
				{
					t++;
				}
				else if (s[i] > 1)
				{
					t--;
				}
			}
			return ((t / length) * straightScores[length - 4]);
		}
		return 0;
	}
	float yahtzeeCheck(int die[5])
	{
		if (!scoreSheet.sections.at(1)->spots.at(5)->taken)
		{
			float t = 0;
			int s[6] = { 0, 0, 0, 0, 0, 0 };
			for (int i = 0; i < 5; i++)
			{
				s[die[i] - 1] ++;
			}
			for (int i = 0; i < 6; i++)
			{
				if (t < s[i])
				{
					t = s[i];
				}
			}
			return ((t / 5) * countScores[2]);
		}
		return 0;
	}
	float chanceCheck()
	{
		if (!scoreSheet.sections.at(1)->spots.at(6)->taken)
		{
			return chanceScore;
		}
		return 0;
	}
	float bonusCheck(int die[5])
	{
		if (!scoreSheet.sections.at(1)->spots.at(7)->taken && scoreSheet.sections.at(1)->spots.at(5)->taken)
		{
			float t = 0;
			int s[6] = { 0, 0, 0, 0, 0, 0 };
			for (int i = 0; i < 5; i++)
			{
				s[die[i] - 1] ++;
			}
			for (int i = 0; i < 6; i++)
			{
				if (t < s[i])
				{
					t = s[i];
				}
			}
			return ((t / 5) * countScores[2]);
		}
		return 0;
	}
	std::vector<bool> getRolls(int die[5])
	{
		std::vector<bool> t;
		t.resize(5);
		for (int i = 0; i < 5; i++)
		{
			t.at(i) = true;
		}
		switch (pick(die))
		{
		case 0:
		{
			for (int i = 0; i < 5; i++)
			{
				t[i] = die[i] != 1;
			}
			break;
		}
		case 1:
		{
			for (int i = 0; i < 5; i++)
			{
				t[i] = die[i] != 2;
			}
			break;
		}
		case 2:
		{
			for (int i = 0; i < 5; i++)
			{
				t[i] = die[i] != 3;
			}
			break;
		}
		case 3:
		{
			for (int i = 0; i < 5; i++)
			{
				t[i] = die[i] != 4;
			}
			break;
		}
		case 4:
		{
			for (int i = 0; i < 5; i++)
			{
				t[i] = die[i] != 5;
			}
			break;
		}
		case 5:
		{
			for (int i = 0; i < 5; i++)
			{
				t[i] = die[i] != 6;
			}
			break;
		}
		case 6:
		{
			int s[6]{ 0, 0, 0, 0, 0, 0 };
			for (int i = 0; i < 5; i++)
			{
				s[die[i] - 1] ++;
			}
			int r(0);
			int q(0);
			for (int i = 0; i < 6; i++)
			{
				if (r < s[i])
				{
					r = s[i];
					q = i;
				}
			}
			r++;
			for (int i = 0; i < 5; i++)
			{
				t[i] = die[i] != q;
			}
			break;
		}
		case 7:
		{
			int s[6]{ 0, 0, 0, 0, 0, 0 };
			for (int i = 0; i < 5; i++)
			{
				s[die[i] - 1] ++;
			}
			int r(0);
			int q(0);
			for (int i = 0; i < 6; i++)
			{
				if (r < s[i])
				{
					r = s[i];
					q = i;
				}
			}
			r++;
			for (int i = 0; i < 5; i++)
			{
				t[i] = die[i] != q;
			}
			break;
		}
		case 8:
		{
			for (int i = 0; i < 5; i++)
			{
				t[i] = false;
			}
			break;
		}
		case 9:
		{
			int min = 6;
			for (int i = 0; i < 5; i++)
			{
				if (die[i] < min)
				{
					min = die[i];
				}
			}
			bool h[6]{ false, false, false, false, false, false };
			for (int i = 0; i < 5; i++)
			{
				if (!h[die[i] - 1])
				{
					if (die[i] < min + 4)
					{
						h[die[i] - 1] = true;
						t[i] = false;
					}
				}
			}
			break;
		}
		case 10:
		{
			int min = 6;
			for (int i = 0; i < 5; i++)
			{
				if (die[i] < min)
				{
					min = die[i];
				}
			}
			bool h[6]{ 0, 0, 0, 0, 0, 0 };
			for (int i = 0; i < 5; i++)
			{
				if (!h[die[i] - 1])
				{
					if (die[i] < min + 5)
					{
						h[die[i] - 1] = true;
						t[i] = false;
					}
				}
			}
			break;
		}
		case 11:
		{
			int s[6]{ 0, 0, 0, 0, 0, 0 };
			for (int i = 0; i < 5; i++)
			{
				s[die[i] - 1] ++;
			}
			int r(0);
			int q(0);
			for (int i = 0; i < 6; i++)
			{
				if (r < s[i])
				{
					r = s[i];
					q = i;
				}
			}
			r++;
			for (int i = 0; i < 5; i++)
			{
				t[i] = die[i] != r;
			}
			break;
		}
		case 12:
		{
			for (int i = 0; i < 5; i++)
			{
				if (die[i] > 3)
				{
					t[i] = false;
				}
			}
			break;
		}
		case 13:
		{
			int s[6]{ 0, 0, 0, 0, 0, 0 };
			for (int i = 0; i < 5; i++)
			{
				s[die[i] - 1] ++;
			}
			int r(0);
			int q(0);
			for (int i = 0; i < 6; i++)
			{
				if (r < s[i])
				{
					r = s[i];
					q = i;
				}
			}
			r++;
			for (int i = 0; i < 5; i++)
			{
				t[i] = die[i] != r;
			}
			break;
		}
		}
		return t;
	}
	int zeros()
	{
		for (int t = 13; t >= 0; t--)
		{
			int h = 0;
			int k = 0;
			if (t > 5)
			{
				h = 1;
				k = t - 6;
			}
			else
			{
				h = 0;
				k = t;
			}
			if (!scoreSheet.sections.at(h)->spots.at(k)->taken)
			{
				return t;
			}
		}
		return 0;
	}
	int pickStrike()
	{
		float scores[14]{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
		int s = 0;
		int t = 0;
		int r = 0;
		float max = 0;
		for (int i = 0; i < 14; i++)
		{
			if (i > 5)
			{
				s = 1;
				t = i - 6;
			}
			else
			{
				s = 0;
				t = i;
			}
			scores[i] = scoreSheet.sections.at(s)->spots.at(t)->points(dice.vals) * bias[i]; 
			std::cout << scores[i] << '\n';
		}
		std::cout << '\n';
		for (int i = 0; i < 14; i++)
		{
			if (scores[i] > max)
			{
				max = scores[i];
				r = i;
			}
		}
		if (max == 0)
		{
			r = zeros();
		}
		return r;
	}
};

