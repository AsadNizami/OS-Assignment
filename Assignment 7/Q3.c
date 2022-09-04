#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define size 10

int arr[size];

void *avg(){
	int i = 0;
	int curr = 0;
	while (arr[i] != -1){
		curr += arr[i];
		i += 1;
	}
	printf("Average : %f \n", (float)curr / (float)i);
}

void *min(){
	int i = 0;
	int curr = 10000000;
	while (arr[i] != -1){
		if (curr > arr[i])
			curr = arr[i];
		i += 1;
	}
	printf("Minimum: %d \n", curr);
}

void *max(){
	int i = 0;
	int curr = 0;
	while (arr[i] != -1){
		if (curr < arr[i])
			curr = arr[i];
		i += 1;
	}
	printf("Maximum : %d \n", curr);
}


int main(int argc, char** argv){
	if (argc == 1){
		printf("No arguments\n");
		exit(0);
	}
	
	for(int i=0; i<size; i++)	arr[i] = -1;
	for(int i=1; i<argc; i++)	arr[i-1] = atoi(argv[i]);

	pthread_t t0;
	pthread_t t1;
	pthread_t t2;
	
	pthread_create(&t0, NULL, avg, NULL);
	pthread_create(&t1, NULL, max, NULL);
	pthread_create(&t2, NULL, min, NULL);
	
	pthread_join(t0, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
		
}
