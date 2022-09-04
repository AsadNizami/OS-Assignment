#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

	int fd1[2]; int fd2[2];
	pipe(fd1);
	
	int cpid = fork();

	if (cpid != 0){
		printf("2132");
		close(fd1[0]);
		dup2(fd1[1], 1);
		execlp("man", "myman", "ls", NULL);
		fflush(stdout);
		exit(1);
	}
	else{
		pipe(fd2);
		dup2(fd1[0], 0);
		close(fd1[1]);
		
		int cpid2 = fork();
		if (cpid2 != 0){
			close(fd2[0]);
			
			dup2(fd2[1], 1);
			execlp("grep", "mygrep", "ls", NULL);
			fflush(stdout);
			exit(1);
		}
		else{
			fflush(stdout);
			
			close(fd2[1]);
			dup2(fd2[0], 0);
			execlp("wc", "mywc", "-l", NULL);
			exit(1);
		}
	}
}
