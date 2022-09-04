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

sem_t *m1, *m2, *m3;
int count = 1;

void *fun1(void *args){
	forn(_, 10) {printf("%d ", count); count++;}
	sem_post(m1);
}
void *fun2(void *args){
	sem_wait(m1);
	forn(_, 10) {printf("%d ", count); count++;}
	sem_post(m2);
}
void *fun3(void *args){
	sem_wait(m2);
	forn(_, 10) {printf("%d ", count); count++;}
	sem_post(m3);
}
void *fun4(void *args){
	sem_wait(m3);
	forn(_, 10) {printf("%d ", count); count++;}
}

int main(){
	char *name1 = "/sem1";
	m1 = sem_open(name1, O_CREAT, 0666, 1);
	char *name2 = "/sem2";
	m2 = sem_open(name2, O_CREAT, 0666, 1);
	char *name3 = "/sem3";
	m3 = sem_open(name3, O_CREAT, 0666, 1);
	
	pthread_t t1, t2, t3, t4;
	pthread_create(&t1, NULL, fun1, NULL);
	pthread_create(&t2, NULL, fun2, NULL);
	pthread_create(&t3, NULL, fun3, NULL);
	pthread_create(&t4, NULL, fun4, NULL);
	
	pthread_join(t4, NULL);
	printf("\n");
	
	sem_close(m1);
	sem_unlink(name1);
	sem_close(m2);
	sem_unlink(name2);
	sem_close(m3);
	sem_unlink(name3);
}

