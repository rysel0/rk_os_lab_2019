#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
static int counter = 0;
pthread_mutex_t mutex;
 
void* minus(void *args) {
    int local;
    //Блокировка: теперь к ресурсам имеет доступ только один
    //поток, который владеет мьютексом. Он же единственный, 
    //кто может его разблокировать
    pthread_mutex_lock(&mutex);
        local = counter;
        printf("min %d\n", counter);
        local = local - 1;
        counter = local;
    pthread_mutex_unlock(&mutex);
    return NULL;
}
 
void* plus(void *args) {
    int local;
    pthread_mutex_lock(&mutex);
        local = counter;
        printf("pls %d\n", counter);
        local = local + 1;
        counter = local;
    pthread_mutex_unlock(&mutex);
    return NULL;
}
 
#define NUM_OF_THREADS 100
 
int main() {
    pthread_t threads[NUM_OF_THREADS];
    size_t i;
 
    printf("counter = %d\n", counter);
    //Инициализация мьютекса
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < NUM_OF_THREADS/2; i++) {
        pthread_create(&threads[i], NULL, minus, NULL);
    }
    for (; i < NUM_OF_THREADS; i++) {
        pthread_create(&threads[i], NULL, plus, NULL);
    }
    for (i = 0; i < NUM_OF_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    //Уничтожение мьютекса
    pthread_mutex_destroy(&mutex);
    printf("counter = %d", counter);
    return 0;
}