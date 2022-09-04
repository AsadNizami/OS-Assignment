#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define forn(i, n) for(int i=0; i<n; i++)

pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int count = 0;

	
void* produce(void *p){
	while(1){
		pthread_mutex_lock(&mutex);
		pthread_cond_signal(&empty);
		count += 1;
		printf("Produce: Count=%d\n", count);
		pthread_mutex_unlock(&mutex);
	}
}

void* consume(void *p){
	while(1){
		pthread_mutex_lock(&mutex);
		while(count == 0)
		pthread_cond_wait(&empty, &mutex);
		count -= 1;
		printf("Consume: Count=%d\n", count);	
		pthread_mutex_unlock(&mutex);
	}
}

int main(){
	pthread_t threads[5]; 
	
	forn(i, 5){
		if (i == 0)	pthread_create(&threads[i], NULL, produce, NULL);
		else	pthread_create(&threads[i], NULL, consume, NULL);
	}
	
	forn(i, 5)	pthread_join(threads[i], NULL);
	
}

