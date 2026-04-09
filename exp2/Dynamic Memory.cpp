#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int *ptr = (int*) malloc(5 * sizeof(int));

    if(ptr == NULL)
    {
        cout << "Memory Allocation Failed" << endl;
        return 1;
    }

    for(int i = 0; i < 5; i++)
        ptr[i] = i * 10;

    cout << "Stored Values: ";
    for(int i = 0; i < 5; i++)
        cout << ptr[i] << " ";

    cout << endl;

    free(ptr);
    cout << "Memory Freed" << endl;

    return 0;
}