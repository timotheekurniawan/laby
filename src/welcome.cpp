// welcome.cpp
// Display welcome message, choose either new or continue game
// Get the user and return it to the main function

#include <iostream>
#include <string>
#include <fstream>
#include "userStruct.h"
using namespace std;

void displayExistingUsers(){
  
}

User newGame(){
  string newUsername;
  cout << "Enter a new username: ";
  cin >> newUsername;
  
}

User continueGame(){
  string chosenUsername;
  cout << "Choose an existing user:" << endl;
  displayExistingUsers();
  cin >> chosenUsername;
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