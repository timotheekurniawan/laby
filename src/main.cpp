// main.cpp
// The main program

#include <iostream>
#include "welcome.h"
#include "play.h"
#include "userStruct.h"
using namespace std;

int main()
{
    User userPlaying = welcome();       // Display welcome page and get the user playing
    playGame(userPlaying);              // Play the game
}