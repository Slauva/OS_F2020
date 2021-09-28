#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int id;
    int arrival_time;
    int burst_time;
    int tat;
    int wt;
};

int comp(const void *elem1, const void *elem2);
void RoundRobin(struct Process *processes, int nProcess, int quant);

int main()
{

    int nProcess, quant;
    printf("How much processes you need: ");
    scanf("%d", &nProcess);
    printf("Quant: ");
    scanf("%d", &quant);

    struct Process *processes = (struct Process *)malloc(nProcess * sizeof(struct Process));

    for (int i = 0; i < nProcess; i++)
    {
        printf("Process #%d init\n", i);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i + 1;
    }

    RoundRobin(processes, nProcess, quant);

    return 0;
}

int comp(const void *elem1, const void *elem2)
{
    struct Process f = *((struct Process *)elem1);
    struct Process s = *((struct Process *)elem2);
    if (f.tat > s.tat)
        return 1;
    if (f.tat < s.tat)
        return -1;
    return 0;
}

void RoundRobin(struct Process *processes, int nProcess, int quant)
{
    float aveTAT, aveWT, CT, totalTAT = 0, totalWT = 0;
    int *temp = (int *)malloc(nProcess * sizeof(int));
    int *wt = (int *)malloc(nProcess * sizeof(int));
    int *tat = (int *)malloc(nProcess * sizeof(int));

    for (int i = 0; i < nProcess; i++)
        temp[i] = processes[i].burst_time;

    int t = 0;
    while (1)
    {
        int done = 1;
        for (int i = 0; i < nProcess; i++)
        {
            if (temp[i] > 0)
            {
                done = 0;
                if (temp[i] > quant)
                {
                    t += quant;
                    temp[i] -= quant;
                }
                else
                {
                    t += temp[i];
                    wt[i] = t - processes[i].burst_time;
                    temp[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }

    for (int i = 0; i < nProcess; i++)
        tat[i] = processes[i].burst_time + wt[i];

    printf("\n\nProcess\t CT\t TAT\t WT\n");

    for (int i = 0; i < nProcess; i++)
    {
        totalWT += wt[i];
        totalTAT += tat[i];
        processes[i].tat = tat[i];
        processes[i].wt = wt[i];
    }

    qsort(processes, nProcess, sizeof(struct Process), comp);
    for (int i = 0; i < nProcess; i++)
    {
        printf("%d\t %d\t %d\t %d\t\n", processes[i].id, processes[i].tat, processes[i].tat, processes[i].wt);
    }

    printf("Average TAT: %.1f\n", (float)totalTAT / (float)nProcess);
    printf("Average WT: %.1f\n", (float)totalWT / (float)nProcess);
}