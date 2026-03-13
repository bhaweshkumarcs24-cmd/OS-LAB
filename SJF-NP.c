#include <stdio.h>

int main()
{
    int n, i, j, pos;
    int at[10], bt[10], wt[10], tat[10], ct[10];
    int temp;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter Arrival Time of P%d: ",i+1);
        scanf("%d",&at[i]);

        printf("Enter Burst Time of P%d: ",i+1);
        scanf("%d",&bt[i]);
    }

    // Sorting processes according to burst time
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j] < bt[pos])
                pos=j;
        }

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = at[i];
        at[i] = at[pos];
        at[pos] = temp;
    }

    wt[0] = 0;

    for(i=1;i<n;i++)
    {
        wt[i] = 0;
        for(j=0;j<i;j++)
            wt[i] += bt[j];
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");

    for(i=0;i<n;i++)
    {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],wt[i],tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f",avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n",avg_tat/n);

    return 0;
}
