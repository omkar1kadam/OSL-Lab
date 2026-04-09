#include <iostream>
using namespace std;

int main() {
    cout << "===== FCFS Scheduling =====\n\n";

    int n = 4;
    int bt[] = {5, 3, 8, 6};
    int wt[4], tat[4];

    wt[0] = 0;

    for(int i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    cout << "Process\tBT\tWT\tTAT\n";
    for(int i = 0; i < n; i++)
        cout << "P" << i+1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;

    return 0;
}