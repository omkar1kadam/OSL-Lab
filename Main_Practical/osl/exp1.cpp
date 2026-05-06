#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<cstring>

using namespace std;

int main(){
    int fd = open("test.txt", O_CREAT | O_WRONLY, 0644);

    const char *msg = "Hello bro, only file system calls here!";
    write(fd,msg,strlen(msg));

    close(fd);

    fd = open("test.txt", O_RDONLY);
    cout<<fd;

    char buffer[100];
    read(fd,buffer,sizeof(buffer));
    write(1,buffer,100);

    close(fd);
}