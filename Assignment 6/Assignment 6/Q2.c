#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
	char *msg_parent = "Message from parent\n";
	char *msg_child = "Message from child\n";
	int n = strlen(msg_parent);
	
	int fd1[2], fd2[2];
	
	pipe(fd1);
	pipe(fd2);
	
	int cpid = fork();
	
	if (cpid == 0){ // child
		char buf[1024];
		sleep(1);
		int k = read(fd1[0], buf, 1024);
		printf("Inside child\n %s \n", buf);
		write(fd2[1], msg_child, k);
	}
	else{
		char buf[1024];
		write(fd1[1], msg_parent, 1024);
		sleep(2);
		int k = read(fd2[0], buf, 1024);
		printf("Inside parent\n %s", buf);	
	}
}
