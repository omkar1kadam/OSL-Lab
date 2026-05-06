#include<iostream>
using namespace std;

int main() {

    int n;

    cout<<"Enter number of processes: ";
    cin>>n;

    int at[n], bt[n], rt[n], ct[n], wt[n], tat[n];

    for(int i=0;i<n;i++) {

        cout<<"AT of P"<<i+1<<": ";
        cin>>at[i];

        cout<<"BT of P"<<i+1<<": ";
        cin>>bt[i];

        rt[i] = bt[i];
    }

    int completed = 0;
    int time = 0;

    while(completed < n) {

        int idx = -1;
        int minRT = 9999;

        for(int i=0 ; i<n; i++){
            if(at[i] <= time && rt[i] > 0 && bt[i] < minBT){
                minBT = bt[i];
                idx = i;
            }
        }

        if(idx != -1) {
            rt[idx]--;
            time++;
            
            if(rt[idx] == 0){
                ct[idx] = timee;
                completed++;
            }
        } else{
            time++;
        }
    }

    for(int i=0;i<n;i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout<<"\nP\tAT\tBT\tCT\tWT\tTAT\n";

    for(int i=0;i<n;i++) {
        cout<<"P"<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
    }

    return 0;
}