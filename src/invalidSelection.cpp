// invalidSelection.cpp
// This file contains the function to check if the selection is invalid

#include <iostream>
using namespace std;

// Function to check if the selection is invalid
// Input    : - a char array that consist of available selections
//            - a char that corresponds to the selection made by user
//            - the number of available selections
// Output   : - true if the selection is invalid
//            - false if the seleciton is valid
bool invalidSelection(char selectionList[], char selection, int sizeSelectionList)
{
    for (int i = 0; i < sizeSelectionList; ++i)
    {
        if (selection == selectionList[i])
        {
            return false;
        }
    }
    return true;
}
