// Noahs addition to the yahtzee game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
<<<<<<< Updated upstream
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
=======
#include "Game.h";
#include "TitleScreen.h";
#include <iostream>;
#include <ctime>;
#include <string>;
TitleScreen title;
int main()
{
	title.Title();
>>>>>>> Stashed changes
}