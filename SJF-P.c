#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, time = 0, smallest;
    int at[10], bt[10], rt[10];
    int wt[10], tat[10], complete = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input arrival time and burst time
    for(i = 0; i < n; i++)
    {
        printf("Enter Arrival Time for P%d: ", i+1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];   // Remaining time
    }

    while(complete != n)
    {
        smallest = -1;
        int min = INT_MAX;

        // Find process with smallest remaining time
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min)
            {
                min = rt[i];
                smallest = i;
            }
        }

        if(smallest == -1)
        {
            time++;
            continue;
        }

        rt[smallest]--;

        // If process completes
        if(rt[smallest] == 0)
        {
            complete++;
            int finish = time + 1;

            wt[smallest] = finish - at[smallest] - bt[smallest];
            if(wt[smallest] < 0)
                wt[smallest] = 0;

            tat[smallest] = bt[smallest] + wt[smallest];

            avg_wt += wt[smallest];
            avg_tat += tat[smallest];
        }

        time++;
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}
