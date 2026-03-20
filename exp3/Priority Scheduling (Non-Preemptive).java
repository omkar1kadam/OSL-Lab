import java.util.*;

class PriorityNonPreemptive {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] bt = new int[n];
        int[] priority = new int[n];
        int[] wt = new int[n];
        int[] tat = new int[n];

        for (int i = 0; i < n; i++) {
            bt[i] = sc.nextInt();
            priority[i] = sc.nextInt();
        }

        // Sort based on priority
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (priority[i] > priority[j]) {
                    int temp;

                    temp = priority[i];
                    priority[i] = priority[j];
                    priority[j] = temp;

                    temp = bt[i];
                    bt[i] = bt[j];
                    bt[j] = temp;
                }
            }
        }

        wt[0] = 0;

        for (int i = 1; i < n; i++) {
            wt[i] = wt[i - 1] + bt[i - 1];
        }

        for (int i = 0; i < n; i++) {
            tat[i] = wt[i] + bt[i];
        }

        System.out.println("Process\tPriority\tWT\tTAT");
        for (int i = 0; i < n; i++) {
            System.out.println(i + "\t" + priority[i] + "\t\t" + wt[i] + "\t" + tat[i]);
        }

        sc.close();
    }
}
