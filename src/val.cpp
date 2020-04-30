#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin;
    string existingnames;
    bool ExistingUserFound=true;
    fin.open("usernameList.txt");
    if (fin.fail())
    {
        cout<<"Error "<<endl;
        exit(1);
    }
    for (int i=0;ExistingUserFound;++i)
    {
        cout<<i<<endl;
        string newUsername;
        int numofusers=0,count=0;
        cout<<"Enter username: ";
        cin>>newUsername;
        while (getline(fin,existingnames))
        {
            cout<<existingnames<<endl;
            numofusers+=1;
            if (existingnames!=newUsername)
            {
                count+=1;
            }
            cout<<numofusers<<" "<<count<<endl;
        }
        if (count==numofusers)
        {
            // cout<<count<<" "<<numofusers<<endl;
            cout<<newUsername<<endl;
            ExistingUserFound=false;
        }
        else
        {
            cout<<"Username taken!"<<endl;
        }
    }
    fin.close();
}