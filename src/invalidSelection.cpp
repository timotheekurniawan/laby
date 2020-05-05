#include <iostream>
using namespace std;

bool invalidSelection(char selectionList[], char selection, int sizeSelectionList){
  for (int i = 0; i < sizeSelectionList; ++i){
    if (selection == selectionList[i]){
      return false;
    }
  }
  return true;
}
