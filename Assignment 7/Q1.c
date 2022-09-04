#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int c[3][3];
int a[3][3] = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}	
	};

int b[3][3] = {
		{1, 1, 1},
		{2, 2, 3},
		{1, 1, 4}	
	};
	
void *first(){
	for(int i=0; i<3; i++){
		int sum = 0;
		for(int j=0; j<3; j++){
			sum += a[0][j] * b[j][i];
		}
		c[0][i] = sum;
	}
}

void *second(){
	for(int i=0; i<3; i++){
		int sum = 0;
		for(int j=0; j<3; j++){
			sum += a[1][j] * b[j][i];
		}
		c[1][i] = sum;
	}
}

void *third(){
	for(int i=0; i<3; i++){
		int sum = 0;
		for(int j=0; j<3; j++){
			sum += a[2][j] * b[j][i];
		}
		c[2][i] = sum;
	}
}

int main(){
	pthread_t t1;
	pthread_t t2;
	pthread_t t3;
	
	pthread_create(&t1, NULL, first, NULL);
	pthread_create(&t2, NULL, second, NULL);
	pthread_create(&t3, NULL, third, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}
