#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int t_count = 0;
int t_print = 1;
int t_sleep = 0;

void *consumer()
{
    while (1)
    {
        if (!t_sleep)
            continue;

        while (t_count > 0)
            t_count--;

        if (t_print)
        {
            printf("Consumer terminal: %d\n", t_count);
            t_print = 0;
        }

        t_sleep = 0;
    }
    pthread_exit(NULL);
}

void *producer()
{
    while (1)
    {
        if (t_sleep)
            continue;

        while (t_count < 10)
            t_count++;

        if (t_print)
        {
            printf("Producer terminal: %d\n", t_count);
            t_print = 0;
        }

        t_sleep = 1;
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t producer_t, consumer_t;
    pthread_create(&producer_t, NULL, producer, NULL);
    pthread_create(&consumer_t, NULL, consumer, NULL);

    while (1)
    {
        t_print = 1;
        sleep(60);
    }

    pthread_join(producer_t, NULL);
    pthread_join(consumer_t, NULL);

    exit(0);
}