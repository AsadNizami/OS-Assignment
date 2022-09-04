#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int count = 0;

void *inc(){
	int i=0;
	
	while (i<1000){	
		count += 1;
		i++;
		//printf("T1 %d \n", i);
	}
}

void *dec(){
	int i=0;
	
	while (i<1000){	
		count -= 1;
		i++;
		//printf("T2 %d \n", i);
	}
}

int main(){
	pthread_t t1;
	pthread_t t2;
	
	pthread_create(&t1, NULL, inc, NULL);
	pthread_create(&t2, NULL, dec, NULL);
	
	pthread_join(t1, NULL);
	//pthread_join(t2, NULL);
	
	printf("%d", count);
	// Although the two thread are operating on the same variabel, they are not doing it simultaneously. One of the thread stops.	
}
