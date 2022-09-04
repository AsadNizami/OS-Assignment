#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
	int cpid = fork();
	
	if (cpid == 0)	while (1);
	
	else{
		int cpid2 = fork();
		if (cpid2 == 0){
			printf("Killing child1 in 5 seconds.\n");
			sleep(5);
			kill(cpid, SIGKILL);
			printf("Killed.");
			while(1){
				printf("Child 2 lives \n");
				fflush(stdout);
				sleep(2);
			}
		}
		else{
			while(1) {
			printf("Parent lives\n");
			fflush(stdout);
			sleep(2);
			}
		}
	}	
}
