#pragma once
#include "SheetSpot.h"
class StraightSpot :
	public SheetSpot
{
public:
	int points(int dice[5])
	{
		if (!taken)
		{
			int t[5]{ 0, 0, 0, 0, 0 };
			int c = 1;
			bool flipFlop(false);
			bool done(false);
			for (int i = 0; i < 5; i++)
			{
				t[i] = dice[i];
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 5 - i - 1; j++)
				{
					if (t[j] > t[j + 1])
					{
						int temp = t[j + 1];
						t[j + 1] = t[j];
						t[j] = temp;
					}
				}
			}
			for (int i = 1; i < 5; i++)
			{
				if (t[i] == t[i - 1] + 1)
				{
					if (!done)
					{
						c++;
						if (!flipFlop)
						{
							flipFlop = !flipFlop;
						}
					}
				}
				else
				{
					if (flipFlop)
					{
						flipFlop = !flipFlop;
						done = !done;
					}
				}
			}
			if (c >= val)
			{
				return (10 * val) - 10;
			}
		}
		return 0;
	}
	StraightSpot(int v) : SheetSpot((std::to_string(v) + " Straight Spot"))
	{
		val = v;
	}
private:
	int val;
};

