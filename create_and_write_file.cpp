#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;

int main(){
	int fd; // fd is the file directory number
	fd = open("demo.txt",O_CREAT | O_WRONLY, 0644);
	
	write(fd,"OS needs to be studied",20);
	
	close(fd);
	
	cout<<"file created and wrote the text successfull"<<endl;
	return 0;
}
