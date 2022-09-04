#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string.h>

#define SIZE 512

struct msgbuf{
	long mtype;
	char mtext[SIZE];
};

int main(){
	struct msgbuf msg;
	key_t key = ftok("./myfile", 65);

	int mid = msgget(key, 0666);
	if (mid == -1){
		printf("No message queue found \n");
		exit(0);
	}
	
	if (msgctl(mid, IPC_RMID, NULL) == -1){
		printf("Could not delete\n");
		exit(0);
	}
	printf("Message deleted\n");

}
