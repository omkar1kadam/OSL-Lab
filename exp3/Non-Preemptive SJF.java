import java.util.*;

public class SJF_NonPreemptive {

    static void findAvgTime(int bt[], int at[]) {

        int n = bt.length;

        int[] wt = new int[n];
        int[] tat = new int[n];
        int[] ct = new int[n];
        boolean[] completed = new boolean[n];

        int currentTime = 0;
        int completedCount = 0;
        int totalWT = 0, totalTAT = 0;

        while (completedCount < n) {

            int idx = -1;
            int minBT = Integer.MAX_VALUE;

            // Find shortest job among arrived processes
            for (int i = 0; i < n; i++) {
                if (at[i] <= currentTime && !completed[i]) {
                    if (bt[i] < minBT) {
                        minBT = bt[i];
                        idx = i;
                    }
                }
            }

            // If no process has arrived yet
            if (idx == -1) {
                currentTime++;
            } else {
                wt[idx] = currentTime - at[idx];
                currentTime += bt[idx];
                ct[idx] = currentTime;
                tat[idx] = ct[idx] - at[idx];

                totalWT += wt[idx];
                totalTAT += tat[idx];

                completed[idx] = true;
                completedCount++;
            }
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
