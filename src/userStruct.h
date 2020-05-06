// userStruct.h
// Structure that  contains the data of the user
#ifndef USER_STRUCT
#define USER_STRUCT

#include <string>
struct User
{
    std::string username;
    int currentLevel;       // Current currentLevel of user
    std::string currentMap; // String which corresponds to the map
    int currentLimit;       // Current move currentLimit
    int currentTravel;      // Current spaces traveled by Laby
};

#endif

