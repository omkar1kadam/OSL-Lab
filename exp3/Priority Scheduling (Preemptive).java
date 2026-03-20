import java.util.*;

class PriorityPreemptive {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] bt = new int[n];
        int[] pr = new int[n];
        int[] rem = new int[n];
        int[] wt = new int[n];
        int[] tat = new int[n];

        for (int i = 0; i < n; i++) {
            bt[i] = sc.nextInt();
            pr[i] = sc.nextInt();
            rem[i] = bt[i];
        }

        int complete = 0, time = 0;
        int min = Integer.MAX_VALUE, shortest = 0;
        boolean found = false;

        while (complete != n) {

            for (int i = 0; i < n; i++) {
                if (pr[i] < min && rem[i] > 0) {
                    min = pr[i];
                    shortest = i;
                    found = true;
                }
            }

            if (!found) {
                time++;
                continue;
            }

            rem[shortest]--;

            if (rem[shortest] == 0) {
                complete++;
                int finish = time + 1;

                wt[shortest] = finish - bt[shortest];
                if (wt[shortest] < 0) wt[shortest] = 0;
            }

            min = Integer.MAX_VALUE;
            found = false;
            time++;
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
