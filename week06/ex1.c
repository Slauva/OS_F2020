#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int id;
    int arrival_time;
    int burst_time;
};

void FCFS(struct Process *processes, int nProcess);

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

    // for (int i = 0; i < nProcess; i++)
    // {
    //     printf("Process #%d: Arrival Time %d Burst Time %d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time);
    // }

    FCFS(processes, nProcess);

    return 0;
}

void FCFS(struct Process *processes, int nProcess)
{
    float aveTAT, aveWT, CT, totalTAT = 0, totalWT = 0;

    int *WT = (int *)malloc(nProcess * sizeof(int));
    int *TAT = (int *)malloc(nProcess * sizeof(int));
    int *temp = (int *)malloc((nProcess + 1) * sizeof(int));

    temp[0] = 0;
    for (int i = 0; i < nProcess; i++)
    {
        temp[i + 1] = temp[i] + processes[i].burst_time;
        WT[i] = temp[i] - processes[i].arrival_time;
        TAT[i] = WT[i] + processes[i].burst_time;
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