// welcome.cpp
// Display welcome message, choose either new or continue game
// Get the user and return it to the main function
#include <iostream>
#include <string>
#include <fstream>
#include "welcome.h"
#include "userStruct.h"
#include "levels.h"
using namespace std;

// Function to add new username to usernameList.txt 
// that holds all the username registered in the game
// Input    : - new username
void addToUsernameList(string username){
    ofstream fout;
    fout.open("usernameList.txt",ios::app);
    if (fout.fail()){
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    fout << username << endl;
    fout.close();
}

// Function to display all usernames in usernameList.txt 
// that holds all the username registered in the game
void displayExistingUsers(){
    int count = 1;
    string username;
    ifstream fin;
    fin.open("usernameList.txt");
    while (fin >> username){
        cout << count << ". " << username << endl;
        ++count;
    }
    return;
}

// Function to get the chosen user from users.txt 
// based on the chosen username
// Input    : - chosen username
//            - chosenUser (pass by referenced)
void getUser(string chosenUsername, User &chosenUser){
    string file=chosenUsername+".txt";
    ifstream fin;
    fin.open(file);
    if (fin.fail())
    {
        cout<<"Error in file opening!"<<endl;
        exit(1);
    }
    fin>>chosenUser.username>>chosenUser.currentLevel>>chosenUser.currentMap>>chosenUser.currentLimit>>chosenUser.currentTravel;
    fin.close();
    return;
}

// Function to create a new user to users.txt 
// with username input. It also calls the function
// addToUsernameList() to add the new username to usersList.txt
// Input    : - new username
//            - newUser (pass by referenced) 
void createUser(string newUsername,User *& newUser){
    string file=newUsername+".txt";
    ofstream fout;
    fout.open(file);
    if (fout.fail())
    {
        cout<<"Error in file opening!"<<endl;
        exit(1);
    }
    addToUsernameList(newUsername);

    newUser -> username= newUsername;
    newUser -> currentLevel= 1;
    newUser -> currentMap = getEmptyMap(newUser->currentLevel);
    newUser -> currentLimit= getInitialLimit(newUser->currentLevel);
    newUser -> currentTravel= 0;
    fout<<newUser->username<<" "<<newUser->currentLevel<<" "<<newUser->currentMap<<" "<<newUser->currentLimit<<" "<<newUser->currentTravel<<endl;
    fout.close();
}

// void createUser(string newUsername, User &newUser){
//     string file=newUsername+".txt";
//     ofstream fout;
//     fout.open(file);
//     if (fout.fail())
//     {
//         cout<<"Error in file opening!"<<endl;
//         exit(1);
//     }
//     addToUsernameList(newUsername);

//     newUser.username = newUsername;
//     newUser.currentLevel = 1;
//     newUser.currentMap = getEmptyMap(newUser.currentLevel);
//     newUser.currentLimit = getInitialLimit(newUser.currentLevel);
//     newUser.currentTravel=0;

//     fout<<newUser.username<<" "<<newUser.currentLevel<<" "<<newUser.currentMap<<" "<<newUser.currentLimit<<" "<<newUser.currentTravel<<endl;
//     fout.close();
// }

// Function to check if the username is in the usernamelist
// returns true if exist, returns false if not exist
bool usernameExist(string newUsername){
    ifstream fin;
    string existingUsername;
    fin.open("usernameList.txt");
    
    // If usernameList.txt does not exist, returns dne; 
    if (fin.fail()){
        return false;
    }

    while (fin >> existingUsername){
        if (existingUsername == newUsername){
            return true;
        }
    }
    return false;
}


// Function used if the player choose New Game.
// It asks for a new username and create the user
// then store the user locally.
// Return   : the newly created User
User newGame(){
    string newUsername;
    User *newUser = new User;
    cout << "Enter a new username: ";
    
    while (true){
        cin >> newUsername;
        if (usernameExist(newUsername) == false){
            createUser(newUsername, newUser);
            return *newUser;
        }
        cout << "Username already exist." << endl;
        cout << "Enter a new username: ";
    }
    
}

// User newGame(){
//     string newUsername;
//     User newUser;
//     cout << "Enter a new username: ";
//     cin >> newUsername;
//     createUser(newUsername, newUser);
//     return newUser;
// }


// Function used if the player choose Continue Game.
// The player chooses the user. 
// Return   : the chosen existing User
User continueGame(){
    ifstream fin;
    fin.open("usernameList.txt");
    if (fin.fail()){
        cout << "Error in opening usernameList" << endl;
        exit(1);
    }
    int chosenUsernameNumber;
    string chosenUsername;
    User chosenUser;
    cout << "Choose an existing user:" << endl;
    displayExistingUsers();
    cin >> chosenUsernameNumber;
    for (int i = 0; i < chosenUsernameNumber; ++i){
        fin >> chosenUsername;
    }
    getUser(chosenUsername,chosenUser);
    return chosenUser;
}

// Function to display welcome message and let the player choose
// to new game or continue game. 
// Return   : the user
User welcome(){
    string game;
    User userPlaying;
    cout << "Welcome to Labyrinth!" << endl;
    cout << "Choose (1) or (2)" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Continue Game" << endl;

    cin >> game;
    if (game == "1")
    {
        userPlaying = newGame();
    }
    if (game == "2")
    {
        userPlaying = continueGame();
    }
    return userPlaying;
}