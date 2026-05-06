#include<iostream>
using namespace std;

int main() {

    int n;

    cout<<"Enter number of processes: ";
    cin>>n;

    int at[n], bt[n], rt[n], pr[n];
    int ct[n], wt[n], tat[n];

    for(int i=0;i<n;i++) {

        cout<<"AT: ";
        cin>>at[i];

        cout<<"BT: ";
        cin>>bt[i];

        cout<<"Priority: ";
        cin>>pr[i];

        rt[i] = bt[i];
    }

    int completed = 0;
    int time = 0;

    while(completed < n) {

        int idx = -1;
        int high = 9999;

        for(int i=0;i<n;i++) {

            if(at[i] <= time && rt[i] > 0 && pr[i] < high) {

                high = pr[i];
                idx = i;
            }
        }

        if(idx != -1) {

            rt[idx]--;
            time++;

            if(rt[idx] == 0) {

                ct[idx] = time;
                completed++;
            }
        }
        else {
            time++;
        }
    }

    for(int i=0;i<n;i++) {

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout<<"\nP\tAT\tBT\tPR\tCT\tWT\tTAT\n";

    for(int i=0;i<n;i++) {

        cout<<"P"<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<pr[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
    }

    return 0;
}