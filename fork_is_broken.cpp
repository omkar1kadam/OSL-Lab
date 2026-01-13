#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;

int main(){
	int pid;
	
	pid = fork();
	
	if(pid == 0){
		cout << "child process"<<endl;
	}
	if (pid > 0 ){
		cout << "Parent process"<<endl;
	}
	cout<<"pid is:"<<pid<<endl;
	
	return 0;
}
