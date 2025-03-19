#include <stdio.h>
#include <limits.h>

#define MAX 10

struct process {
    int id, AT, BT, CT, TAT, WT, RT, remaining_BT;
    int completed;
};

void calculate_SJF_Preemptive(struct process p[], int n) {
    int completed = 0, currentTime = 0;
    
    for (int i = 0; i < n; i++) {
        p[i].remaining_BT = p[i].BT;
        p[i].RT = -1;
    }

    while (completed != n) {
        int shortest = -1, minBT = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].AT <= currentTime && p[i].remaining_BT < minBT) {
                minBT = p[i].remaining_BT;
                shortest = i;
            }
        }

        if (shortest == -1) {
            currentTime++;
        } else {
            if (p[shortest].RT == -1) {  // Set RT only on first execution
                p[shortest].RT = currentTime - p[shortest].AT;
            }

            p[shortest].remaining_BT--;
            currentTime++;

            if (p[shortest].remaining_BT == 0) {
                p[shortest].CT = currentTime;
                p[shortest].TAT = p[shortest].CT - p[shortest].AT;
                p[shortest].WT = p[shortest].TAT - p[shortest].BT;
                p[shortest].completed = 1;
                completed++;
            }
        }
    }
}

void display(struct process p[], int n) {
    float total_tat = 0, total_wt = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT, p[i].RT);
        total_tat += p[i].TAT;
        total_wt += p[i].WT;
    }

    printf("\nAverage TAT: %.2f", total_tat / n);
    printf("\nAverage WT: %.2f\n", total_wt / n);
}

int main() {
    int n;
    struct process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time (AT) for process %d: ", i + 1);
        scanf("%d", &p[i].AT);
        printf("Enter Burst Time (BT) for process %d: ", i + 1);
        scanf("%d", &p[i].BT);
        p[i].completed = 0;
    }

    calculate_SJF_Preemptive(p, n);
    display(p, n);

    return 0;
}
