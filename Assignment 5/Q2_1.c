#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void catcher(){
	printf("Signal catched");
}

int main(){
	signal(SIGINT, catcher);
	int ret = raise(SIGINT); // Will raise corresponding signal.
	
}
