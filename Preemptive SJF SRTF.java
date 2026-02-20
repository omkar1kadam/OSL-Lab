import java.util.*;

public class SJF_Preemptive {

    static void findAvgTime(int bt[], int at[]) {

        int n = bt.length;

        int[] rt = new int[n]; // remaining time
        int[] wt = new int[n];
        int[] tat = new int[n];
        int[] ct = new int[n];

        for (int i = 0; i < n; i++)
            rt[i] = bt[i];

        int complete = 0, currentTime = 0;
        int min = Integer.MAX_VALUE;
        int shortest = -1;
        boolean found = false;

        int totalWT = 0, totalTAT = 0;

        while (complete != n) {

            // Find process with minimum remaining time
            for (int i = 0; i < n; i++) {
                if (at[i] <= currentTime && rt[i] > 0 && rt[i] < min) {
                    min = rt[i];
                    shortest = i;
                    found = true;
                }
            }

            if (!found) {
                currentTime++;
                continue;
            }

            rt[shortest]--;
            min = rt[shortest];

            if (min == 0)
                min = Integer.MAX_VALUE;

            // If process completes
            if (rt[shortest] == 0) {
                complete++;
                found = false;

                ct[shortest] = currentTime + 1;
                wt[shortest] = ct[shortest] - bt[shortest] - at[shortest];

                if (wt[shortest] < 0)
                    wt[shortest] = 0;

                totalWT += wt[shortest];
            }

            currentTime++;
        }

        for (int i = 0; i < n; i++) {
            tat[i] = bt[i] + wt[i];
            totalTAT += tat[i];
        }

        System.out.println("Process\tBT\tAT\tWT\tTAT\tCT");
        for (int i = 0; i < n; i++) {
            System.out.println((i+1) + "\t\t" + bt[i] + "\t" + at[i] +
                               "\t" + wt[i] + "\t" + tat[i] + "\t" + ct[i]);
        }

        System.out.println("\nAverage Waiting Time = " + (double) totalWT / n);
        System.out.println("Average Turnaround Time = " + (double) totalTAT / n);
    }

    public static void main(String[] args) {

        int burst_time[] = {5, 9, 6};
        int arrival_time[] = {0, 3, 6};

        findAvgTime(burst_time, arrival_time);
    }
}
