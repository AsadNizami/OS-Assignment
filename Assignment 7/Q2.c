#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define SIZE 512

struct msgbuf{
	long mtype;
	char mtext[SIZE];
};

int main(){
	key_t key = ftok("./myfile", 65);
	int qid = msgget(key, IPC_CREAT|0666);
	
	struct msgbuf msg;
	msgrcv(qid, &msg, SIZE, 0, IPC_NOWAIT);
	fflush(stdout);
	printf("Message received: %s\n", msg.mtext);

}
