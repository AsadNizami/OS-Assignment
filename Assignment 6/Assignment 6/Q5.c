#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	char *msg_parent = "Message from parent\n";
	char *msg_child = "Message from child\n";
	
	char *p_name = "parent";
	char *c_name = "child";
	mknod(p_name, S_IFIFO|0666, 0);
	mknod(c_name, S_IFIFO|0666, 0);
	
	int cpid = fork();
	
	if (cpid == 0){ // child
		char buff[1024];
		int writefd = open(c_name, O_WRONLY);
		sleep(1);
		int readfd = open(p_name, O_RDONLY);
		int num = read(readfd, buff, 1024);
		printf("Inside child\n %s", buff);
		write(writefd, buff, strlen(msg_child));
	}
	else{
		int readfd = open(c_name, O_RDONLY);
		char buff[1024];
		int writefd = open(p_name, O_WRONLY);
		write(writefd, msg_parent, strlen(msg_parent));
		sleep(2);
		int num = read(readfd, buff, 1024);
		printf("Inside parent\n %s", buff);	
	}
}
