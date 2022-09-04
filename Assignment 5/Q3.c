#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void catch_2(){
	printf("Signal-2 \n");
}
void catch_3(){
	printf("Signal-3 \n");
}
void catch_8(){
	printf("Signal-8 \n");
}
void catch_9(){
	printf("Signal-9 \n");
}
void catch_19(){
	printf("Signal-19 \n");
}
void catch_20(){
	printf("Signal-20 \n");
}


int main(){
	signal(2, catch_2); //SIGINT
	signal(3, catch_3);	//SIGQUIT
	signal(8, catch_8);	//SIGFPE
	signal(9, catch_9);	//SIGKILL
	signal(19, catch_19); //SIGSTOP
	signal(20, catch_20); //SIGTSTP
	
	while(1){
		fflush(stdout);
		sleep(1);
	}
}
