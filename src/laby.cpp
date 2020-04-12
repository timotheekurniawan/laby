#include <iostream>
#include "userStruct.h"
#include "levels.h"

using namespace std;

#define HEART "\xE2\x99\xA5"


void moveLeft(int LabyPos,User &userSelected){
    int a=LabyPos%10;//misal posisi laby 28, jadi a=8
    for (int i=LabyPos-1;i>=LabyPos-a;--i)//biar i>=20 (kalo posisi laby 28, brarti kalo move left check index 27 26 25 24 23 22 21 20)
    {
        if (userSelected.currentMap[i]==' ')
        {
            userSelected.currentMap[i]='*';
            userSelected.currentMap[i+1]='O';
        }
        else if (userSelected.currentMap[i]==HEART)
        {
            userSelected.currentMap[i]=='*';
            userSelected.currentMap[i+1]=='O';
            userSelected.currentLimit+=1;
        }
        else if (userSelected.currentMap[i]=='X')
        {
            break;
        } 
    }
}

void moveRight(int LabyPos,User &userSelected){
    int b=LabyPos%10;//misal posisi laby 35, brarti b=5
    int a=9-b;//a=9-5=4
    for (int i=LabyPos+1;i<=LabyPos+a;++i)//biar i<=39 (kalo posisi laby 35, brarti kalo move right cek index 36 37 38 39)
    {
        if (userSelected.currentMap[i]==' ')
        {
            userSelected.currentMap[i]='*';
            userSelected.currentMap[i-1]='O';
        }
        else if (userSelected.currentMap[i]==HEART)
        {
            userSelected.currentMap[i]='*';
            userSelected.currentMap[i-1]='O';
            userSelected.currentLimit+=1;
        }
        else if (userSelected.currentMap[i+1]=='X')
        {
            break;
        }
    }
}

void moveUp(int LabyPos,User &userSelected){
    int a=LabyPos%10;//misal posisi laby 52, brarti a=2
    for (int i=LabyPos-10;i>=a;i-=10)//biar i>=2 (kalo posisi laby 52, brarti kalo move up cek index 42,32,22,12,2)
    {
        if (userSelected.currentMap[i]==' ')
        {
            userSelected.currentMap[i]='*';
            userSelected.currentMap[i+10]='O';
        }
        else if (userSelected.currentMap[i-10]==HEART)
        {
            userSelected.currentMap[i]='*';
            userSelected.currentMap[i+10]='O';
            userSelected.currentLimit+=1;
        }
        else if (userSelected.currentMap[i]=='X')
        {
            break;
        }
    }
}

void moveDown(int LabyPos,User &userSelected){
    int a=LabyPos%10;//misal posisi laby 74, brarti a=4
    for (int i=LabyPos+10;i<=(90+a);i+=10)//biar i<=94 (kalo posisi laby 74, berarti kalo move down cek index 84 94)
    {
        if (userSelected.currentMap[i]==' ')
        {
            userSelected.currentMap[i]='*';
            userSelected.currentMap[i-10]='O';
        }
        else if (userSelected.currentMap[i]==HEART)
        {
            userSelected.currentMap[i]='*';
            userSelected.currentMap[i-10]='O';
            userSelected.currentLimit+=1;
        }
        else if (userSelected.currentMap[i]=='X')
        {
            break;
        }
    }
}

//function to get user input of move selection
//getIntialLimit() to get move limit of user's respective level
//moveLeft(),moveRight(),moveUp(), and moveDown() to move to respective directions
void getMove(User &userSelected){
    int move;
    int LabyPos=(userSelected.currentMap).find("*");//to find postion(index) of laby in map represented by a string
    userSelected.currentLimit=getInitialLimit(userSelected.currentLevel);
    cout<<"1. Left"<<endl;
    cout<<"2. Right"<<endl;
    cout<<"3. Up"<<endl;
    cout<<"4. Down"<<endl;
    cout<<"Choose (1), (2), (3), or (4)"<<endl;
    cout<<"Select Move: "<<endl;
    cin>>move;
    userSelected.currentLimit-=1;
    if (move==1)
    {
        moveLeft(LabyPos,userSelected);
    }
    else if (move==2)
    {
        moveRight(LabyPos,userSelected);
    }
    else if (move==3)
    {
        moveUp(LabyPos,userSelected);
    }
    else if (move==5)
    {
        moveDown(LabyPos,userSelected);
    }
}
