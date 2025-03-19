#include <stdio.h>
#include <limits.h>

void sjfNonPreemptive(int n, int at[], int bt[], int p[]) {
    int ct[n], tat[n], wt[n], completed = 0, currentTime = 0, isCompleted[n];

    // Initialize isCompleted array
    for (int i = 0; i < n; i++)
        isCompleted[i] = 0;

    while (completed < n) {
        int shortest = -1, minBT = INT_MAX;

        // Find the shortest job available at the current time
        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && isCompleted[i] == 0) {
                if (bt[i] < minBT || (bt[i] == minBT && (shortest == -1 || at[i] < at[shortest]))) {
                    minBT = bt[i];
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            // If no process is available, move to the next earliest arrival time
            int nextArrival = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (!isCompleted[i] && at[i] < nextArrival) {
                    nextArrival = at[i];
                }
            }
            currentTime = nextArrival;
        } else {
            // Process execution
            ct[shortest] = currentTime + bt[shortest];
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
            isCompleted[shortest] = 1;
            currentTime = ct[shortest];
            completed++;
        }
    }

    // Printing results
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    float totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", totalWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], p[n];

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;  // Assign process IDs
        printf("Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    sjfNonPreemptive(n, at, bt, p);
    
    return 0;
}
