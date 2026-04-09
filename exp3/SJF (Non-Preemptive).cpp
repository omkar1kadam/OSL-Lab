#include <iostream>
using namespace std;

int main() {
    cout << "===== SJF Non-Preemptive =====\n\n";

    int n = 4;
    int bt[] = {5, 3, 8, 6};
    int wt[4] = {0}, tat[4];

    // Sorting
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(bt[i] > bt[j]){
                swap(bt[i], bt[j]);
            }
        }
    }

    for(int i=1;i<n;i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(int i=0;i<n;i++)
        tat[i] = wt[i] + bt[i];

    cout << "Process\tBT\tWT\tTAT\n";
    for(int i=0;i<n;i++)
        cout << "P" << i+1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;

    return 0;
}