import java.util.*;

class RoundRobin {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); // number of processes
        int[] bt = new int[n]; // burst time
        int[] rem_bt = new int[n]; // remaining time
        int[] wt = new int[n]; // waiting time
        int[] tat = new int[n]; // turnaround time

        for (int i = 0; i < n; i++) {
            bt[i] = sc.nextInt();
            rem_bt[i] = bt[i];
        }

        int quantum = sc.nextInt();

        int time = 0;

        while (true) {
            boolean done = true;

            for (int i = 0; i < n; i++) {
                if (rem_bt[i] > 0) {
                    done = false;

                    if (rem_bt[i] > quantum) {
                        time += quantum;
                        rem_bt[i] -= quantum;
                    } else {
                        time += rem_bt[i];
                        wt[i] = time - bt[i];
                        rem_bt[i] = 0;
                    }
                }
            }

            if (done) break;
        }

        for (int i = 0; i < n; i++) {
            tat[i] = bt[i] + wt[i];
        }

        System.out.println("Process\tWT\tTAT");
        for (int i = 0; i < n; i++) {
            System.out.println(i + "\t" + wt[i] + "\t" + tat[i]);
        }

        sc.close();
    }
}
