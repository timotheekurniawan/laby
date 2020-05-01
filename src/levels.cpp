#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "levels.h"
using namespace std;

//DEFINE HEARTS
#define HEART "\xE2\x99\xA5"
// define UNAVAILABLE, LABY, VISITED 

// Map of each level in form of string
string maps[10] = {
"XXXXXXXXXX---------X-X-XX-X----X---------X-XX-X-X-----X-X-X-------X-X--X---XX-X--XX-----X-XXXXXXXXXX",
"---XXXX----X-XXXX-X---------X-XX-XX---X----XX-XXX--X-XX------X-XXXXX---X-----X---XXXXX-X---------X--",
"XX----XXXXXX-X----XXXX------XXXXXX--XXXXXXXX--XXXX--XX--XX-----X--X---X--------XXX---X--XXXXXX--XXXX",
"X---X----X--------------X-X-X-----------------X----X-------X------------X-------X-------XXXXX----XXX",
"XXXX--XXXXXXXX--XXXXXX------XXX--------XX---X-----X---X-X---------X-----X-----------------XX-----X--",
"X---X-------X---XX-----------X--X----X--X-X--X---------XXX-X-XXX-X------------X------XX-----XX-----X",
"-----XXXXX-XX---XX---X----X-------------XX------X-XXXXX-X---------XXX--XXXX-X---------X---XXXXXXXXXX",

};

// Move limit of each level
int limits[10] = {500, 500, 500, 500, 500, 500, 500, 500, 500, 500};

// Spaces to be traveled by laby of each level
int spaces[10] = {57, 61, 47, 81, 68};

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
            map.replace(startPos, 1, "L");
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
            map.replace(heartPos, 1, "H");
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
            cout << "|";
            if (line.substr(b, 1) == "-"){
                cout << " ";
            }
            else if (line.substr(b, 1) == "X"){
                cout << "X";
            }
            else if (line.substr(b, 1) == "L"){
                cout << "L";
            }
            else if (line.substr(b, 1) == "V"){
                cout << "V";
            }
            else if (line.substr(b, 1) == "H"){
                cout << HEART;
            }
        }
        cout << "|" << endl;
    }
    for (int a = 0; a < 10; ++a)
    {                                                     // Print last line
        cout << " -";
    }    
    cout << endl;                     
}
