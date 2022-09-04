#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int t = 5;
	alarm(t);	//This will terminate the program after t seconds.

	int i = 0;
	while (1){
		printf("%d ", i);
		fflush(stdout);
		sleep(1);
		i++;
	}
}
