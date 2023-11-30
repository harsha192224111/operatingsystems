#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, arr[20], h, min, idx, i, j, iscomp[10], diff, seektime = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter request sequence: ");
    
    for (i = 0; i < n; i++)
    {	
        scanf("%d", &arr[i]);
        iscomp[i] = 0;
    }
    
    printf("Enter head position: ");
    scanf("%d", &h);

    for (i = 0; i < n; i++)
    {
        min = 99999;
        idx = -1;
        for (j = 0; j < n; j++)
        {
            if (iscomp[j] == 0)
            {
                diff = abs(h - arr[j]);// Fix: Changed 'i' to 'j' for correct index assignment
                if (min > diff)
                {
                    min = diff;
                    idx = j;  // Fix: Changed 'i' to 'j' for correct index assignment
                }
            }
        }
        if (iscomp[idx] == 0)
        {
            seektime += min;
            h = arr[idx];
            iscomp[idx] = 1;
        }
    }
    printf("Total seek time is %d\n", seektime);
    return 0;
}

