#include<stdio.h>

int main() {
    int p[10], at[10], bt[10], ct[10], tat[10], wt[10], i, j, temp = 0, n;
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter %d processes: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter %d arrival times: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter %d burst times: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    // Sorting based on arrival time
    for (i = 0; i < n; i++) {
        for (j = 0; j < (n - i - 1); j++) {
            if (at[j] > at[j + 1]) {
                // Swap process IDs
                temp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = temp;

                // Swap arrival times
                temp = at[j + 1];
                at[j + 1] = at[j];
                at[j] = temp;

                // Swap burst times
                temp = bt[j + 1];
                bt[j + 1] = bt[j];
                bt[j] = temp;
            }
        }
    }

     /* calculating 1st ct */
    ct[0]=at[0]+bt[0];
    /* calculating 2 to n ct */
    for(i=1;i<n;i++)
    {  
      //when proess is ideal in between i and i+1
      temp=0;
     if(ct[i-1]<at[i])
     {
        temp=at[i]-ct[i-1];
     }
     ct[i]=ct[i-1]+bt[i]+temp;
    }

    // Calculate turnaround time and waiting time
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time");
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        atat += tat[i];
        awt += wt[i];

        printf("\n%d\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Calculate average turnaround time and average waiting time
    atat = atat / n;
    awt = awt / n;

    printf("\n\nAverage Turnaround Time: %.2f", atat);
    printf("\nAverage Waiting Time: %.2f\n", awt);

    return 0;
}

