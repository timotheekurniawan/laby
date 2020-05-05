//congrats.cpp
//this file contains the function when a player finishes all 10 levels of the game
//displays congratulations/completion message
#include <iostream>
#include <fstream>
#include "congrats.h"
#include "userStruct.h"
#include "levels.h"
#include "play.h"

using namespace std;

// Function used when a user has finished all 10 levels.
// It displays congratulation message and asks the user whether to restart the game or quit the game.
// - If the user restarts game, it resets user's game progress(currentLevel, currentMap, and currentLimit) to level 1
//   playGame(username) to play the game again.
// - If the user quits game, the user's game progress(currentLevel,currentMap,etc.) is stored in username.txt.
//input: struct of userSelected (pass by referenced)
void completedGame(User &userSelected)
{
    string filename = userSelected.username + ".txt";
    ofstream fout;
    fout.open(filename);
    int selection;
    cout << "Congratulations. You have completed all the levels!" << endl;
    cout << "Would you like to restart?" << endl;
    cout << "1. Restart Game" << endl;
    cout << "2. Quit Game" << endl;
    cout << "Choose (1) or (2)" << endl;
    cout << "Selection: " << endl;
    cin >> selection;
    if (selection == 1)
    {
        userSelected.currentLevel = 1;
        userSelected.currentMap = getEmptyMap(userSelected.currentLevel);
        userSelected.currentLimit = getInitialLimit(userSelected.currentLevel);
        userSelected.currentTravel = 1;
        fout << userSelected.username << " " << userSelected.currentLevel << " " << userSelected.currentMap << " " << userSelected.currentLimit << " " << userSelected.currentTravel;
        fout.close();
        playGame(userSelected);
    }
    else if (selection == 2)
    {
        userSelected.currentLevel = 11;
        fout << userSelected.username << " " << userSelected.currentLevel << " " << userSelected.currentMap << " " << userSelected.currentLimit << " " << userSelected.currentTravel;
        fout.close();
    }
}
