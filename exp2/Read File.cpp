#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;

int main()
{
    int fd;
    char buffer[50];

    fd = open("demo.txt", O_RDONLY);
    read(fd, buffer, 50);

    write(1, buffer, 50);
    close(fd);

    return 0;
}