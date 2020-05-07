// congrats.cpp
// This file contains the function when a player finishes all 10 levels of the game

#include <iostream>
#include <fstream>
#include "congrats.h"
#include "userStruct.h"
#include "levels.h"
#include "play.h"
#include "invalidSelection.h"
using namespace std;

// Function when a user has finished all 10 levels.
// It displays congratulation message and asks the user whether to restart the game or quit the game.
// - If the user restarts game, it resets user's game progress(currentLevel, currentMap,
//   currentLimit, and currentTravel) to level 1 then playGame(username) to play the game again.
// - If the user quits game, the user's game progress (currentLevel, currentMap,
//   currentLimit, and currentTravel) is stored in username.txt.
// Input    : - struct of userSelected (pass by referenced)
void completedGame(User &userSelected)
{
    char selectionList[2] = {'1', '2'};
    char selection = '0';
    int sizeSelectionList = 2;
    string filename = userSelected.username + ".txt";
    ofstream fout;
    fout.open(filename);
    cout << "Congratulations. You have completed all the levels!" << endl;

    // Loop as long as the selection made by user is invalid
    while (invalidSelection(selectionList, selection, sizeSelectionList))
    {
        cout << "(1) Restart Game" << endl;
        cout << "(2) Quit Game" << endl;
        cout << "Selection: " << endl;
        cin >> selection;

        // If the user choose to Restart Game
        if (selection == '1')
        {
            userSelected.currentLevel = 1;
            userSelected.currentMap = getEmptyMap(userSelected.currentLevel);
            userSelected.currentLimit = getInitialLimit(userSelected.currentLevel);
            userSelected.currentTravel = 1;
            fout << userSelected.username << " " << userSelected.currentLevel << " " << userSelected.currentMap << " " << userSelected.currentLimit << " " << userSelected.currentTravel;
            fout.close();
            playGame(userSelected);
            break;
        }
        // If the user choose to Quit Game
        else if (selection == '2')
        {
            userSelected.currentLevel = 11;
            fout << userSelected.username << " " << userSelected.currentLevel << " " << userSelected.currentMap << " " << userSelected.currentLimit << " " << userSelected.currentTravel;
            fout.close();
            break;
        }
        else
        {
            cout << endl
                 << "---------------- Invalid Selection ----------------" << endl
                 << endl;
        }
    }
}
