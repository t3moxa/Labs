#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int ready = 0;

void* producer(void*)
{
    for (int i = 0; i<5; i++)
    {
        pthread_mutex_lock(&mutex);
        if (ready == 1)
            {
            pthread_mutex_unlock(&mutex);
            continue;
        }
        ready = 1;
        cout << "Message provided " << i << endl;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }   
    return nullptr;
}

void* consumer(void*)
{
    for (int i = 0; i<5; i++)
    {
        pthread_mutex_lock(&mutex);
        while (ready == 0)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        ready = 0;
        cout << "Message consumed " << i << endl;
        pthread_mutex_unlock(&mutex);
    }
    return nullptr;
}

int main() 
{
    pthread_t producerThread;
    pthread_t consumerThread;
    pthread_create(&producerThread, nullptr, producer, nullptr);
    pthread_create(&consumerThread, nullptr, consumer, nullptr);
    pthread_join(producerThread, nullptr);
    pthread_join(consumerThread, nullptr);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}