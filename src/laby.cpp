// laby.cpp
// This file contains functions to move the character Laby in the map

#include <iostream>
#include <fstream>
#include "laby.h"
#include "userStruct.h"
#include "levels.h"
#include "invalidSelection.h"
using namespace std;

// Function to move laby to the left and update the data of userSelected
// Input    : - an integer representing the position of Laby in the map
//            - struct of user Selected (pass-by-referenced)
void moveLeft(int labyPos, User &userSelected)
{
    int a = labyPos % 10; //e.g if laby is at index 32, a=2

    //this loop iterates every 1 index before the current index until it hits the left boundary of the map
    //e.g if laby is at index 19, it will check index 18,17,16,.. until index 10
    for (int i = labyPos - 1; i >= labyPos - a; --i)
    {
        if (userSelected.currentTravel == spaces[userSelected.currentLevel - 1])
        {
            break;
        }
        else if (userSelected.currentMap[i] == '-')
        {
            userSelected.currentMap[i] = 'L';
            userSelected.currentMap[i + 1] = 'V';
            userSelected.currentTravel += 1;
            userSelected.currentLimit -= 1;
        }
        else if (userSelected.currentMap[i] == 'V')
        {
            userSelected.currentMap[i] = 'L';
            userSelected.currentMap[i + 1] = 'V';
            userSelected.currentLimit -= 1;
        }
        else if (userSelected.currentMap[i] == 'h')         // the heart is on the block that hasn't been visited
        {
            userSelected.currentMap[i] = 'L';
            userSelected.currentMap[i + 1] = 'V';
            // userSelected.currentLimit+=1; how many currentLimit should be added if heart is obtained?
            userSelected.currentLimit += 5;
            userSelected.currentLimit -= 1;
            userSelected.currentTravel += 1;
            randomizeHeartPos(userSelected.currentMap);
        }
        else if (userSelected.currentMap[i] == 'H')
        {
            userSelected.currentMap[i] = 'L';
            userSelected.currentMap[i + 1] = 'V';
            // userSelected.currentLimit+=1; how many currentLimit should be added if heart is obtained?
            userSelected.currentLimit += 5;
            userSelected.currentLimit -= 1;
            randomizeHeartPos(userSelected.currentMap);
        }
        else if (userSelected.currentMap[i] == 'X')
        {
            break;
        }
    }
}

// Function to move laby to the right and update the data of userSelected
// Input    : - an integer representing the position of Laby in the map
//            - struct of user Selected (pass-by-referenced)
void moveRight(int labyPos, User &userSelected)
{
    int b = labyPos % 10; //e.g. laby is at index 35, so b will be 5
    int a = 9 - b;        //this helps to get the right boundary of the map

    //this loop iterates to every 1 index after the current index until it hits the right boundary of the map
    //e.g laby is at index 0, so it will check index 1,2,3, .. until index 9
    for (int i = labyPos + 1; i <= labyPos + a; ++i)
    {
        if (userSelected.currentTravel == spaces[userSelected.currentLevel - 1])
        {
            break;
        }
        else if (userSelected.currentMap[i] == '-')
        {
            userSelected.currentMap[i] = 'L';
            userSelected.currentMap[i - 1] = 'V';
            userSelected.currentTravel += 1;
            userSelected.currentLimit -= 1;
        }
        else if (userSelected.currentMap[i] == 'V')
        {
            userSelected.currentMap[i] = 'L';
            userSelected.currentMap[i - 1] = 'V';
            userSelected.currentLimit -= 1;
        }
        else if (userSelected.currentMap[i] == 'h')
        {
            userSelected.currentMap[i] = 'L';
            userSelected.currentMap[i - 1] = 'V';
            // userSelected.currentLimit+=1;
            userSelected.currentLimit += 5;
            userSelected.currentLimit -= 1;
            userSelected.currentTravel += 1;
            randomizeHeartPos(userSelected.currentMap);
        }
        else if (userSelected.currentMap[i] == 'H')
        {
            userSelected.currentMap[i] = 'L';
            userSelected.currentMap[i - 1] = 'V';
            // userSelected.currentLimit+=1;
            userSelected.currentLimit += 5;
            userSelected.currentLimit -= 1;
            randomizeHeartPos(userSelected.currentMap);
        }

        else if (userSelected.currentMap[i] == 'X')
        {
            break;
        }
    }
}

