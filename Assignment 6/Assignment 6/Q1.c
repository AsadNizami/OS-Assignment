#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int fd[2];
	pipe(fd);
	
	int cpid = fork();

	if (cpid != 0){
		dup2(fd[1], 1);
		execlp("cat", "mycat", "file.txt", NULL);
		exit(1);
	}
	else{
		dup2(fd[0], 0);
		execlp("grep", "mygrep", "world", NULL);
		exit(1);
	}
}
