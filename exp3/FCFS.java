// this code is of burst time with different arival time 
public class FCFS {

    static void findAvgTime(int bt[], int at[]) {

        int n = bt.length;

        int[] wt = new int[n];
        int[] tat = new int[n];
        int[] ct = new int[n];

        int currentTime = 0;
        int totalWT = 0, totalTAT = 0;

        for (int i = 0; i < n; i++) {

            // If CPU is idle, jump to arrival time
            if (currentTime < at[i]) {
                currentTime = at[i];
            }

            // Waiting time
            wt[i] = currentTime - at[i];

            // Completion time
            ct[i] = currentTime + bt[i];

            // Turnaround time
            tat[i] = ct[i] - at[i];

            // Move current time forward
            currentTime += bt[i];

            totalWT += wt[i];
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
