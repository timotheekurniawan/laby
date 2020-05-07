// play.cpp
// This file includes functions to play the game and play each level of the game
#include <iostream>
#include <fstream>
#include "play.h"
#include "userStruct.h"
#include "laby.h"
#include "levels.h"
#include "congrats.h"
#include "invalidSelection.h"
using namespace std;

// Function to play a certain level. It display the game and asks for input until
// the player ran out of moves or the level is completed. Then it checks if the player
// completed or failed the level. Finally, It stores userSelected's progress 
// (currentLevel, currentMap, currentLimit, currentTravel) in userSelected.username.txt 
// when user decides to quit game.
// Input : - struct of userSelected (pass-by-referenced)
//         - boolean stillPlaying which indicates if the user is still playing
void playCurrentLevel(User &userSelected, bool &stillPlaying)
{
    char selection;

    // The user continues playing if user's currentLimit is bigger than 0 
    // and user hasn't filled out all the spaces in the map
    while (userSelected.currentLimit > 0 && userSelected.currentTravel < spaces[userSelected.currentLevel - 1] && stillPlaying)
    {
        cout << "                      "
             << "Level " << userSelected.currentLevel << "                      " << endl
             << endl;
        buildMap(userSelected.currentMap);
        cout << endl;
        cout << "Moves Remaining: " << userSelected.currentLimit << endl;
        cout << endl;
        getMove(userSelected, stillPlaying);
    }

    // If user completed the game, indicated by all available spaces 
    // has been visited and user's currentLimit is not yet 0
    if (userSelected.currentTravel == spaces[userSelected.currentLevel - 1] && userSelected.currentLimit >= 0)
    {
        // If the user has not finished all 10 levels
        if (userSelected.currentLevel + 1 < 11)
        {
            char selectionList[2] = {'e', 'q'};
            int sizeSelectionList = 2;
            cout << "Level " << userSelected.currentLevel << " Completed!" << endl
                 << endl;
            userSelected.currentLevel += 1;
            userSelected.currentMap = getEmptyMap(userSelected.currentLevel);
            userSelected.currentLimit = getInitialLimit(userSelected.currentLevel);
            userSelected.currentTravel = 1;

            // Loop as long as the selection made by user is invalid
            while (invalidSelection(selectionList, selection, sizeSelectionList))
            {
                cout << "(e) Continue" << endl;
                cout << "(q) Quit" << endl;
                cout << "Select: ";
                cin >> selection;
                cout << endl;

                // If user decides to quit game, save user's progress to .txt file
                if (selection == 'q')
                {
                    string filename = userSelected.username + ".txt";
                    ofstream fout;
                    fout.open(filename);
                    if (fout.fail())
                    {
                        cout << "Error in file opening!" << endl;
                        exit(1);
                    }
                    fout << userSelected.username << " " << userSelected.currentLevel << " " << userSelected.currentMap << " " << userSelected.currentLimit << " " << userSelected.currentTravel << endl;
                    stillPlaying = false;
                    break;
                }

                // If the user decides to continue game
                else if (selection == 'e')
                {
                    playCurrentLevel(userSelected, stillPlaying);
                    break;
                }
                // If user enters neither e or q
                else
                {
                    cout << "---------------- Invalid Selection ----------------" << endl
                         << endl;
                }
            }
        }
        // If user has finished all 10 levels
        else
        {
            userSelected.currentLevel += 1;
            string filename = userSelected.username + ".txt";
            ofstream fout;
            fout.open(filename);
            if (fout.fail())
            {
                cout << "Error in file opening!" << endl;
                exit(1);
            }
            fout << userSelected.username << " " << userSelected.currentLevel << endl;
            fout.close();
            stillPlaying = false;
        }
    }

    // If user fails to complete the level, indicated by not being able to 
    // visit all the available spaces in the map with and user's currentLimit has reached 0
    else if ((userSelected.currentTravel < spaces[userSelected.currentLevel - 1] && userSelected.currentLimit == 0) || userSelected.currentLimit < 0)
    {
        char selectionList[2] = {'e', 'q'};
        int sizeSelectionList = 2;
        userSelected.currentMap = getEmptyMap(userSelected.currentLevel);
        userSelected.currentLimit = getInitialLimit(userSelected.currentLevel);
        userSelected.currentTravel = 1;
        cout << "Level " << userSelected.currentLevel << " failed!" << endl
             << endl;

        // Loop as long as the selection made by user is invalid
        while (invalidSelection(selectionList, selection, sizeSelectionList))
        {
            cout << "(e) Retry" << endl;
            cout << "(q) Quit" << endl;
            cout << "Select: ";
            cin >> selection;
            cout << endl;

            // If user decides to quit game, store user's progress in .txt file
            if (selection == 'q')
            {
                string filename = userSelected.username + ".txt";
                ofstream fout;
                fout.open(filename);
                if (fout.fail())
                {
                    cout << "Error in file opening!" << endl;
                    exit(1);
                }
                fout << userSelected.username << " " << userSelected.currentLevel << " " << userSelected.currentMap << " " << userSelected.currentLimit << " " << userSelected.currentTravel << endl;
                fout.close();
                stillPlaying = false;
                break;
            }
            // If user decides to retry level
            else if (selection == 'e')
            {
                playCurrentLevel(userSelected, stillPlaying);
                break;
            }
            // If user enters neither e or q
            else
            {
                cout << "---------------- Invalid Selection ----------------" << endl
                     << endl;
            }
        }
    }
}

// Function to play the game. It calls the function playCurrentLevel
// as long as the player has not finished all 10 levels and is still playing.
// Then, it checks if the player has finished all 10 levels. If the player has
// finished all 10 levels, call the funciton completedGame()
// Input    : - struct of userSelected(pass-by-referenced)
void playGame(User &userSelected)
{
    bool stillPlaying = true;
    while (userSelected.currentLevel < 11 && stillPlaying)
    {
        playCurrentLevel(userSelected, stillPlaying);
    }
    if (userSelected.currentLevel == 11)
    {
        completedGame(userSelected);
    }
    else
    {
        return;
    }
}
