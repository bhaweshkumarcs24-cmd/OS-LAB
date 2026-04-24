#include <stdio.h>
#include <math.h>

int main()
{
    int C[3] = {3, 2, 2};
    int T[3] = {20, 5, 10};
    float U, bound;
    int n = 3;

    printf("Rate Monotonic Scheduling\n\n");

    printf("Tasks:\n");
    printf("T1 -> C=3 , T=20\n");
    printf("T2 -> C=2 , T=5\n");
    printf("T3 -> C=2 , T=10\n");

    /* Step 1 : CPU Utilization */
    U = (float)C[0]/T[0] + (float)C[1]/T[1] + (float)C[2]/T[2];

    /* RMS Bound calculation */
    bound = n * (pow(2, (float)1/n) - 1);

    printf("\nCPU Utilization U = %.2f\n", U);
    printf("RMS Bound for %d tasks = %.2f\n", n, bound);

    if (U <= bound)
        printf("Tasks are Schedulable\n");
    else
    {
        printf("Tasks are NOT Schedulable\n");
        return 0;
    }

    /* Step 2 : Priority */
    printf("\nPriority (Smaller period -> Higher priority)\n");
    printf("T2 > T3 > T1\n");

    /* Step 3 : Execution timeline (Corrected RMS schedule) */
    printf("\nExecution Timeline (0 - 20)\n");

    printf("0  - 2  : T2\n");
    printf("2  - 4  : T3\n");
    printf("4  - 5  : T1\n");
    printf("5  - 7  : T2\n");
    printf("7  - 9  : T1\n");
    printf("9  - 10 : Idle\n");
    printf("10 - 12 : T2\n");
    printf("12 - 14 : T3\n");
    printf("14 - 15 : T1\n");
    printf("15 - 17 : T2\n");
    printf("17 - 20 : Idle\n");

    return 0;
}
