#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdint.h>

sem_t ch[5];
char st[6] = { '-', '-', '-', '-', '-' };

void printst() {
    int i;
    printf("\n");
    for (i = 0; i < 5; i++)
        printf("   %c", st[i]);
}

void *philosopher(void *arg) {
   long int n = (intptr_t)arg;

    // p is hungry
    st[n] = 'h';
    printst();

    // acquire left and right chopsticks
    sem_wait(&ch[n]);
    sem_wait(&ch[(n + 1) % 5]);

    // p is eating
    st[n] = 'e';
    printst();
    sleep(1);

    // release chopsticks
    sem_post(&ch[(n + 1) % 5]);
    sem_post(&ch[n]);

    // p is thinking
    st[n] = 't';
    printst();
    pthread_exit(NULL);
}

int main() {
    pthread_t p[5];
    long int i, j;

    // initialize semaphore
    for (i = 0; i < 5; i++)
        sem_init(&ch[i], 0, 1);
        
        printf("\n");
        for(i=0;i<5;i++)
        printf(" p[%ld]",i);

    // create threads for philosophers
    for (i = 0; i < 5; i++)
        pthread_create(&p[i], NULL, philosopher, (void *)i);

    // join threads
    for (i = 0; i < 5; i++)
        pthread_join(p[i], NULL);

    /* destroy semaphores
    for (i = 0; i < 5; i++)
        sem_destroy(&ch[i]);*/

    return 0;
}

