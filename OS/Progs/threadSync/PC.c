#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

#define buffersize 10

pthread_mutex_t mutex;
pthread_t tidp[20],tidc[20];
sem_t full,empty;
int counter;
int buffer[buffersize];

void initialise(){
	pthread_mutex_init(&mutex,NULL);	
	sem_init(&full,1,0);
	sem_init(&empty,1,buffersize);
	counter=0;
}

void write(int item){
	buffer[counter++]=item;
}

int read(){
	return (buffer[--counter]);
}

void *producer(void *param){
	int waittime,item,i;
	waittime=rand()%5;
	item=rand()%5;
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	printf("\n Producer produced item %d\n",item);
	write(item);
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
}

void *consumer(void *param){
	int waittime,item;
	waittime=rand()%5;
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
	item=read();
	printf("\n Consumer consumer item %d\n",item);
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
}

int main(){
	int n1,n2,i;
	initialise();
	printf("\nEnter the number of producers: ");
	scanf("%d",&n1);
	printf("\n Enter the number of consumers: ");
	scanf("%d",&n2);
	for(i=0;i<n1;i++)
		pthread_create(&tidp[i],NULL,producer,NULL);
	for(i=0;i<n2;i++)
		pthread_create(&tidc[i],NULL,consumer,NULL);
	for(i=0;i<n1;i++)
		pthread_join(tidp[i],NULL);
	for(i=0;i<n2;i++)
		pthread_join(tidc[i],NULL);
}
