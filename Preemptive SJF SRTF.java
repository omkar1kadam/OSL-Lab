import java.util.Scanner;

public class SJFPreemptive {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();

        int[] AT = new int[n];
        int[] BT = new int[n];
        int[] RT = new int[n];
        int[] CT = new int[n];
        int[] TAT = new int[n];
        int[] WT = new int[n];

        // Input
        System.out.println("\nEnter Arrival Time and Burst Time:");
        for (int i = 0; i < n; i++) {
            System.out.println("Process " + (i + 1) + ":");
            System.out.print("Arrival Time: ");
            AT[i] = sc.nextInt();
            System.out.print("Burst Time: ");
            BT[i] = sc.nextInt();

            RT[i] = BT[i];   // Remaining Time = Burst Time
        }

        int currentTime = 0;
        int completed = 0;

        while (completed < n) {

            int idx = -1;
            int minRT = Integer.MAX_VALUE;

            // Find process with smallest remaining time
            for (int i = 0; i < n; i++) {
                if (AT[i] <= currentTime && RT[i] > 0) {
                    if (RT[i] < minRT) {
                        minRT = RT[i];
                        idx = i;
                    }
                }
            }

            if (idx == -1) {
                // CPU idle
                currentTime++;
            } else {
                // Execute for 1 unit time
                RT[idx]--;
                currentTime++;

                // If process finished
                if (RT[idx] == 0) {
                    completed++;
                    CT[idx] = currentTime;
                    TAT[idx] = CT[idx] - AT[idx];
                    WT[idx] = TAT[idx] - BT[idx];
                }
            }
        }

        // Output
        System.out.println("\nProcess\tAT\tBT\tCT\tTAT\tWT");
        for (int i = 0; i < n; i++) {
            System.out.println("P" + (i + 1) + "\t"
                    + AT[i] + "\t"
                    + BT[i] + "\t"
                    + CT[i] + "\t"
                    + TAT[i] + "\t"
                    + WT[i]);
        }

        float totalWT = 0, totalTAT = 0;
        for (int i = 0; i < n; i++) {
            totalWT += WT[i];
            totalTAT += TAT[i];
        }

        System.out.println("\nAverage Waiting Time = " + (totalWT / n));
        System.out.println("Average Turnaround Time = " + (totalTAT / n));

        sc.close();
    }
}
