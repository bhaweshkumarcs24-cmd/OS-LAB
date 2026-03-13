#include <stdio.h>

int main() {
    int n, i, j, pos, temp;
    int at[20], bt[20], pr[20];
    int ct[20], wt[20], tat[20];
    int time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority (lower number = higher priority): ");
        scanf("%d", &pr[i]);
    }

    for(i = 0; i < n; i++) {
        pos = i;
        for(j = i + 1; j < n; j++) {
            if(pr[j] < pr[pos]) {
                pos = j;
            }
        }

        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = at[i];
        at[i] = at[pos];
        at[pos] = temp;
    }

    time = at[0];

    for(i = 0; i < n; i++) {
        if(time < at[i])
            time = at[i];

        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        time = ct[i];
    }

    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
