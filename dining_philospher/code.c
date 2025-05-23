#include <stdio.h>

int isEating[5] = {0};

int canEat(int pos) {
    if (isEating[(pos + 4) % 5] || isEating[(pos + 1) % 5])
        return 0;
    return 1;
}

void simulate(int hungry[], int hungryCount, int mode) {
    int eaten = 0, i;

    while (eaten < hungryCount) {
        int eatingNow = 0;

        for (i = 0; i < hungryCount; i++) {
            int p = hungry[i] - 1;

            if (!isEating[p] && canEat(p)) {
                if ((mode == 1 && eatingNow == 0) || (mode == 2 && eatingNow < 2)) {
                    printf("P %d is granted to eat\n", p + 1);
                    isEating[p] = 1;
                    eatingNow++;

                    printf("P %d has finished eating\n", p + 1);
                    isEating[p] = 0;
                    eaten++;
                } else {
                    printf("P %d is waiting\n", p + 1);
                }
            } else {
                printf("P %d is waiting\n", p + 1);
            }
        }
    }
}

int main() {
    int total, hungryCount, choice;
    int hungry[5];

    printf("Enter the total number of philosophers: ");
    scanf("%d", &total);

    printf("How many are hungry: ");
    scanf("%d", &hungryCount);

    for (int i = 0; i < hungryCount; i++) {
        printf("Enter philosopher %d position (1 to %d): ", i + 1, total);
        scanf("%d", &hungry[i]);
    }

    while (1) {
        printf("\n1. One can eat at a time\n");
        printf("2. Two can eat at a time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) break;

        simulate(hungry, hungryCount, choice);
    }

    return 0;
}
