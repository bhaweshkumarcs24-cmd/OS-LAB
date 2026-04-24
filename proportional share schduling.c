#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i;
    int tickets[10], totalTickets = 0;
    int lottery, winner = -1;

    printf("Enter number of processes (max 10): ");
    scanf("%d", &n);

    if(n <= 0 || n > 10) {
        printf("Invalid number of processes!\n");
        return 1;
    }

    for(i = 0; i < n; i++) {
        printf("Enter number of tickets for Process P%d: ", i + 1);
        scanf("%d", &tickets[i]);

        if(tickets[i] < 0) {
            printf("Tickets cannot be negative!\n");
            return 1;
        }

        totalTickets += tickets[i];
    }

    if(totalTickets == 0) {
        printf("No tickets assigned. Cannot perform lottery scheduling.\n");
        return 1;
    }

    srand(time(0));

    printf("\nTotal Tickets = %d\n", totalTickets);

    lottery = rand() % totalTickets + 1;
    printf("Winning Ticket Number: %d\n", lottery);

    int sum = 0;

    for(i = 0; i < n; i++) {
        sum += tickets[i];
        if(lottery <= sum) {
            winner = i + 1;
            break;
        }
    }

    if(winner != -1)
        printf("Process P%d wins the lottery and gets the CPU.\n", winner);
    else
        printf("Error determining winner.\n");

    return 0;
}
