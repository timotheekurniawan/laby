// userStruct.h
// Struct to hold 
#include <string>
#ifndef USER_STRUCT
#define USER_STRUCT

struct User {
    std::string username;              
    int currentLevel;             // Current currentLevel of user 
    std::string currentMap;       // String which corresponds to the map
    int currentLimit;             // Current move currentLimit
    int currentTravel;            // Current spaces traveled by Laby
};

#endif

// Example of use:
// 
// (1)
// User user1;
// user1.currentLevel = 1;
// user1.currentLimit = 2;
// user1.applePos[0] = 3;
// user1.applePos[1] = 4;
// user1.appleExist = true;
//
// 
// DYNAMIC MEMORY MANAGEMENT
// 
// (2)
// User * user1 = new User;
// (*user1).currentLevel = 4;
// cout << (*user1).currentLevel << endl;
//
// (3)
// User * user1 = new User;
// user1->currentLevel = 4;
// cout << user1->currentLevel << endl;
// 
