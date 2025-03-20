#include <stdio.h>

void sort(int proc_id[],int at[],int bt[],int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = proc_id[i];
                proc_id[i] = proc_id[j];
                proc_id[j] = temp;
}}}
}
void main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int proc_id[n],at[n],bt[n],ct[n],tat[n],wt[n];
    double avg_tat = 0.0, avg_wt = 0.0;
for (int i = 0; i < n; i++) {
        proc_id[i] = i + 1;
    }
printf("Enter arrival time:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }
printf("Enter burst time:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }
sort(proc_id, at, bt, n);
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (c < at[i]) {
            c = at[i];
        }
        ct[i] = c + bt[i];
        c = ct[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }


    double total_tat = 0, total_wt = 0;
    for (int i = 0; i < n; i++) {
        total_tat += tat[i];
        total_wt += wt[i];
    }

    avg_tat = total_tat / n;
    avg_wt = total_wt / n;


    printf("\nFCFS scheduling:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", proc_id[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage turnaround time: %f ms\n", avg_tat);
    printf("Average waiting time: %f ms\n", avg_wt);
}
