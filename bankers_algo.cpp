#include<iostream>
using namespace std;

int main(){
	int n;
	int m;
	
	// take input of the number of the processes and resources
	cout<<"Enter number of process: ";
	cin>>n;
	
	cout<<"Enter number of resources: ";
	cin>>m;
	
	// Prepare the required matrix
	int allocated[n][m];
	int max_needed[n][m];
	int needed[n][m];
	int available[m];
	
	// Take all the required matrix`s input
	cout<<"Enter allocation matrix: "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<"Enter allocation matrix:["<<i<<"]["<<j<<"]";
			cin>> allocated[i][j];
		}
	}
	cout<<"Enter max_needed matrix: "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
		cout<<"Enter max_nedded matrix:["<<i<<"]["<<j<<"]";
			cin>> max_needed[i][j];
		}
	}
	cout<<"Enter availabe matrix: "<<endl;
	for(int i=0; i<m; i++){
		cin>> available[i];
	}
	
	// Calculating needed matrix need = max - allocated
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			needed[i][j] = max_needed[i][j] - allocated[i][j];
		}
	}
	
	// Finish array to track completed processes
	bool finish[n];
	for(int i=0; i<n; i++){
		finish[i] = false;
	}
	
	int safeSequence[n];
	int work[m];
	
	// copy avaiable resources to work
	for(int i=0; i<m; i++){
		work[i] = available[i];
	}
	
	int count = 0;
	
	// Banker`s Algorithm 
	while(count < n){
		bool found = false;
		
		for(int i=0; i<n; i++){
			if(finish[i] == false){
				bool possible = true;
				
				// check if need <= work
				for(int j=0; j<m; j++){
					if(needed[i][j] > work[j]){
						possible = false;
						break;
					}
				}
				if(possible){
					for(int j=0; j<m; j++){
						work[j] += allocated[i][j]; 
					}
					safeSequence[count] = i;
					count++;
					
					finish[i] = true;
					found = true;
				}
			}
		}
		if(found == false){
			cout<<"\nSystem is not in safe state\n";
			return 0;
		}
	}
	
	// the code only reaches here if the while loop is completed
	cout<<"\n System is in safe state\n";
	cout<<"Safe Sequence is: ";
	
	for(int i=0; i<n; i++){
		cout<<"P"<<safeSequence[i]<<" ";
	}
	cout << endl;
	return 0;
}
