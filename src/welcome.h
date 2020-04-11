//welcome.h
#ifndef WELCOME_H
#define WELCOME_H

User welcome();
User newGame();
User continueGame();
void createUser(string newUsername, User &newUser);
void getUser(string chosenUsername, User &chosenUser);
void displayExistingUsers();
void addToUsernameList(string username);

#endif
