#include <stdio.h>

int main() {
    int n, i, time = 0, remain, tq;
    int bt[20], rt[20], wt[20], tat[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while(remain != 0) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                if(rt[i] <= tq) {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                    remain--;
                } else {
                    rt[i] -= tq;
                    time += tq;
                }
            }
        }
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
