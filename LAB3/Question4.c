#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	// system library function uses fork to create a child process that executes the shell command.
	// system is used to execute a shell command
	// return:
	// Null if process is not available
	// -1 if process could not be retrieved
	// returns value as though the child shell terminated by calling _exit(2)
	// 0 if process is executed successfully
	printf("Files in current directory: ");
	fflush(stdout);
	system("ls");
	printf("Time and date");
	fflush(stdout);
	system("date");	
}