// Function to move laby upwards and update the data of userSelected
// Input    : - an integer representing the position of Laby in the map
//            - struct of user Selected (pass-by-referenced)
void moveUp(int labyPos, User &userSelected)
{
    int a = labyPos % 10; //e.g laby is at index 5, then a=5

    //this loop iterates 10 indexes before the current index until it hits the upper boundary of the map
    //e.g. laby is at index 45, it will check index 30,25,.. until index 5
    for (int i = labyPos - 10; i >= a; i -= 10)
    {
        if (userSelected.currentTravel == spaces[userSelected.currentLevel - 1])
        {
            break;
        }
        else if (userSelected.currentMap[i] == '-')
        {
            userSelected.currentMap[i] = 'L';
            userSelected.currentMap[i + 10] = 'V';
            userSelected.currentTravel += 1;
            userSelected.currentLimit -= 1;
        }
        else if (userSelected.currentMap[i] == 'V')
        {
            userSelected.currentMap[i] = 'L';
            userSelected.currentMap[i + 10] = 'V';
            userSelected.currentLimit -= 1;
        }
        else if (userSelected.currentMap[i] == 'h')
        {
            userSelected.currentMap[i] = 'L';
            userSelected.currentMap[i + 10] = 'V';
            // userSelected.currentLimit+=1;
            userSelected.currentLimit += 5;
            userSelected.currentLimit -= 1;           
            userSelected.currentTravel += 1;
            randomizeHeartPos(userSelected.currentMap);
        }
        else if (userSelected.currentMap[i] == 'H')
        {
            userSelected.currentMap[i] = 'L';
            userSelected.currentMap[i + 10] = 'V';
            // userSelected.currentLimit+=1;
            userSelected.currentLimit += 5;
            userSelected.currentLimit -= 1;           
            randomizeHeartPos(userSelected.currentMap);
        }
        else if (userSelected.currentMap[i] == 'X')
        {
            break;
        }
    }
}

// Function to move laby downwards and update the data of userSelected
// Input    : - an integer representing the position of Laby in the map
//            - struct of user Selected (pass-by-referenced)
void moveDown(int labyPos, User &userSelected)
{
    int a = labyPos % 10; //e.g laby is at index 5, a will be 5

    //this loop iterates 10 indexes before the current index until it hits the bottom boundary of the map
    //e.g laby is at index 5, it will check index 15,25,35,.. until index 95
    for (int i = labyPos + 10; i <= (90 + a); i += 10)
    {
        if (userSelected.currentTravel == spaces[userSelected.currentLevel - 1])
        {
            break;
        }
        else if (userSelected.currentMap[i] == '-')
        {
            userSelected.currentMap[i] = 'L';
            userSelected.currentMap[i - 10] = 'V';
            userSelected.currentTravel += 1;
            userSelected.currentLimit -= 1;
        }
        else if (userSelected.currentMap[i] == 'V')
        {
            userSelected.currentMap[i] = 'L';
            userSelected.currentMap[i - 10] = 'V';
            userSelected.currentLimit -= 1;
        }
        else if (userSelected.currentMap[i] == 'h')
        {
            userSelected.currentMap[i] = 'L';
            userSelected.currentMap[i - 10] = 'V';
            userSelected.currentLimit += 5;
            userSelected.currentLimit -= 1;
            userSelected.currentTravel += 1;
            randomizeHeartPos(userSelected.currentMap);
        }

        else if (userSelected.currentMap[i] == 'H')
        {
            userSelected.currentMap[i] = 'L';
            userSelected.currentMap[i - 10] = 'V';
            userSelected.currentLimit += 5;
            userSelected.currentLimit -= 1;
            randomizeHeartPos(userSelected.currentMap);
        }
        else if (userSelected.currentMap[i] == 'X')
        {
            break;
        }
    }
}

// Function to get user input of move selection then move Laby
// respective to the selection and update the data of userSelected
// Input    : - struct of userSelected (pass-by-referenced)
//            - a boolean which indicates if the user is still playing
void getMove(User &userSelected, bool &stillPlaying)
{
    char selectionList[5] = {'w', 'a', 's', 'd', 'q'};
    int sizeSelectionList = 5;
    char move = '0';
    int labyPos = (userSelected.currentMap).find('L'); //to find postion(index) of laby in map represented by a string

    while (invalidSelection(selectionList, move, sizeSelectionList))
    {
        cout << "(w) Up" << endl;
        cout << "(a) Left" << endl;
        cout << "(s) Down" << endl;
        cout << "(d) Right" << endl;
        cout << "(q) Quit and Save Game" << endl;
        cout << "Select: ";
        cin >> move;
        if (move == 'a')
        {
            moveLeft(labyPos, userSelected);
            break;
        }
        else if (move == 'd')
        {
            moveRight(labyPos, userSelected);
            break;
        }
        else if (move == 'w')
        {
            moveUp(labyPos, userSelected);
            break;
        }
        else if (move == 's')
        {
            moveDown(labyPos, userSelected);
            break;
        }
        else if (move == 'q') //if the user decides to quit in the middle of the game, progess will still be saved
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
        else
        {
            cout << endl << "---------------- Invalid Selection ----------------" << endl << endl;
        }
    }
    cout << endl
         << "---------------------------------------------------" << endl
         << endl;
}