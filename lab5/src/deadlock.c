#include <pthread.h>
#include <stdio.h>
#include <unistd.h> // Для sleep()

pthread_mutex_t resource1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t resource2 = PTHREAD_MUTEX_INITIALIZER;

void* thread1_func(void* arg) {
    pthread_mutex_lock(&resource1); // Захват ресурса 1
    printf("Thread 1: locked resource 1\n");
    
    sleep(1); // Имитируем работу
    
    printf("Thread 1: waiting for resource 2\n");
    pthread_mutex_lock(&resource2); // Ожидание ресурса 2
    printf("Thread 1: locked resource 2\n");

    pthread_mutex_unlock(&resource2);
    pthread_mutex_unlock(&resource1);
    return NULL;
}

void* thread2_func(void* arg) {
    pthread_mutex_lock(&resource2); // Захват ресурса 2
    printf("Thread 2: locked resource 2\n");

    sleep(1); // Имитируем работу
    
    printf("Thread 2: waiting for resource 1\n");
    pthread_mutex_lock(&resource1); // Ожидание ресурса 1
    printf("Thread 2: locked resource 1\n");

    pthread_mutex_unlock(&resource1);
    pthread_mutex_unlock(&resource2);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Program finished.\n");
    return 0;
    //ctrl+c
}
