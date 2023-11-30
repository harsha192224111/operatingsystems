#include<stdio.h>
#include<conio.h>
struct process{
    int pid;
    int at;
    int bt;
    int prt;
    int st;
    int ct;
    int tat;
    int wt;
    int rt;
} p[100];

int main() {
    int i, n, ttat = 0, twt = 0, trt = 0;
    float atat, awt, art;

    int iscomp[100] = {0};
    int rembt[100];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time of process %d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &p[i].bt);
        printf("Enter priority of process %d: ", i + 1);
        scanf("%d", &p[i].prt);
        rembt[i] = p[i].bt;
        p[i].pid = i + 1;
        printf("\n");
    }

    int comp = 0;
    int currtime = 0;
    while (comp != n) {
        int idx = -1;
        int max = -1;
        for (i = 0; i < n; i++) {
            if (p[i].at <= currtime && iscomp[i] == 0) {
                if (p[i].prt > max) {
                    max = p[i].prt;
                    idx = i;
                }
                if (p[i].prt == max) {
                    if (p[i].at < p[idx].at) {
                        max = p[i].prt;
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            if (rembt[idx] == p[idx].bt) {
                p[idx].st = currtime;
            }
            rembt[idx] -= 1;
            currtime++;

            if (rembt[idx] == 0) {
                p[idx].ct = currtime;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                p[idx].rt = p[idx].st - p[idx].at;

                ttat += p[idx].tat;
                twt += p[idx].wt;
                trt += p[idx].rt;

                iscomp[idx] = 1;
                comp++;
            }
        } else {
            currtime++;
        }
    }

    atat = (float) ttat / n;
    awt = (float) twt / n;
    art = (float) trt / n;

    printf("P\tAT\tBT\tPRT\tST\tCT\tTAT\tWT\tRT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].prt, p[i].st, p[i].ct,
               p[i].tat, p[i].wt, p[i].rt);
    }

    return 0;
}

