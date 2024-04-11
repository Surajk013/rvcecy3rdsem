#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
	int input_fd;
	
	if(argc!=2){
		printf("Usage: rm file1");
		return 1;
	}
	
	input_fd=unlink(argv[1]);
	if(input_fd==-1){
		perror("unlink error");
		return 2;
	}
	

}
