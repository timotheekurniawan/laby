// currentLevels.h
#ifndef currentLevelS_H
#define currentLevelS_H
#include <string>

extern std::string maps[10];
extern int limits[10];
extern int spaces[10];
std::string getEmptyMap(int level);
int getInitialLimit(int level);
void randomizeHeartPos(std::string &map);
void randomizeStartPos(std::string &map);
void buildMap(std::string map);

#endif