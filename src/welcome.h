//welcome.h
#include <string>
#include "userStruct.h"
#ifndef WELCOME_H
#define WELCOME_H

void addToUsernameList(std::string username);
void displayExistingUsers();
void getUser(std::string chosenUsername, User &chosenUser);
void createUser(std::string newUsername, User &newUser)
User newGame();
User continueGame();
User welcome();

#endif
