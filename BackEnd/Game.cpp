// Noahs addition to the yahtzee game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Game.h"
#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include <mmsystem.h>
Game game;
int main()
{
	srand(unsigned(time(NULL)));
	
	PlaySound(TEXT("BootUp.wav"), NULL, SND_FILENAME | SND_ASYNC);
	game = Game();
	game.Setup();
	game.Play();
}