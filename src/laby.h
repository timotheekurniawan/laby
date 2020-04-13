//laby.h
//contains function for movement of Laby
#include "userStruct.h"
#ifndef LABY_H
#define LABY_H

void moveLeft(int labyPos,User &userSelected);
void moveRight(int labyPos,User &userSelected);
void moveUp(int labyPos,User &userSelected);
void moveDown(int labyPos,User &userSelected);
void getMove(User &userSelected);

#endif

