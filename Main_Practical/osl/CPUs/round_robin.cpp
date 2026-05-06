#include<iostream>
using namespace std;

int main() {

    int n, tq;

    cout<<"Enter number of processes: ";
    cin>>n;

    int bt[n], rt[n], wt[n], tat[n];

    for(int i=0;i<n;i++) {

        cout<<"BT of P"<<i+1<<": ";
        cin>>bt[i];

        rt[i] = bt[i];
    }

    cout<<"Enter Time Quantum: ";
    cin>>tq;

    int time = 0;

    while(true) {

        bool done = true;

        for(int i=0;i<n;i++) {

            if(rt[i] > 0) {

                done = false;

                if(rt[i] > tq) {

                    time += tq;
                    rt[i] -= tq;
                }
                else {

                    time += rt[i];

                    wt[i] = time - bt[i];

                    rt[i] = 0;
                }
            }
        }

        if(done)
            break;
    }

    for(int i=0;i<n;i++) {
        tat[i] = wt[i] + bt[i];
    }

    cout<<"\nP\tBT\tWT\tTAT\n";

    for(int i=0;i<n;i++) {
        cout<<"P"<<i+1<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
    }

    return 0;
}