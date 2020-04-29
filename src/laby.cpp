#include <iostream>
#include "laby.h"
#include "userStruct.h"
#include "levels.h"

using namespace std;

#define HEART "\xE2\x99\xA5"


//function to move laby to the left
void moveLeft(int labyPos,User &userSelected){
    int a=labyPos%10;//misal posisi laby 28, jadi a=8
    for (int i=labyPos-1;i>=labyPos-a;--i)//biar i>=20 (kalo posisi laby 28, brarti kalo move left check index 27 26 25 24 23 22 21 20)
    {
        if (userSelected.currentMap[i]=='-')
        {
            userSelected.currentMap[i]='L';
            userSelected.currentMap[i+1]='O';
            userSelected.currentTravel+=1;
            userSelected.currentLimit-=1;
        }
        else if (userSelected.currentMap[i]=='V')
        {
            userSelected.currentMap[i]='L';
            userSelected.currentMap[i+1]='V';
            userSelected.currentLimit-=1;
        }
        else if (userSelected.currentMap[i]=='H')
        {
            userSelected.currentMap[i]='L';
            userSelected.currentMap[i+1]='V';
            // userSelected.currentLimit+=1; how many currentLimit should be added if heart is obtained?
            userSelected.currentTravel+=1;
            userSelected.currentLimit-=1;
        }
        else if (userSelected.currentMap[i]=='X')
        {
            break;
        } 
    }
}

//function to move laby to the right
void moveRight(int labyPos,User &userSelected){
    int b=labyPos%10;//misal posisi laby 35, brarti b=5
    int a=9-b;//a=9-5=4
    for (int i=labyPos+1;i<=labyPos+a;++i)//biar i<=39 (kalo posisi laby 35, brarti kalo move right cek index 36 37 38 39)
    {
        if (userSelected.currentMap[i]=='-')
        {
            userSelected.currentMap[i]='L';
            userSelected.currentMap[i-1]='V';
            userSelected.currentTravel+=1;
            userSelected.currentLimit-=1;
        }
        else if (userSelected.currentMap[i]=='V')
        {
            userSelected.currentMap[i]='L';
            userSelected.currentMap[i-1]='V';
            userSelected.currentLimit-=1;
        }
        else if (userSelected.currentMap[i]=='H')
        {
            userSelected.currentMap[i]='L';
            userSelected.currentMap[i-1]='V';
            // userSelected.currentLimit+=1;
            userSelected.currentTravel+=1;
            userSelected.currentLimit-=1;
        }
        else if (userSelected.currentMap[i]=='X')
        {
            break;
        }
    }
}

//function to move laby upwards
void moveUp(int labyPos,User &userSelected){
    int a=labyPos%10;//misal posisi laby 52, brarti a=2
    // if (labyPos>9)
    // {
        for (int i=labyPos-10;i>=a;i-=10)//biar i>=2 (kalo posisi laby 52, brarti kalo move up cek index 42,32,22,12,2)
        {
            if (userSelected.currentMap[i]=='-')
            {
                userSelected.currentMap[i]='L';
                userSelected.currentMap[i+10]='V';
                userSelected.currentTravel+=1;
                userSelected.currentLimit-=1;
            }
            else if (userSelected.currentMap[i]=='V')
            {
                userSelected.currentMap[i]='L';
                userSelected.currentMap[i+10]='V';
                userSelected.currentLimit-=1;
            }
            else if (userSelected.currentMap[i]=='H')
            {
                userSelected.currentMap[i]='L';
                userSelected.currentMap[i+10]='V';
                // userSelected.currentLimit+=1;
                userSelected.currentTravel+=1;
                userSelected.currentLimit-=1;
            }
            else if (userSelected.currentMap[i]=='X')
            {
                break;
            }
        }
    // }
}

//function to move laby downwards
void moveDown(int labyPos,User &userSelected){
    int a=labyPos%10;//misal posisi laby 74, brarti a=4
    // if (labyPos<90)
    // {
        for (int i=labyPos+10;i<=(90+a);i+=10)//biar i<=94 (kalo posisi laby 74, berarti kalo move down cek index 84 94)
        {
            if (userSelected.currentMap[i]=='-')
            {
                userSelected.currentMap[i]='L';
                userSelected.currentMap[i-10]='V';
                userSelected.currentTravel+=1;
                userSelected.currentLimit-=1;
            }
            else if (userSelected.currentMap[i]=='V')
            {
                userSelected.currentMap[i]='L';
                userSelected.currentMap[i-10]='V';
                userSelected.currentLimit-=1;
            }
            else if (userSelected.currentMap[i]=='H')
            {
                userSelected.currentMap[i]='L';
                userSelected.currentMap[i-10]='V';
                // userSelected.currentLimit+=1;
                userSelected.currentTravel+=1;
                userSelected.currentLimit-=1;
            }
            else if (userSelected.currentMap[i]=='X')
            {
                break;
            }
        }
    // }
}

//function to get user input of move selection
//getIntialLimit() to get move limit of user's respective level
//moveLeft(),moveRight(),moveUp(), and moveDown() to move to respective directions
void getMove(User &userSelected){
    int move;
    int labyPos=(userSelected.currentMap).find('*');//to find postion(index) of laby in map represented by a string
    // userSelected.currentLimit=getInitialLimit(userSelected.currentLevel);
    cout<<"1. Left"<<endl;
    cout<<"2. Right"<<endl;
    cout<<"3. Up"<<endl;
    cout<<"4. Down"<<endl;
    cout<<"Choose (1), (2), (3), or (4)"<<endl;
    cout<<"Select Move: ";
    cin>>move;
    // userSelected.currentLimit-=1;
    if (move==1)
    {
        moveLeft(labyPos,userSelected);
    }
    else if (move==2)
    {
        moveRight(labyPos,userSelected);
    }
    else if (move==3)
    {
        moveUp(labyPos,userSelected);
    }
    else if (move==4)
    {
        moveDown(labyPos,userSelected);
    } 
}