// welcome.cpp
// Display welcome message, choose either new or continue game
// Get the user and return it to the main function

#include <iostream>
#include <string>
#include <fstream>
#include "userStruct.h"
#include "welcome.h"
#include "levels.h"
#include "play.h"
using namespace std;

void displayExistingUsers(){
  // baca users
}

User getUser(string chosenUsername,User chosenUser){
  string file=chosenUsername+".txt";
  ifstream fin;
  fin.open(file);
  if (fin.fail())
  {
    cout<<"Error in file opening"<<endl;
    exit(1);
  }
  fin>>chosenUser.username>>chosenUser.level>>chosenUser.currentMap>>chosenUser.limit>>chosenUser.heartPos[0]>>chosenUser.heartPos[1]>>chosenUser.heartExist;
  fin.close()
}

void createUser(string newUsername,User newUser){
  string file=newUsername+".txt";
  ofstream fout;
  fout.open(file);
  if (fout.fail())
  {
    cout<<"Error in file opening!"<<endl;
    exit(1);
  }
  newUser.username=newUsername;
  newUser.level=1;
  newUser.currentMap=GetEmptyMap(newUser.level);
  newUser.limit=GetInitialMoves(newUser.level);
  newUser.heartPos[0];//how to randomize position?
  newUser.heartPos[1];//
  newUser.heartExist=true;
  fout<<newUser.username<<" "<<newUser.level<<" "<<newUser.currentMap<<" "<<newUser.limit<<" "<<newUser.heartPos[0]<<" "<<newUser.heartPos[1]<<" "<<newUser.heartExist<<endl;
  fout.close();
}

User newGame(){
  string newUsername;
  User newUser;
  cout << "Enter a new username: ";
  cin >> newUsername;
  createUser(newUsername,newUser);
  return newUser;
}

User continueGame(){
  string chosenUsername;
  User chosenUser;
  cout << "Choose an existing user:" << endl;
  displayExistingUsers();
  cin >> chosenUsername;
  chosenUser = getUser(chosenUsername,chosenUser);
  return chosenUser;
}


// Function to display welcome message and let the player choose
// to new game or continue game. Returns the user.
User welcome(){
  string game;
  User theUser;
  cout << "Welcome to Labyrinth!" << endl;
  cout << "1. New Game" << endl;
  cout << "2. Continue Game" << endl;
  
  cin >> game;
  if (game == "1"){
    theUser = newGame();
  }
  if (game == "2"){
    theUser = continueGame();
  }
  
  return theUser;
}