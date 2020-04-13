// The main program
#include <iostream>
#include "welcome.h"
#include "play.h"
#include "userStruct.h"
using namespace std;

int main(){
  User user = welcome();
  PlayGame(user);
}