#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	char buff[1024];
	
	char *name = "myfifo";
	mknod(name, S_IFIFO|0666, 0);
	
	int writefd = open(name, O_WRONLY);
	printf("Type input\n");
	
	while (fgets(buff, 1023, stdin)){
		write(writefd, buff, strlen(buff));
	}
}
