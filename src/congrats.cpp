#include <iostream>
#include <fstream>
#include "congrats.h"
#include "userStruct.h"
#include "levels.h"
#include "play.h"

using namespace std;

//Function used when a user has finished all 10 levels
//Function displays congratulation message and asks the user wether to restart the game or quit the game
//If the user restarts game, it resets user's game progress(currentLevel,currentMap,etc.) to level 1
//PlayGame(username) to play the game again
//If the user quits game, the user's game progress(currentLevel,currentMap,etc.) is stored in username.txt
void CompletedGame(User &username){
    int selection;
    cout<<"Congratulations. You have completed all the levels!"<<endl;
    cout<<"Would you like to restart?"<<endl;
    cout<<"Choose (1) or (2)"<<endl;
    cout<<"1. Restart Game"<<endl;
    cout<<"2. Quit Game"<<endl;
    cin>>selection;
    if (selection==1)
    {
        username.currentLevel = 1;
        username.currentMap = getEmptyMap(username.currentLevel);
        username.currentLimit = getInitialLimit(username.currentLevel);
        // username.heartPos[0] = randomizeHeartPos;
        // username.heartPos[1] = randomizeHeartPos;
        //randomizeHeartPos(username.currentMap);
        username.heartExist = 1;
        PlayGame(username);
    }
    else if (selection==2)
    {
        username.currentLevel = 11;
    }

}
