//welcome.h
#ifndef WELCOME_H
#define WELCOME_H
#include <string>
#include "userStruct.h"
#include "levels.h"

void addToUsernameList(std::string username);
void displayExistingUsers();
void getUser(std::string chosenUsername, User &chosenUser);
void createUser(std::string newUsername, User &newUser);
User newGame();
User continueGame();
User welcome();

#endif
