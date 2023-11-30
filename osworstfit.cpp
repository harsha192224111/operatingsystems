#include<stdio.h>
#include<conio.h>

int main() {
    int i, j, np, nb, bsize[10], psize[10], alloc[10];
    int diff = 0, idx, max;

    printf("Enter no of processes ");
    scanf("%d", &np);
    printf("Enter size of each process ");
    for (i = 0; i < np; i++)
        scanf("%d", &psize[i]);

    printf("Enter no of blocks ");
    scanf("%d", &nb);
    printf("Enter size of each block ");
    for (i = 0; i < nb; i++)
        scanf("%d", &bsize[i]);

    for (i = 0; i < np; i++)
        alloc[i] = -1;

    for (i = 0; i < np; i++) {
        idx = -1;
        max= -10;
        for (j = 0; j < nb; j++) {
            if (bsize[j] >= psize[i]) {
                diff = bsize[j] - psize[i];
                if (diff > max) {
                    max = diff;
                    idx = j;
                }
            }
        }
        alloc[i] = idx; // allocating ith process to jth block
        bsize[idx] -= psize[i];
    }

    printf("P.NO \t PSIZE \t Block No\n");
    for (i = 0; i < np; i++) {
        printf("%d\t", i);
        printf("%d \t", psize[i]);
        if (alloc[i] != -1)
            printf("%d", alloc[i] + 1);
        else
            printf("NA");
        printf("\n");
    }

    return 0;
}

