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

// Function to play a certain level
// randomizeStartPos() is called to place laby in a randomize position in the map
// randomizeHeartPos() is called to place a heart in a randomize position in the map
// getMove() is called for getting user's input on what direction will laby go
// buildMap is called to output the map
// stores userSelected's progress(currentLevel,currentMap,currentLimit,currentTravel) in userSelected.username.txt when user decides to quit game
// Input : - struct of userSelected (pass-by-referenced)
//         - boolean stillPlaying which indicates if the user is still playing
void playCurrentLevel(User &userSelected, bool &stillPlaying)
{
    char selection;

    
    while (userSelected.currentLimit > 0 && userSelected.currentTravel < spaces[userSelected.currentLevel - 1] && stillPlaying)
    {
        cout << "                      " << "Level " << userSelected.currentLevel << "                      " << endl << endl;
        buildMap(userSelected.currentMap);
        cout << endl;
        cout << "Moves Remaining: " << userSelected.currentLimit << endl;
        cout << endl;
        getMove(userSelected, stillPlaying);
    }

    //if user fills out all the empty spaces in the map with 'O' and user's currentLimit is not yet 0
    if (userSelected.currentTravel == spaces[userSelected.currentLevel - 1] && userSelected.currentLimit >= 0)
    {
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
            while (invalidSelection(selectionList, selection, sizeSelectionList))
            {
                cout << "(e) Continue" << endl;
                cout << "(q) Quit" << endl;
                cout << "Select: ";
                cin >> selection;
                cout << endl;
                if (selection == 'q') //if user decides to quit game, save user's progress to .txt file
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
                else if (selection == 'e')
                {
                    playCurrentLevel(userSelected, stillPlaying);
                    break;
                }
                else 
                {
                    cout << "---------------- Invalid Selection ----------------" << endl << endl;
                }
            }
 
        }
        else //finished 10 levels
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
    //if user fails to complete the level, indicated by not being able to fill out all the empty spaces in the map with 'O' when user's currentLimit has reached 0
    else if ((userSelected.currentTravel < spaces[userSelected.currentLevel - 1] && userSelected.currentLimit == 0) || userSelected.currentLimit < 0)
    {
        char selectionList[2] = {'e', 'q'};
        int sizeSelectionList = 2;
        userSelected.currentMap = getEmptyMap(userSelected.currentLevel);
        userSelected.currentLimit = getInitialLimit(userSelected.currentLevel);
        userSelected.currentTravel = 1;
        // cout<<"No moves left!"<<endl;
        cout << "Level " << userSelected.currentLevel << " failed!" << endl
             << endl;
             
        while (invalidSelection(selectionList, selection, sizeSelectionList))
        {
            cout << "(e) Retry" << endl;
            cout << "(q) Quit" << endl;
            cout << "Select: ";
            cin >> selection;
            cout << endl;
            if (selection == 'q') //if user decides to quit game, store user's progress in .txt file
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
            else if (selection == 'e') // if user decides to retry level
            {
                playCurrentLevel(userSelected, stillPlaying);
                break;
            }
            else 
            {
                cout << "---------------- Invalid Selection ----------------" << endl << endl;
            }
        }
        
    }
}

// Function to play the game
//Playcurrentlevel() is called to play a certain level
//CompletedGame() is called to display congratulations message when user succeeds to completed all 10 level
//input: -struct of userSelected
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
