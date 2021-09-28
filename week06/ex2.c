#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int id;
    int arrival_time;
    int burst_time;
};

int comp(const void *elem1, const void *elem2);
void SJF(struct Process *processes, int nProcess);

int main()
{

    int nProcess;
    printf("How much processes you need: ");
    scanf("%d", &nProcess);

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

    SJF(processes, nProcess);

    // for (int i = 0; i < nProcess; i++)
    // {
    //     printf("Process #%d: Arrival Time %d Burst Time %d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time);
    // }

    return 0;
}

int comp(const void *elem1, const void *elem2)
{
    struct Process f = *((struct Process *)elem1);
    struct Process s = *((struct Process *)elem2);
    if (f.burst_time > s.burst_time)
        return 1;
    if (f.burst_time < s.burst_time)
        return -1;
    return 0;
}

void SJF(struct Process *processes, int nProcess)
{
    float aveTAT, aveWT, CT, totalTAT = 0, totalWT = 0;

    qsort(processes, nProcess, sizeof(struct Process), comp);

    int *WT = (int *)malloc(nProcess * sizeof(int));
    WT[0] = 0;
    for (int i = 1; i < nProcess; i++)
        WT[i] = WT[i - 1] + processes[i - 1].burst_time;

    int *TAT = (int *)malloc(nProcess * sizeof(int));
    for (int i = 0; i < nProcess; i++)
        TAT[i] = WT[i] + processes[i].burst_time;

    for (int i = 0; i < nProcess; i++)
    {
        totalWT += WT[i];
        totalTAT += TAT[i];
    }

    printf("\n\nProcess\t CT\t TAT\t WT\n");
    for (int i = 0; i < nProcess; i++)
    {
        printf("%d\t %d\t %d\t %d\t\n", processes[i].id, TAT[i], TAT[i], WT[i]);
    }
    printf("Average TAT: %.1f\n", totalTAT / (float)nProcess);
    printf("Average WT: %.1f\n", totalWT / (float)nProcess);
}