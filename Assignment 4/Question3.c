#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){
	printf("Process info: \n");
	fflush(stdout);
	system("ps -l $$"); // Stands for process status, displays the pid, ppid, nice value, priority of the process of shell.
	printf("\n");
	
	// syntax: int getpriority(int which, id_t who)
	int prev = getpriority(PRIO_PROCESS, getpid()); // Operates on the process when PID equls who equals, pid.
	printf("Current priority : %d\n", prev);
	fflush(stdout);

	// getpriority(PRIO_PGRP, getpgid(getpid())); // Same but on group
	
	// syntax: int setpriority(int which, id_t who, int priority)
	int stats = setpriority(PRIO_PROCESS, getpid(), 5);
	if (!stats)
		printf("Successful! \n");
	else
		printf("Unsucceful %d\n", stats);

	int new = getpriority(PRIO_PROCESS, getpid());
	printf("New priority: %d", new);
}

