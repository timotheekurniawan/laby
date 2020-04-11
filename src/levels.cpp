#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "levels.h"
using namespace std;

//DEFINE HEARTS

string maps[10] = {
  "----------------------------------------------------------------------------------------------------"
  "----------------------------------------------------------------------xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
};

// Move limit of each level
int limits[10] = {100, 200};

// Spaces to be traveled by laby of each level
// kalo dah traveledCount == 67 (misalnya), artinya covered semua
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

void randomizeApplePos(string &map){
  srand(time(NULL));
  int applePos = rand() % 100;
  map.replace(applePos, 1, HEART);
  return;
}

void buildMap(string map){
  randomizeApplePos(map);

}

int main(){
  for (int i = 0; i < 10; ++i){
    cout << " -";
  }
  cout << endl;
  for (int j = 0; j < 11; ++j){
    cout << "| ";
  }
  cout << endl;
  for (int i = 0; i < 10; ++i){
    cout << " -";
  }
  cout << endl;
  for (int j = 0; j < 11; ++j){
    cout << "| ";
  }
  cout << endl;
  for (int i = 0; i < 10; ++i){
    cout << " -";
  }
  cout << endl;
  for (int j = 0; j < 11; ++j){
    cout << "| ";
  }
  cout << endl;
  for (int i = 0; i < 10; ++i){
    cout << " -";
  }
  cout << endl;
  for (int j = 0; j < 11; ++j){
    cout << "| ";
  }
  cout << endl;
  for (int i = 0; i < 10; ++i){
    cout << " -";
  }
  cout << endl;
  for (int j = 0; j < 11; ++j){
    cout << "| ";
  }
  cout << endl;
  for (int i = 0; i < 10; ++i){
    cout << " -";
  }
  cout << endl;
  for (int j = 0; j < 11; ++j){
    cout << "| ";
  }
  cout << endl;
  for (int i = 0; i < 10; ++i){
    cout << " -";
  }
  cout << endl;
  for (int j = 0; j < 11; ++j){
    cout << "| ";
  }
  cout << endl;
  for (int i = 0; i < 10; ++i){
    cout << " -";
  }
  cout << endl;
  for (int j = 0; j < 11; ++j){
    cout << "| ";
  }
  cout << endl;
  for (int i = 0; i < 10; ++i){
    cout << " -";
  }
  cout << endl;
  for (int j = 0; j < 11; ++j){
    cout << "| ";
  }
  cout << endl;
  for (int i = 0; i < 10; ++i){
    cout << " -";
  }
  cout << endl;
  for (int j = 0; j < 11; ++j){
    cout << "| ";
  }
  cout << endl;
  for (int i = 0; i < 10; ++i){
    cout << " -";
  }
  cout << endl;
}