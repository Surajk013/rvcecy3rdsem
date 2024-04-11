#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	int fd;
	struct flock fvar;
	if(argc==1){
		printf("Usage: %s filename",argv[0]);
		return -1;
	}
	
	if((fd=open(argv[1],O_RDWR))==-1){
		perror("open");
		exit(1);
	}
	fvar.l_type=F_WRLCK;
	fvar.l_whence=SEEK_END;
	fvar.l_start=SEEK_END-100;
	fvar.l_len=100;
	printf("\n Press enter to set lock");
	getchar();
	printf("\n Trying to set lock...");
	if((fcntl(fd,F_SETLK,&fvar))==-1){
		fcntl(fd,F_GETLK,&fvar);
		printf("File already locked by process id: %d\n",fvar.l_pid);
		return -1;
	}
	printf("locked");
	printf("\n Press enter to release lock");
	getchar();
	fvar.l_type=F_UNLCK;
	fvar.l_whence=SEEK_SET;
	fvar.l_start=0;
	fvar.l_len=0;
	if((fcntl(fd,F_UNLCK,&fvar))==-1){
		printf("fcntl");
		exit(0);
	}
	printf("unlocked");
	close(fd);
	return 0;
}
