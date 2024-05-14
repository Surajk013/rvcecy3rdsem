#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

#define n 5
#define thinking 2
#define hungry 1
#define eating 0
#define left (phnum+4)%n
#define right (phnum+1)%n

int state[n];
int phil[n]={0,1,2,3,4	};

sem_t mutex;
sem_t s[n];

void test(int phnum){
	if(state[phnum]==hungry && state[left]!=eating && state[right]!=eating){
		state[phnum]=eating;
		sleep(2);
		printf("\nPhilosopher %d is taking fork %d and %d",phnum+1,left+1,phnum+1);
		printf("\nPhilospher %d is eating",phnum+1);
		sem_post(&s[phnum]);
	}
}

void takefork(int phnum){
	sem_wait(&mutex);
	state[phnum]=hungry;
	printf("\n Philosopher %d is hungry",phnum+1);
	test(phnum);
	sem_post(&mutex);
	sem_wait(&s[phnum]);
	sleep(1);

}

void putfork(int phnum){
	sem_wait(&mutex);
	
	state[phnum]=thinking;
	printf("\n Philospher %d is putting fork %d and %d down",phnum+1,left+1,phnum+1);
	printf("\n Philosopher %d is thinking",phnum+1);
	test(left);
	test(right);
	sem_post(&mutex);
}

void* philosopher(void* num){
	while(1){
		int *i=num;
		sleep(1);
		takefork(*i);
		sleep(0);
		putfork(*i);
	}
}

int main(){
	int i;
	pthread_t thread_id[n];
	sem_init(&mutex,0,1);
	for(i=0;i<n;i++)
		sem_init(&s[i],0,0);
		
	for(i=0;i<n;i++){
		pthread_create(&thread_id[i],NULL,philosopher,&phil[i]);
		printf("\n Philospher %d is thinking",i+1);
	}
	
	for(i=0;i<n;i++)
		pthread_join(thread_id[i],NULL);
}
