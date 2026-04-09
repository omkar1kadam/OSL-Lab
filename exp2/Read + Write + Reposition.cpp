#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>
using namespace std;

int main()
{
    int fd;
    char buffer[100];

    fd = open("info.txt", O_CREAT | O_RDWR, 0644);

    char msg[] = "Linux File System Call";
    write(fd, msg, strlen(msg));

    lseek(fd, 0, SEEK_SET);

    read(fd, buffer, sizeof(buffer));
    cout << "Data read: " << buffer << endl;

    close(fd);
    return 0;
}