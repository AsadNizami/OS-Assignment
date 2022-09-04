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
	key_t key = ftok("./myfile", 65);
	int qid = msgget(key, IPC_CREAT|0666);
	
	struct msgbuf msg;
	msg.mtype = 10;
	strcpy(msg.mtext, "Hello JNU\n");
	msgsnd(qid, &msg, sizeof(msg.mtext), 0);
}

