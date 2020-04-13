//currentLevels.h
//contain all 10 currentLevels, function to get empty maps of each currentLevel, and get initial moves of each currentLevel
#include <string>
#ifndef currentLevelS_H
#define currentLevelS_H

std::string maps[10];
int limits[10];
int spaces[10];
std::string getEmptyMap(int level);
int getInitialLimit(int level);
void randomizeHeartPos(std::string &map);
void randomizeStartPos(std::string &map);
void buildMap(std::string map);
#endif