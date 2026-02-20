#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;

int main(){
	int fd; // fd is the file directory number
	char buffer[50];
	
	fd = open("demo.txt",O_RDONLY);
	
	read(fd,buffer,20);
	
	cout<<"Write function"<<endl;
	write(1,buffer,20);
	cout<<endl;
	
	cout<<"Cout function"<<endl;
	cout<<buffer<<endl;
	
	
	close(fd);
	cout<<"file readed and the output is the printed"<<endl;
	return 0;
}
