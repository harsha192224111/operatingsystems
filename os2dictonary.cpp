#include<stdio.h>

struct dictionary
{
    char dn[10];
    char sdn[10][10];
    char fn[10][10][10];
    int ds, sds[10];
} d[100];

int main()
{
    int i, j, k, n;

    printf("Enter the number of dictionaries: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter dictionary name and size: ");
        scanf("%s %d", &d[i].dn, &d[i].ds);

        for (j = 0; j < d[i].ds; j++)
        {
            printf("Enter subdictionary name and size: ");
            scanf("%s %d", &d[i].sdn[j], &d[i].sds[j]);

            for (k = 0; k < d[i].sds[j]; k++)
            {
                printf("Enter file name: ");
                scanf("%s", &d[i].fn[j][k]);
            }
        }
    }

    printf("\nDname \t Dsize \t SDname \t SDsize \t Files\n");

    for (i = 0; i < n; i++)
    {
        printf("%s \t %d \t", d[i].dn, d[i].ds);

        for (j = 0; j < d[i].ds; j++)
        {
            printf("\t %s \t %d \t", d[i].sdn[j], d[i].sds[j]);

            for (k = 0; k < d[i].sds[j]; k++)
            {
                printf("%s ", d[i].fn[j][k]);
            }
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}

