#include <iostream>
#include <fstream>
#include "play.h"
#include "userStruct.h"
#include "laby.h"
#include "levels.h"
#include "congrats.h"

using namespace std;

//function to play a certain level
//randomizeStartPos() is called to place laby in a randomize position in the map
//randomizeHeartPos() is called to place a heart in a randomize position in the map
//getMove() is called for getting user's input on what direction will laby go
//buildMap is called to output the map
//stores userSelected's progress(currentLevel,currentMap,currentLimit,currentTravel) in userSelected.username.txt when user decides to quit game
//input : -struct of user selected
//        -boolean stillPlaying which indicates if a user still wants to play or not, if a user quits, stillPlaying becomes false
void playCurrentLevel(User &userSelected,bool &stillPlaying){
    int selection;
    // randomizeStartPos(userSelected.currentMap);
    // randomizeHeartPos(userSelected.currentMap);
    while (userSelected.currentLimit>0 && userSelected.currentTravel<spaces[userSelected.currentLevel-1] && stillPlaying)
    {
        buildMap(userSelected.currentMap);
        cout<<"Moves Remaining: "<<userSelected.currentLimit<<endl;
        getMove(userSelected,stillPlaying);
    }

    //if user fills out all the empty spaces in the map with 'O' and user's currentLimit is not yet 0
    if (userSelected.currentTravel==spaces[userSelected.currentLevel-1] && userSelected.currentLimit>=0)
    {
        if (userSelected.currentLevel+1<11)
        {
            cout<<"Level "<<userSelected.currentLevel<<" Completed!"<<endl;
            userSelected.currentLevel+=1;
            userSelected.currentMap=getEmptyMap(userSelected.currentLevel);
            userSelected.currentLimit=getInitialLimit(userSelected.currentLevel);
            userSelected.currentTravel=0;
            cout<<"Level Up!"<<endl;
            cout<<"Now you are at level "<<userSelected.currentLevel<<"."<<endl;
            cout<<"Continue Playing?"<<endl;
            cout<<"1. Continue"<<endl;
            cout<<"2. Quit"<<endl;
            cout<<"Choose (1) or (2)"<<endl;
            cout<<"Selection: "<<endl;
            cin>>selection;
            if (selection==2)//if user decides to quit game, save user's progress to .txt file
            {
                string filename=userSelected.username+".txt";
                ofstream fout;
                fout.open(filename);
                if (fout.fail())
                {
                    cout<<"Error in file opening!"<<endl;
                    exit(1);
                }
                fout<<userSelected.username<<" "<<userSelected.currentLevel<<" "<<userSelected.currentMap<<" "<<userSelected.currentLimit<<" "<<userSelected.currentTravel<<endl;
                stillPlaying=false;
                return;
            }
            else if (selection==1)
            {
                playCurrentLevel(userSelected, stillPlaying);
            }
        }
        else//finished 10 levels
        {
            stillPlaying=false;
        }
    }
    //if user fails to complete the level, indicated by not being able to fill out all the empty spaces in the map with 'O' when user's currentLimit has reached 0
    else if ( (userSelected.currentTravel<spaces[userSelected.currentLevel-1] && userSelected.currentLimit==0) || userSelected.currentLimit<0 )
    {
        userSelected.currentMap=getEmptyMap(userSelected.currentLevel);
        userSelected.currentLimit=getInitialLimit(userSelected.currentLevel);
        userSelected.currentTravel=0;
        cout<<"No moves left!"<<endl;
        cout<<"Level failed!"<<endl;
        cout<<"Retry Level?"<<endl;
        cout<<"1. Retry"<<endl;
        cout<<"2. Quit"<<endl;
        cout<<"Choose (1) or (2)"<<endl;
        cout<<"Selection: "<<endl;
        cin>>selection;
        if (selection==2)//if user decides to quit game, store user's progress in .txt file
        {
            string filename=userSelected.username+".txt";
            ofstream fout;
            fout.open(filename);
            if (fout.fail())
            {
                cout<<"Error in file opening!"<<endl;
                exit(1);
            }
            fout<<userSelected.username<<" "<<userSelected.currentLevel<<" "<<userSelected.currentMap<<" "<<userSelected.currentLimit<<" "<<userSelected.currentTravel<<endl;
            stillPlaying=false;
            return;
        }
        else if (selection==1)
        {
            playCurrentLevel(userSelected, stillPlaying);
        }
    }
}

//function to play the game
//Playcurrentlevel() is called to play a certain level
//CompletedGame() is called to display congratulations message when user succeeds to completed all 10 level
//input: -struct of userSelected
void playGame(User &userSelected){
    bool stillPlaying=true;
    while (userSelected.currentLevel<11 && stillPlaying)
    {
        playCurrentLevel(userSelected, stillPlaying);
    }
    if (userSelected.currentLevel == 11){
        completedGame(userSelected);
    }
    else {
        return;
    }
}
