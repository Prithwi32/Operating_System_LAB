#include <stdio.h>
#include <semaphore.h>
#include <sys/types.h>
#include <pthread.h>

sem_t wrt;
pthread_mutex_t mutex;
int numreader = 0;
int cnt = 1;

void *writer(void *wno)
{
    sem_wait(&wrt);
    cnt = cnt * 2;
    printf("\nWriter %d changed cnt to %d", *((int *)wno), cnt);
    sem_post(&wrt);
}

void *reader(void *rno)
{
    pthread_mutex_lock(&mutex);
    numreader++;
    if (numreader == 1)
        sem_wait(&wrt);
    pthread_mutex_unlock(&mutex);

    printf("\nReader %d read cnt as %d", *(int *)rno, cnt);

    pthread_mutex_lock(&mutex);
    numreader--;
    if (numreader == 0)
        sem_post(&wrt);
    pthread_mutex_unlock(&mutex);
}

int main()
{
    pthread_t read[3], write[3];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt, 0, 1);
    int a[3] = {1,2,3};

    for(int i=0; i<3; i++){
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    }
    for(int i=0; i<3; i++){
        pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
    }
    for(int i=0; i<3; i++){
        pthread_join(read[i], NULL);
    }
    for(int i=0; i<3; i++){
        pthread_join(write[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}