#include <stdio.h>
#include <unistd.h>
#include <sched.h>


int main(){
	// sched_setscheduler sets both the scheduling policy and parameters for the thread whose ID is specified, if pid is zero then that of calling thread will be set.
	struct sched_param s = {130};
	printf("%d", s.sched_priority);

	printf("Current policy: %d \n", sched_getscheduler(getpid()));

	int status = sched_setscheduler(getpid(), 0, &s);
	if (status == 0)	printf("Success\n");
	else	printf("Error: %d\n", status);
	printf("New policy: %d \n", sched_getscheduler(getpid()));
}

