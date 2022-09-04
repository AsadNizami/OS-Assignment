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

int main(){
	char *name = "/sem1";
	sem_t *mutex = sem_open(name, O_CREAT, 0666, 1);
	key_t key = ftok("f1.txt", 65);
	int shmid = shmget(key, 1024, 0666|IPC_CREAT);
	int cpid = fork();

	if (cpid == 0){
		
		forn(_, 5){
			sleep(1);
			sem_wait(mutex);
			char *buffer = (char*) shmat(shmid, NULL, 0);
			printf("Child (Reading): %s \n", buffer);
			fflush(stdout);
			sem_post(mutex);
		}
	}
	else{
		forn(_, 5){
			sem_wait(mutex);
			char* buffer = (char*)shmat(shmid, NULL, 0);
			printf("Parent (Write): ");
			fflush(stdout);
			fgets(buffer, 512, stdin);
			sem_post(mutex);
			sleep(1);
		}
	}
	shmctl(shmid, IPC_RMID, NULL);
	sem_close(mutex);
	sem_unlink(name);
}

