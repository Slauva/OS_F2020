#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *message_handler(void *id);

void main()
{
    int status, n;

    printf("Count of threads N = ");
    scanf("%d", &n);

    printf("Inited #%d threads\n", n);
    pthread_t threads[n];

    for (int i = 0; i < n; i++)
    {
        printf("Created #%d thread\n", i);
        status = pthread_create(&threads[i], NULL, message_handler, (void *)i);

        if (status != 0)
        {
            printf("Error {status: %d}", status);
            exit(-1);
        }
        pthread_join(threads[i], NULL);
    }

    exit(0);
}

void *message_handler(void *id)
{
    printf("Set thread message with id #%d\n", (int)id);
    pthread_exit(NULL);
}