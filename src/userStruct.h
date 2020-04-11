// userStruct.h
// Struct to hold 
#include <string>
#ifndef USER_STRUCT
#define USER_STRUCT

struct User {
  std::string username;              
  int currentLevel;             // Current level of user 
  std::string currentMap;       // String which corresponds to the map
  int currentLimit;             // Current move limit
  int heartPos[2];              // (x,y) coordinate
  int heartExist;               // 1 if exist, 0 if not exist
};

#endif

// Example of use:
// 
// (1)
// User user1;
// user1.level = 1;
// user1.limit = 2;
// user1.applePos[0] = 3;
// user1.applePos[1] = 4;
// user1.appleExist = true;
//
// 
// DYNAMIC MEMORY MANAGEMENT
// 
// (2)
// User * user1 = new User;
// (*user1).level = 4;
// cout << (*user1).level << endl;
//
// (3)
// User * user1 = new User;
// user1->level = 4;
// cout << user->level << endl;
// 
