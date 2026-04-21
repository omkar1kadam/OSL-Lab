#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// Utility to print frames
void printFrames(vector<int> &frames, int capacity) {
    for (int i = 0; i < capacity; i++) {
        if (i < frames.size())
            cout << frames[i] << " ";
        else
            cout << "- ";
    }
}

// ---------------- FIFO ----------------
void FIFO(int pages[], int n, int capacity) {
    queue<int> q;
    unordered_set<int> s;
    vector<int> frames;

    int faults = 0;

    cout << "\n--- FIFO ---\n";

    for (int i = 0; i < n; i++) {
        cout << "Page " << pages[i] << " -> ";

        if (s.find(pages[i]) == s.end()) {
            faults++;

            if (q.size() == capacity) {
                int val = q.front(); q.pop();
                s.erase(val);

                // remove from frames
                for (int j = 0; j < frames.size(); j++) {
                    if (frames[j] == val) {
                        frames.erase(frames.begin() + j);
                        break;
                    }
                }
            }

            q.push(pages[i]);
            s.insert(pages[i]);
            frames.push_back(pages[i]);

            cout << "FAULT | ";
        } else {
            cout << "HIT   | ";
        }

        printFrames(frames, capacity);
        cout << endl;
    }

    cout << "Total Faults = " << faults << endl;
}

// ---------------- LRU ----------------
void LRU(int pages[], int n, int capacity) {
    vector<int> frames;
    int faults = 0;

    cout << "\n--- LRU ---\n";

    for (int i = 0; i < n; i++) {
        cout << "Page " << pages[i] << " -> ";

        bool found = false;

        for (int j = 0; j < frames.size(); j++) {
            if (frames[j] == pages[i]) {
                found = true;

                // move to end
                frames.erase(frames.begin() + j);
                frames.push_back(pages[i]);
                break;
            }
        }

        if (!found) {
            faults++;

            if (frames.size() == capacity)
                frames.erase(frames.begin());

            frames.push_back(pages[i]);
            cout << "FAULT | ";
        } else {
            cout << "HIT   | ";
        }

        printFrames(frames, capacity);
        cout << endl;
    }

    cout << "Total Faults = " << faults << endl;
}

// ---------------- OPTIMAL ----------------
bool isPresent(vector<int> &frames, int page) {
    for (int x : frames)
        if (x == page) return true;
    return false;
}

void Optimal(int pages[], int n, int capacity) {
    vector<int> frames;
    int faults = 0;

    cout << "\n--- OPTIMAL ---\n";

    for (int i = 0; i < n; i++) {
        cout << "Page " << pages[i] << " -> ";

        if (!isPresent(frames, pages[i])) {
            faults++;

            if (frames.size() < capacity) {
                frames.push_back(pages[i]);
            } else {
                int index = -1, farthest = i;

                for (int j = 0; j < frames.size(); j++) {
                    int k;
                    for (k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k]) break;
                    }

                    if (k == n) {
                        index = j;
                        break;
                    }

                    if (k > farthest) {
                        farthest = k;
                        index = j;
                    }
                }

                frames[index] = pages[i];
            }

            cout << "FAULT | ";
        } else {
            cout << "HIT   | ";
        }

        printFrames(frames, capacity);
        cout << endl;
    }

    cout << "Total Faults = " << faults << endl;
}

// ---------------- MAIN ----------------
int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    FIFO(pages, n, capacity);
    LRU(pages, n, capacity);
    Optimal(pages, n, capacity);

    return 0;
}