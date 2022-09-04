#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	printf("Enter:\n1: fork\n2: vfork\n");
	int option;
	scanf("%d", &option);
	if (option == 1){
		int pid = fork();
		if (pid == 0){
			printf("Child Process\n");
			printf("PID of current process: %d\n", getpid());
			printf("PID of parent process: %d \n", getppid());
		}
		else{
			for(int i=0; i<10000000; i++);
			printf("Parent Process\n");
			printf("PID of current process: %d\n", getpid());
			printf("PID of parent process: %d \n", getppid());
		}
	}
	else if(option == 2){
		int pid = vfork();
		if (pid == 0){
			for(int i=0; i<1000000; i++);
			printf("Child Process\n");
			fflush(stdin);
			printf("PID of current process: %d\n", getpid());
			printf("PID of parent process: %d \n", getppid());
		}
		else{
			printf("Parent Process\n");
			printf("PID of current process: %d\n", getpid());
			printf("PID of parent process: %d \n", getppid());
			exit(0);
		}
	}
	else{
		printf("Exit \n");
	}
	
}
