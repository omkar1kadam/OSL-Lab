#include<iostream>
using namespace std;

int main(){
    int n;

    cout<<"Number of Processes are: ";
    cin>>n;

    int bt[n],wt[n],tat[n];

    for(int i=0; i<n; i++){
        cout<<"BT for n: "<<i<<" : ";
        cin>>bt[i];
    }

    wt[0] = 0;

    for(int i=1; i<n; i++){
        wt[i] = wt[i-1] + bt[i-1];
    }

    for(int i=0; i<n; i++){
        tat[i] = wt[i] + bt[i];
    }

    cout<<"\nProcess\tBT\tWT\tTAT\n";

    for(int i=0;i<n;i++) {
        cout<<"P"<<i+1<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
    }

    return 0;
}