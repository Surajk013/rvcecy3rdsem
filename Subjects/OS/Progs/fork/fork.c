#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<wait.h>

int main(int argc, char *argv[]){
	printf("\n In main function -- \n");
	int retval=1;
	pid_t pid=fork();
	
	if(pid<0){
		printf("Error in fork execution\n");
	}
	if(pid==0){
		printf("PID of child process is :%d\nPID of its parent is: %d\n",getpid(),getppid());
		execl("./app",argv[1],NULL);
	}
	else{
		printf("PID of parent is: %d\n",getpid());
		wait(&retval);
		if(WIFEXITED(retval)==1){
			printf("Child terminated noramlly\n");
		}
		else{
			printf("Child terminated abnormally\n");
			exit(0);
		}
	}
	return 0;
}
