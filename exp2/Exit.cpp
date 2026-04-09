#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int choice;
    cout << "Enter 1 to Exit, Enter 2 to Abort: ";
    cin >> choice;

    if(choice == 1)
    {
        cout << "Process Ended Normally" << endl;
        exit(0);
    }
    else
    {
        cout << "Process Aborted" << endl;
        abort();
    }

    return 0;
}