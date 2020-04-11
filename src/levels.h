//currentLevels.h
//contain all 10 currentLevels, function to get empty maps of each currentLevel, and get initial moves of each currentLevel
#include <string>
#ifndef currentLevelS_H
#define currentLevelS_H

std::string getEmptyMap(int level);
int getInitialLimit(int level);
void buildMap(std::string map);

#endif