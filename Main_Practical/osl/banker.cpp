#include<iostream>
using namespace std;

int main(){
    int n, m;

    cout<<"Enter number of process: ";
    cin>>n;

    cout<<"Enter number of resources: ";
    cin>>m;

    int allocated[n][m];
    int max_needed[n][m];
    int needed[n][m];
    int available[m];

    cout<<"Enter allocation matrix:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>allocated[i][j];
        }
    }

    cout<<"Enter max_needed matrix:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>max_needed[i][j];
        }
    }

    cout<<"Enter available resources:\n";
    for(int i=0; i<m; i++){
        cin>>available[i];
    }

    // Need = Max - Allocation
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            needed[i][j] = max_needed[i][j] - allocated[i][j];
        }
    }

    bool finish[n];
    for(int i=0; i<n; i++){
        finish[i] = false;
    }

    int safeSequence[n];
    int count = 0;

    // Banker's Algorithm
    while(count < n){
        bool found = false;

        for(int i=0; i<n; i++){
            if(!finish[i]){
                bool possible = true;

                for(int j=0; j<m; j++){
                    if(needed[i][j] > available[j]){
                        possible = false;
                        break;
                    }
                }

                if(possible){
                    // Release resources
                    for(int j=0; j<m; j++){
                        available[j] += allocated[i][j];
                    }

                    safeSequence[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if(!found){
            cout<<"\nSystem is not in safe state\n";
            return 0;
        }
    }

    cout<<"\nSystem is in safe state\n";
    cout<<"Safe Sequence: ";
    for(int i=0; i<n; i++){
        cout<<"P"<<safeSequence[i]<<" ";
    }

    return 0;
}