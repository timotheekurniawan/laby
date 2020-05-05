//laby.h
//contains function for movement of Laby
#ifndef LABY_H
#define LABY_H
#include "userStruct.h"
#include "levels.h"
#include "invalidSelection.h"
void moveLeft(int labyPos, User &userSelected);
void moveRight(int labyPos, User &userSelected);
void moveUp(int labyPos, User &userSelected);
void moveDown(int labyPos, User &userSelected);
void getMove(User &userSelected, bool &stillPlaying);

#endif
