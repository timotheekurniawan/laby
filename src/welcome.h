//welcome.h
#ifndef WELCOME_H
#define WELCOME_H
#include <string>
#include "userStruct.h"
#include "levels.h"
#include "invalidSelection.h"

void addToUsernameList(std::string username);
void displayExistingUsers();
int countExistingUsers();
void getUser(std::string chosenUsername, User &chosenUser);
void createUser(std::string newUsername, User &newUser);
void printStar();
void printLabyrinth();
User newGame();
User continueGame();
User welcome();

#endif
