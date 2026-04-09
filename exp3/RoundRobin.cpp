#include <iostream>
using namespace std;

int main() {
    cout << "===== Round Robin Scheduling =====\n\n";

    int n = 4, tq = 2;
    int bt[] = {5, 3, 8, 6};
    int rem[4], wt[4] = {0}, tat[4];

    for(int i=0;i<n;i++) rem[i]=bt[i];

    int t = 0;

    while(true) {
        bool done = true;

        for(int i=0;i<n;i++) {
            if(rem[i] > 0) {
                done = false;

                if(rem[i] > tq) {
                    t += tq;
                    rem[i] -= tq;
                } else {
                    t += rem[i];
                    wt[i] = t - bt[i];
                    rem[i] = 0;
                }
            }
        }

        if(done) break;
    }

    for(int i=0;i<n;i++)
        tat[i] = bt[i] + wt[i];

    cout << "Process\tBT\tWT\tTAT\n";
    for(int i=0;i<n;i++)
        cout << "P" << i+1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;

    return 0;
}