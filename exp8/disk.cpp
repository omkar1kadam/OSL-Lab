#include <iostream>
#include <cmath>
using namespace std;

// -------- SORT FUNCTION --------
void sortArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// ================= FCFS =================
void FCFS(int arr[], int n, int head)
{
    int seek = 0;
    cout << "\nFCFS: " << head;

    for(int i = 0; i < n; i++)
    {
        int distance = abs(arr[i] - head);
        seek += distance;
        head = arr[i];
        cout << " -> " << head;
    }

    cout << "\nTotal Seek = " << seek << endl;
}

// ================= SSTF =================
void SSTF(int arr[], int n, int head)
{
    int seek = 0;
    bool visited[100] = {false};

    cout << "\nSSTF: " << head;

    for(int i = 0; i < n; i++)
    {
        int minDist = 9999, index = -1;

        for(int j = 0; j < n; j++)
        {
            if(!visited[j] && abs(arr[j] - head) < minDist)
            {
                minDist = abs(arr[j] - head);
                index = j;
            }
        }

        seek += minDist;
        head = arr[index];
        visited[index] = true;

        cout << " -> " << head;
    }

    cout << "\nTotal Seek = " << seek << endl;
}

// ================= SCAN =================
void SCAN(int arr[], int n, int head)
{
    int seek = 0;
    sortArray(arr, n);

    cout << "\nSCAN: " << head;

    int i;
    for(i = 0; i < n; i++)
    {
        if(arr[i] > head)
            break;
    }

    // move right
    for(int j = i; j < n; j++)
    {
        seek += abs(arr[j] - head);
        head = arr[j];
        cout << " -> " << head;
    }

    // reverse
    for(int j = i - 1; j >= 0; j--)
    {
        seek += abs(arr[j] - head);
        head = arr[j];
        cout << " -> " << head;
    }

    cout << "\nTotal Seek = " << seek << endl;
}

// ================= MAIN =================
int main()
{
    // Hardcoded values (from your doc)
    int arr[] = {98,183,37,122,14,124,65,67};
    int n = 8;
    int head = 53;

    FCFS(arr, n, head);
    SSTF(arr, n, head);
    SCAN(arr, n, head);

    return 0;
}