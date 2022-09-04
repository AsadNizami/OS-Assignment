#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	char buff[1024];
	
	int num;
	printf("Reading...\n");
	char *name = "myfifo";
	
	int readfd = open(name, O_RDONLY);
	
	do{
		num = read(readfd, buff, 1024);
		buff[num] = '\0';
		printf("Reads %d bytes: %s \n", num, buff);
	}while(num > 0);
	
}
