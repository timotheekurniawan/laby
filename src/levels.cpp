// levels.cpp
// This file contains functions relating to the levels of the game

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "levels.h"
using namespace std;

// Define the symbols used in printing the Map
#define HEART "\xE2\x99\xA5"
#define UNAVAILABLE "\xe2\x96\x88"
#define LABY "\xe2\x98\x85"
#define VISITED "\xe2\x97\xa6"

// An array storing maps of levels in the game in form of string
string maps[10] = {
    "--XXXXXXXX----XXXXXX------XXXX--------XX-------------------X-------XXX-----XXXXX---XXXXXXX-XXXXXXXXX",
    "XXXXXXXXXX---------X-X-XX-X----X---------X-XX-X-X-----X-X-X-------X-X--X---XX-X--XX-----X-XXXXXXXXXX",
    "---XXXX----X-XXXX-X---------X-XX-XX---X----XX-XXX--X-XX------X-XXXXX---X-----X---XXXXX-X---------X--",
    "XX----XXXXXX-X----XXXX------XXXXXX--XXXXXXXX--XXXX--XX--XX-----X--X---X--------XXX---X--XXXXXX--XXXX",
    "X---X----X--------------X-X-X-----------------X----X-------X------------X-------X-------XXXXX----XXX",
    "XXXX--XXXXXXXX--XXXXXX------XXX--------XX---X-----X---X-X---------X-----X-----------------XX-----X--",
    "X---X-------X---XX-----------X--X----X--X-X--X---------XXX-X-XXX-X------------X---XX-XX-----XX-----X",
    "X--------X----XX------XXXXXX---XX----XX---X-XX-X--X--------XX---XX---XXX------XX---XXXX-------XX----",
    "-----XXXXX-XX---XX---X----X-------------XX------X-XXXXX-X---------XXX--XXXX-XXX--XXXX-X---------X---",
    "XXX------X----XXXX-X--X----X-X--X-XX---XX-X--XXXXX--XX-------X--X-XX---X--X-XX------X-----XXX------X"};

// An array storing the move limit of each level
int limits[10] = {65, 115, 75, 75, 145, 100, 125, 105, 120, 85};

// An array storing the spaces to be traveled by laby of each level
int spaces[10] = {55, 57, 61, 48, 81, 68, 73, 66, 64, 62};

// Function to get the initial limit of the level
// Input    : - level
// Output   : - the initial limit
int getInitialLimit(int level)
{
    return limits[level - 1];
}

// Function to get the initial available spaces of the level
// Input    : - level
// Output   : - the initial available spaces
int getInitialSpace(int level)
{
    return spaces[level - 1];
}

// Function to randomize the starting position of Laby
// in the map then update it to the map. This function
// is used when starting or restarting level
// Input    : - map (pass by referenced)
void randomizeStartPos(string &map)
{
    srand(time(NULL));
    int startPos;
    while (true)
    {
        startPos = rand() % 100;
        if (map.substr(startPos, 1) == "-")
        {
            map.replace(startPos, 1, "L");
            break;
        }
    }
    return;
}

// Function to randomize the position of heart
// in the map then update it to the map. This function
// is used when starting or restarting level or when a heart is obtained
// Input    : - map (pass by referenced)
void randomizeHeartPos(string &map)
{
    srand(time(NULL));
    int heartPos;
    while (true)
    {
        heartPos = rand() % 100;
        if (map.substr(heartPos, 1) == "-") // The pos to be a heart is originally unvisited
        {
            map.replace(heartPos, 1, "h");
            break;
        }
        if (map.substr(heartPos, 1) == "V") // The pos to be a heart is originally already visited
        {
            map.replace(heartPos, 1, "H");
            break;
        }
    }
    return;
}

// Function to get the empty map of the level
// Input    : - level
// Return   : - the empty map
string getEmptyMap(int level)
{
    string map = maps[level - 1];
    randomizeStartPos(map);
    randomizeHeartPos(map);
    return map;
}

// Function to output the map in grids
// Input    : - map
void buildMap(string map)
{
    string line;
    for (int i = 0; i < 10; ++i)
    {
        cout << "               "; // Output indent
        for (int a = 0; a < 10; ++a)
        {
            cout << " -";
        }
        cout << endl;
        line = map.substr(i * 10, 10); // Get each line. i * 10 to get index 0, 10, and so on.
        cout << "               ";
        for (int b = 0; b < 10; ++b)
        {
            cout << "|";
            if (line.substr(b, 1) == "-")
            {
                cout << " ";
            }
            else if (line.substr(b, 1) == "X")
            {
                cout << UNAVAILABLE;
            }
            else if (line.substr(b, 1) == "L")
            {
                cout << LABY;
            }
            else if (line.substr(b, 1) == "V")
            {
                cout << VISITED;
            }
            else if (line.substr(b, 1) == "H" || line.substr(b, 1) == "h")
            {
                cout << HEART;
            }
        }
        cout << "|" << endl;
    }
    cout << "               ";
    for (int a = 0; a < 10; ++a) // Print last line
    {
        cout << " -";
    }
    cout << endl;
}
