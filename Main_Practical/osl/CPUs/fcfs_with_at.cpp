#include<iostream>
using namespace std;

int main() {
    int n;

    cout<<"Enter number of processes: ";
    cin>>n;

    int at[n], bt[n], ct[n], wt[n], tat[n];

    for(int i=0;i<n;i++) {
        cout<<"Arrival Time of P"<<i+1<<": ";
        cin>>at[i];

        cout<<"Burst Time of P"<<i+1<<": ";
        cin>>bt[i];
    }

    ct[0] = at[0] + bt[0];

    for(int i=0; i<n; i++){
        if(ct[i-1] < at[i]){
            ct[i] = at[i] + bt[i];
        } else{
            ct[i] = ct[i-1] + bt[i];
        }
    }

    for(int i=0; i<n; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout<<"\nP\tAT\tBT\tCT\tWT\tTAT\n";

    for(int i=0;i<n;i++) {
        cout<<"P"<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
    }
    
    return 0;
}