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
		//vals[0] = 4;
		//vals[1] = 2;
		//vals[2] = 1;
		//vals[3] = 3; 
		//vals[4] = 6;
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
	std::string Display()
	{
		std::string t;
		for (int i = 0; i < 5; i++)
		{
			switch (vals[i])
			{
			case 1:
				t += '1';
				break;
			case 2:
				t += '2';
				break;
			case 3:
				t += '3';
				break;
			case 4:
				t += '4';
				break;
			case 5:
				t += '5';
				break;
			case 6:
				t += '6';
				break;
			}
			t += ' ';
		}
		t += '\n';
		return t;
	}
};