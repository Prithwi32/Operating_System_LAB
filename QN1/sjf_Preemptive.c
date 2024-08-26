#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct process
{
    int pId, AT, BT, TAT, WT, RT, CT;
    int remT;

} Process;

void sjfP(Process[], int);

void main()
{
    int n;
    printf("Enter number of Processes: ");
    scanf("%d", &n);
    Process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Process%d",i+1);
        printf("\nEnter Arrival Time: ");
        scanf("%d", &p[i].AT);
        printf("Enter Burst Time: ");
        scanf("%d", &p[i].BT);
        p[i].pId = (i + 1);
        p[i].remT = p[i].BT;
    }
    sjfP(p, n);
    return;
}

void sjfP(Process p[], int n)
{
    int timeP[100], processTrack[100], j = -1, k = -1;
    int totalTAT = 0, totalWT = 0, totalRT = 0;
    float avgTAT = 0, avgWT = 0, avgRT = 0;
    int eT = 0;
    int remP = n;
    timeP[++j] = 0;

    while (remP)
    {
        int exec = -1;
        int sbt = 9999;
        // checking sbt process
        for (int i = 0; i < n; i++)
        {
            if (p[i].AT <= eT && p[i].remT > 0)
            {
                if (p[i].remT < sbt)
                {
                    exec = i;
                    sbt = p[i].remT;
                }
            }
        }

        // no process arrived
        if (exec == -1)
        {
            processTrack[++k] = 0;
            eT++;
            timeP[++j] = eT;
            continue;
        }

        // remT = BT
        if (p[exec].remT == p[exec].BT)
        {
            p[exec].RT = eT - p[exec].AT;
        }

        p[exec].remT--;
        eT++;
        processTrack[++k] = p[exec].pId;
        timeP[++j] = eT;

        if (p[exec].remT == 0)
        {
                p[exec].CT = eT;
                p[exec].TAT = p[exec].CT - p[exec].AT;
                p[exec].WT = p[exec].TAT - p[exec].BT;

                totalTAT += p[exec].TAT;
                totalWT += p[exec].WT;
                totalRT += p[exec].RT;
                remP--;
    }
}
printf("Observation Table:\n");
printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
for (int i = 0; i < n; i++)
{
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pId, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT, p[i].RT);
}

printf("\nGantt Chart\n(P0-->idle time)\n");
for(int i=0; i<=k; i++)
printf("|P%d\t",processTrack[i]);
printf("|\n");

for(int i=0; i<=j; i++)
printf("%d\t",timeP[i]);
printf("|\n");

avgTAT = (float)totalTAT / n;
avgWT = (float)totalWT / n;
avgRT = (float)totalRT / n;

printf("\nAverage TAT=%.2lf", avgTAT);
printf("\nAverage WT=%.2lf", avgWT);
printf("\nAverage RT=%.2lf", avgRT);
}
