#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<wait.h>

int main(){
	int pid = fork();
	int sl = 5;
	if (pid == 0){
		while(1){
			printf("Child 1: PID: %d\n", getpid());
			sleep(1);
		}
	}
	else{	
		int status;
		int pid2 = fork();
		if (pid2 == 0){
			sleep(sl);
			printf("Child 2: PID: %d\n", getpid());
			kill(pid, SIGKILL);
			printf("Child 1 is dead\n");
			sleep(sl);
			printf("Child 2 is dead\n");
		}
		else{
			waitpid(pid2, &status, 0);
			printf("Parent Process");
		}
	}
		
}

