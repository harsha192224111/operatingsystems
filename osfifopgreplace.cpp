#include <stdio.h>
#include <conio.h>

int main() {
    int i, j, k, np, nf, pg[100], fr[10], avail, pgfault = 0;

    printf("enter no of pages");
    scanf("%d", &np);

    printf("enter %d pages\n", np);
    for (i = 0; i < np; i++)
        scanf("%d", &pg[i]);

    printf("enter no of frames");
    scanf("%d", &nf);
    for (i = 0; i < nf; i++)
        fr[i] = -1;

    k = 0;

    printf("ref_string \t page_frames\n");
    for (i = 0; i < np; i++) {
        printf("%d\t", pg[i]);
        avail = 0;
        for (j = 0; j < nf; j++) {
            if (fr[j] == pg[i]) {
                avail = 1;
                break; // Once the page is found, no need to check further.
            }
        }
        if (avail == 0) {
            fr[k] = pg[i];
            k = (k + 1) % nf;
            pgfault++;
        }
        for (j = 0; j < nf; j++)
            printf("%d   ", fr[j]);
        printf("\n");
    }
    printf("page faults = %d", pgfault);
    return 0;
}

