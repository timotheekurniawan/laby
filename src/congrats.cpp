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
void CompletedGame(User &userSelected){
    string filename=userSelected.username+".txt";
    ofstream fout;
    fout.open(filename);
    int selection;
    cout<<"Congratulations. You have completed all the levels!"<<endl;
    cout<<"Would you like to restart?"<<endl;
    cout<<"Choose (1) or (2)"<<endl;
    cout<<"1. Restart Game"<<endl;
    cout<<"2. Quit Game"<<endl;
    cin>>selection;
    if (selection==1)
    {
        userSelected.currentLevel = 1;
        userSelected.currentMap = getEmptyMap(userSelected.currentLevel);
        userSelected.currentLimit = getInitialLimit(userSelected.currentLevel);
        // username.heartPos[0] = randomizeHeartPos;
        // username.heartPos[1] = randomizeHeartPos;
        //randomizeHeartPos(username.currentMap);
        userSelected.heartExist = 1;
        PlayGame(userSelected);
    }
    else if (selection==2)
    {
        userSelected.currentLevel = 11;
        fout<<userSelected.username<<userSelected.currentLevel<<userSelected.currentMap<<userSelected.currentLimit<<userSelected.heartPos[0]<<userSelected.heartPos[1]<<userSelected.heartExist;
        fout.close();
    }
}
