#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
/*
	SIGHUP(1): The signal is send when the terminal from which this program is ran, goes away.
	SIGILL(4): Illegal instruction, some machine code the CPU cannot understand.
	SIGSEGV(11): Attempt to access illegal memory (the memory is not yet allocated).
	SIGSTOP(19): OS sends signal to pause the process, it's current state is preserved.
*/

void catch_11(){
	printf("Attempt to access illegal memory. \n");
}
void catch_4(){
	printf("Illegal instruction. \n");
}
void catch_1(){
	printf("Terminal terminated? Program will exit in 5 seconds.\n");
	sleep(5);
	exit(0);
}

int main(){
	signal(SIGSEGV, catch_11);
	signal(SIGILL, catch_4);
	signal(SIGHUP, 	catch_1);
	
	while(1)	fflush(stdout);
}

