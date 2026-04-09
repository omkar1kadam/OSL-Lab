#include <iostream>
using namespace std;

int main() {
    cout << "===== Priority Scheduling (Non-Preemptive) =====\n\n";

    int n = 4;
    int bt[] = {5, 3, 8, 6};
    int priority[] = {2, 1, 4, 3};
    int wt[4] = {0}, tat[4];

    // Sort by priority
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(priority[i] > priority[j]){
                swap(priority[i], priority[j]);
                swap(bt[i], bt[j]);
            }
        }
    }

    for(int i=1;i<n;i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(int i=0;i<n;i++)
        tat[i] = wt[i] + bt[i];

    cout << "Process\tBT\tPriority\tWT\tTAT\n";
    for(int i=0;i<n;i++)
        cout << "P" << i+1 << "\t" << bt[i] << "\t" << priority[i] << "\t\t" << wt[i] << "\t" << tat[i] << endl;

    return 0;
}