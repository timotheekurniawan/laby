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
  "------------------------------------------------------------------X---------------------------------"
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
};

// Move limit of each level
int limits[10] = {100, 200};

// Spaces to be traveled by laby of each level
int spaces[10] = {67, 45};

// Function to get the empty map of the level
// Input    : - level
// Return   : - the empty map
string getEmptyMap(int level){
  return maps[level-1];
}

// Function to get the initial limit of the level
// Input    : - level
// Return   : - the initial limit
int getInitialLimit(int level){
  return limits[level-1];
}

// Function to randomize the position of heart
// in the map then update it to the map. This function
// is used when starting or restarting level
// Input    : - map (pass by referenced)
void randomizeHeartPos(string &map){
  srand(time(NULL));
  int heartPos = rand() % 100;
  map.replace(heartPos, 1, HEART);
}

// Function to randomize the starting position of Laby
// in the map then update it to the map. This function
// is used when starting or restarting level
// Input    : - map (pass by referenced)
void randomizeStartPos(string &map){
  srand(time(NULL));
  int startPos = rand() % 100;
  map.replace(startPos, 1, HEART);
}

// Function to output the map in grids.
// Input    : - map
void buildMap(string map){
  string line;
  for (int i = 0; i < 10; ++i){
    for (int a = 0; a < 10; ++a){
      cout << " -";
    }
    cout << endl;
    line = map.substr(i * 10, 10);                      // get each line. i * 10 to get index 0, 10, and so on.
    for (int b = 0; b < 10; ++b){
      cout << "|" << line.substr(b, 1);
    }
    cout << "|" << endl;
  }
  for (int a = 0; a < 10; ++a){                         // Print last line
    cout << " -";
  }    
  cout << endl;                     
}

int main(){
  string s = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
  buildMap(s);
}
// int main(){
//   for (int i = 0; i < 10; ++i){
//     cout << " -";
//   }
//   cout << endl;
//   for (int j = 0; j < 11; ++j){
//     cout << "| ";
//   }
//   cout << endl;
//   for (int i = 0; i < 10; ++i){
//     cout << " -";
//   }
//   cout << endl;
//   for (int j = 0; j < 11; ++j){
//     cout << "| ";
//   }
//   cout << endl;
//   for (int i = 0; i < 10; ++i){
//     cout << " -";
//   }
//   cout << endl;
//   for (int j = 0; j < 11; ++j){
//     cout << "| ";
//   }
//   cout << endl;
//   for (int i = 0; i < 10; ++i){
//     cout << " -";
//   }
//   cout << endl;
//   for (int j = 0; j < 11; ++j){
//     cout << "| ";
//   }
//   cout << endl;
//   for (int i = 0; i < 10; ++i){
//     cout << " -";
//   }
//   cout << endl;
//   for (int j = 0; j < 11; ++j){
//     cout << "| ";
//   }
//   cout << endl;
//   for (int i = 0; i < 10; ++i){
//     cout << " -";
//   }
//   cout << endl;
//   for (int j = 0; j < 11; ++j){
//     cout << "| ";
//   }
//   cout << endl;
//   for (int i = 0; i < 10; ++i){
//     cout << " -";
//   }
//   cout << endl;
//   for (int j = 0; j < 11; ++j){
//     cout << "| ";
//   }
//   cout << endl;
//   for (int i = 0; i < 10; ++i){
//     cout << " -";
//   }
//   cout << endl;
//   for (int j = 0; j < 11; ++j){
//     cout << "| ";
//   }
//   cout << endl;
//   for (int i = 0; i < 10; ++i){
//     cout << " -";
//   }
//   cout << endl;
//   for (int j = 0; j < 11; ++j){
//     cout << "| ";
//   }
//   cout << endl;
//   for (int i = 0; i < 10; ++i){
//     cout << " -";
//   }
//   cout << endl;
//   for (int j = 0; j < 11; ++j){
//     cout << "| ";
//   }
//   cout << endl;
//   for (int i = 0; i < 10; ++i){
//     cout << " -";
//   }
//   cout << endl;
// }