#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "levels.h"
using namespace std;

//DEFINE HEARTS
#define HEART "\xE2\x99\xA5"

// Map of each level in form of string
string maps[10] = {
  "------------------------------------------------------------------X---------------------------------",
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
};

// Move limit of each level
int limits[10] = {100, 200};

// Spaces to be traveled by laby of each level
int spaces[10] = {67, 45};

// Function to get the initial limit of the level
// Input    : - level
// Return   : - the initial limit
int getInitialLimit(int level){
    return limits[level-1];
}

// Function to get the initial available spaces of the level
// Input    : - level
// Return   : - the initial available spaces
int getInitialSpace(int level){
    return spaces[level-1];
}

// Function to randomize the starting position of Laby
// in the map then update it to the map. This function
// is used when starting or restarting level
// Input    : - map (pass by referenced)
void randomizeStartPos(string &map){
    srand(time(NULL));
    int startPos;
    while (true)
    {
        startPos = rand() % 100;
        if (map.substr(startPos, 1) == "-")
        {
            map.replace(startPos, 1, "*");
            break;
        }
    }
    return;
}

// Function to randomize the position of heart
// in the map then update it to the map. This function
// is used when starting or restarting level
// Input    : - map (pass by referenced)
void randomizeHeartPos(string &map){
    srand(time(NULL));
    int heartPos;
    while (true)
    {
        heartPos = rand() % 100;
        if (map.substr(heartPos, 1) == "-")
        {
            map.replace(heartPos, 1, "*");
            break;
        }
    }
    return;
}

// Function to get the empty map of the level
// Input    : - level
// Return   : - the empty map
string getEmptyMap(int level){
    string map = maps[level-1];
    randomizeStartPos(map);
    randomizeHeartPos(map);
    return map;
}

// Function to output the map in grids
// Input    : - map
void buildMap(string map){
    string line;
    for (int i = 0; i < 10; ++i)
    {
        for (int a = 0; a < 10; ++a)
        {
            cout << " -";
        }
        cout << endl;
        line = map.substr(i * 10, 10);                      // Get each line. i * 10 to get index 0, 10, and so on.
        for (int b = 0; b < 10; ++b)
        {
            cout << "|" << line.substr(b, 1);
        }
        cout << "|" << endl;
    }
    for (int a = 0; a < 10; ++a)
    {                                                     // Print last line
        cout << " -";
    }    
    cout << endl;                     
}
