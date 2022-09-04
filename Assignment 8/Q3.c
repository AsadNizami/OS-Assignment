#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <fcntl.h>
#include <string.h>
#define forn(i, n) for(int i=0; i<n; i++)

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

void *first(int c[3][3]){
	for(int i=0; i<3; i++){
		int sum = 0;
		for(int j=0; j<3; j++){
			sum += a[0][j] * b[j][i];
		}
		c[0][i] = sum;
	}
}

void *second(int c[3][3]){
	for(int i=0; i<3; i++){
		int sum = 0;
		for(int j=0; j<3; j++){
			sum += a[1][j] * b[j][i];
		}
		c[1][i] = sum;
	}
}

void *third(int c[3][3]){
	for(int i=0; i<3; i++){
		int sum = 0;
		for(int j=0; j<3; j++){
			sum += a[2][j] * b[j][i];
		}
		c[2][i] = sum;
	}
}

int main(){
	key_t keyr = ftok("r.txt", 65);
	int shmrow = shmget(keyr, sizeof(int[3][3]), 0666|IPC_CREAT);
	int (*c)[3];
	
	c = shmat(shmrow, NULL, 0);
	
	int cpid1 = fork();

	if (cpid1 != 0){
		int cpid2 = fork();
		if (cpid2 != 0){
			first(c);
			shmdt(c);
		}
		else{
			second(c);
			shmdt(c);
		}
		exit(0);
	}
	else{
	third(c);
		sleep(0.5);
		forn(i, 3){
			forn(j, 3){
				printf("%d ", c[i][j]);}
			printf("\n");
		}	
		exit(0);
	}
	shmctl(shmrow, IPC_RMID, NULL);
}

