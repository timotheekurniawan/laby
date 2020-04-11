// userStruct.h
// Struct to hold 
#include <string>
#ifndef USER_STRUCT
#define USER_STRUCT

struct User {
  string username;
  int level;
  std::string currentMap[10][10];
  int limit;
  int applePos[2];
  bool appleExist;
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
