// welcome.cpp
// Display welcome message, choose either new or continue game
// Get the user and return it to the main function

#include <iostream>
#include <string>
#include <fstream>
#include "welcome.h"
#include "userStruct.h"
#include "levels.h"
#include "invalidSelection.h"
using namespace std;

// Function to check if the save file "usernameList.txt"
// exist.
// Output   : - true if exist
//            - false if does not exist
bool existingSaveFiles()
{
    ifstream fin;
    fin.open("usernameList.txt");
    if (fin.fail())
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Function to add new username to usernameList.txt
// that holds all the username registered in the game
// Input    : - new username
void addToUsernameList(string username)
{
    ofstream fout;
    fout.open("usernameList.txt", ios::app);
    if (fout.fail())
    {
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    fout << username << endl;
    fout.close();
}

// Function to display all usernames in usernameList.txt
// that holds all the username registered in the game
void displayExistingUsers()
{
    int count = 1;
    string username;
    ifstream fin;
    fin.open("usernameList.txt");
    while (fin >> username)
    {
        cout << "(" << count << ") " << username << endl;
        ++count;
    }
    return;
}

// Function that counts the number of existing user
// in usernameList.txt
// Output   : - the number of existing users
int countExistingUsers()
{
    int count = 0;
    string username;
    ifstream fin;
    fin.open("usernameList.txt");
    while (fin >> username)
    {
        ++count;
    }
    return count;
}

// Function to get the chosen user from users.txt
// based on the chosen username
// Input    : - chosen username
//            - chosenUser (pass by referenced)
void getUser(string chosenUsername, User &chosenUser)
{
    string file = chosenUsername + ".txt";
    ifstream fin;
    fin.open(file);
    if (fin.fail())
    {
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    fin >> chosenUser.username >> chosenUser.currentLevel >> chosenUser.currentMap >> chosenUser.currentLimit >> chosenUser.currentTravel;
    fin.close();
    return;
}

// Function to create a new user to users.txt
// with username input. It also calls the function
// addToUsernameList() to add the new username to usersList.txt
// Input    : - new username
//            - a pointer newUser (pass by referenced)
void createUser(string newUsername, User *&newUser)
{
    string file = newUsername + ".txt";
    ofstream fout;
    fout.open(file);
    if (fout.fail())
    {
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    addToUsernameList(newUsername);

    newUser->username = newUsername;
    newUser->currentLevel = 1;
    newUser->currentMap = getEmptyMap(newUser->currentLevel);
    newUser->currentLimit = getInitialLimit(newUser->currentLevel);
    newUser->currentTravel = 1;
    fout << newUser->username << " " << newUser->currentLevel << " " << newUser->currentMap << " " << newUser->currentLimit << " " << newUser->currentTravel;
    fout.close();
}

// Function to check if the username is in the usernameList.txt
// Output   : - true if exist
//            - false if does not exist
bool usernameExist(string newUsername)
{
    ifstream fin;
    string existingUsername;
    fin.open("usernameList.txt");

    // If usernameList.txt does not exist, returns false;
    if (fin.fail())
    {
        return false;
    }

    while (fin >> existingUsername)
    {
        if (existingUsername == newUsername)
        {
            return true;
        }
    }
    return false;
}

// Function used if the player choose New Game.
// It asks for a new username and create the user
// then store the user locally.
// Output   : the newly created User
User newGame()
{
    string newUsername;
    User *newUser = new User;                       // Create a variable newUser that points to a dynamically allocated User structure
    User currentUser;
    cout << "Enter a new username: ";

    while (true)
    {
        cin >> newUsername;
        if (usernameExist(newUsername) == false)
        {
            createUser(newUsername, newUser);
            delete (newUser);                       // Free the memory allocated to the User structure
            getUser(newUsername, currentUser);      // Get the user and store the data into currentUser (User structure)
            cout << endl
                 << "---------------------------------------------------" << endl;
            return currentUser;
        }
        cout << endl
             << "Username already exist." << endl;
        cout << "Enter a new username: ";
    }
}

// Function used if the player choose Continue Game.
// The player chooses the user.
// Return   : the chosen existing User
User continueGame()
{
    ifstream fin;
    fin.open("usernameList.txt");
    if (fin.fail())
    {
        cout << "Error in opening usernameList" << endl;
        exit(1);
    }
    int chosenUsernameNumber = 0;
    string chosenUsername;
    User chosenUser;
    int numberOfExistingUsers = countExistingUsers();
    bool firstLoop = true;
    
    // Loop if chosenUsernameNumber is invalid
    while (chosenUsernameNumber <= 0 || chosenUsernameNumber > numberOfExistingUsers)
    {
        if (firstLoop == false)
        {
            cout << endl
                 << "---------------- Invalid Selection ----------------" << endl;
        }
        firstLoop = false;
        cout << "Choose an existing user:" << endl;
        displayExistingUsers();
        cout << "Selection: ";
        cin >> chosenUsernameNumber;
    }
    cout << endl
         << "---------------------------------------------------" << endl;
    for (int i = 0; i < chosenUsernameNumber; ++i)
    {
        fin >> chosenUsername;
    }
    getUser(chosenUsername, chosenUser);
    return chosenUser;
}

// Function to print the star logo in the opening
void printStar()
{
    string indent = "                     ";
    cout << indent << "    ." << endl;
    cout << indent << "___/ \\___" << endl;
    cout << indent << " ',   .'" << endl;
    cout << indent << " /.' '.\\" << endl;
}

// Function to print the title "LABYRINTH" in the opening
void printLabyrinth()
{
    string indent = "  ";
    cout << indent << "   __       _                _       _   _     " << endl;
    cout << indent << "  / /  __ _| |__  _   _ _ __(_)_ __ | |_| |__  " << endl;
    cout << indent << " / /  / _` | '_ \\| | | | '__| | '_ \\| __| '_ \\ " << endl;
    cout << indent << "/ /__| (_| | |_) | |_| | |  | | | | | |_| | | |" << endl;
    cout << indent << "\\____/\\__,_|_.__/ \\__, |_|  |_|_| |_|\\__|_| |_|" << endl;
    cout << indent << "                  |___/                        " << endl;
}

// Function to display welcome message and let the player choose
// to new game or continue game.
// Output   : - the user playing
User welcome()
{
    char game;
    char selectionList[2] = {'1', '2'};
    int sizeSelectionList = 2;
    User userPlaying;
    cout << "---------------------------------------------------" << endl
         << endl;
    printStar();
    printLabyrinth();
    cout << endl
         << endl;

    // Loop as long as the selection made by user is invalid
    while (invalidSelection(selectionList, game, sizeSelectionList))
    {
        cout << "(1) New Game" << endl;
        cout << "(2) Continue Game" << endl;
        cout << "Select: ";
        cin >> game;
        // If the player chooses New Game
        if (game == '1')
        {
            cout << endl
                 << "---------------------------------------------------" << endl
                 << endl;
            userPlaying = newGame();
            break;
        }
        
        // If the player chooses Continue Game
        else if (game == '2')
        {
            cout << endl
                 << "---------------------------------------------------" << endl
                 << endl;
            if (existingSaveFiles())
            {
                userPlaying = continueGame();
            }
            else
            {
                cout << "No existing user yet!" << endl
                     << endl;
                cout << "---------------------------------------------------" << endl
                     << endl;
                cout << "Creating a new user.." << endl
                     << endl;
                userPlaying = newGame();
            }
            break;
        }
        else
        {
            cout << endl
                 << "---------------- Invalid Selection ----------------" << endl
                 << endl;
        }
    }
    cout << endl;
    return userPlaying;
}