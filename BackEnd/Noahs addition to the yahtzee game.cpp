// Noahs addition to the yahtzee game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Game.h"
#include <iostream>
#include <ctime>
#include <string>
Game game;
int main()
{
	srand(unsigned(time(NULL)));
	
	game = Game();
	game.Setup();
	game.Play();
}