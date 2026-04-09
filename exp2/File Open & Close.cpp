#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;

int main()
{
    int fd = open("demo.txt", O_RDONLY);

    if(fd == -1)
    {
        cout << "File Cannot open" << endl;
        return 1;
    }

    cout << "File opened successfully" << endl;
    close(fd);
    cout << "File closed successfully" << endl;

    return 0;
}