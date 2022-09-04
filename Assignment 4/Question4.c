#include <stdio.h>
#include <sched.h>

int main(){
	// sched_get_priority_max returns the maximum priority valus that can be used with the scheduling algorithm identified by policy.
	// sched_get_priority returns the minimum.
	printf("%d\n", sched_get_priority_max(SCHED_OTHER));
	printf("%d\n", sched_get_priority_min(SCHED_OTHER));
	
	// if value is between 1 and 99 then SCHED_FIFO OR SCHED_RR is used and if value is 0 then SCHED_OTHER is used
	
	// Other parameters used: SCHED_BATCH, SCHED_IDLE, SCHED_FIFO and SCHED_RR
}
