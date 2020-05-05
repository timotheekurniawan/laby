//play.h
//to play game
#ifndef PLAY_H
#define PLAY_H
#include "userStruct.h"
#include "laby.h"
#include "levels.h"
#include "congrats.h"
#include "invalidSelection.h"
void playCurrentLevel(User &userSelected, bool &stillPlaying);
void playGame(User &userSelected);

#endif