#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
int count = 0;


void catcher_2(){
	count += 1;
	if (count == 5)	{
		printf(" \nWarning: Next SIGINT signal will terminate the program \n");
		signal(SIGINT, SIG_DFL);
	}
}

int main(){
	signal(SIGINT, catcher_2);
	
	while (1)	fflush(stdout);
}
