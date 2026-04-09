#include <iostream>
#include <climits>
using namespace std;

int main() {
    cout << "===== SJF Preemptive (SRTF) =====\n\n";

    int n = 4;
    int bt[] = {5, 3, 8, 6};
    int rt[4];

    for(int i=0;i<n;i++) rt[i] = bt[i];

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;

    int wt[4] = {0}, tat[4];

    while(complete != n) {
        for(int j=0;j<n;j++) {
            if(rt[j] > 0 && rt[j] < minm) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if(!check) {
            t++;
            continue;
        }

        rt[shortest]--;
        minm = rt[shortest];

        if(minm == 0) minm = INT_MAX;

        if(rt[shortest] == 0) {
            complete++;
            finish_time = t + 1;

            wt[shortest] = finish_time - bt[shortest];
            if(wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }

    for(int i=0;i<n;i++)
        tat[i] = bt[i] + wt[i];

    cout << "Process\tBT\tWT\tTAT\n";
    for(int i=0;i<n;i++)
        cout << "P" << i+1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;

    return 0;
}