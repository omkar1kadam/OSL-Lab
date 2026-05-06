#include<iostream>
using namespace std;

int main() {

    int n;

    cout<<"Enter number of processes: ";
    cin>>n;

    int bt[n], pr[n], wt[n], tat[n];

    for(int i=0;i<n;i++) {

        cout<<"BT of P"<<i+1<<": ";
        cin>>bt[i];

        cout<<"Priority of P"<<i+1<<": ";
        cin>>pr[i];
    }

    for(int i=0;i<n-1;i++) {

        for(int j=i+1;j<n;j++) {

            if(pr[i] > pr[j]) {

                swap(pr[i], pr[j]);
                swap(bt[i], bt[j]);
            }
        }
    }

    wt[0] = 0;

    for(int i=1;i<n;i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    for(int i=0;i<n;i++) {
        tat[i] = wt[i] + bt[i];
    }

    cout<<"\nBT\tPR\tWT\tTAT\n";

    for(int i=0;i<n;i++) {
        cout<<bt[i]<<"\t"<<pr[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
    }

    return 0;
}