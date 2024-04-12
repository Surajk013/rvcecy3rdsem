#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 5

struct queue{
	int front,rear;
	char data[size][20];
};
typedef struct queue queue;

void send(queue *q,char item[20]){
	if(q->front==(q->rear+1)%size)
		printf("\nQueue is full");
	else{
		q->rear=(q->rear+1)%size;
		strcpy(q->data[q->rear],item);
		if(q->front==-1)
			q->front=0;
	}
}

void *receive(queue *q){
	char *del=NULL;
	if(q->front=-1)
		printf("\nQueue is empty");
	else{
		del=q->data[q->front];
		if(q->front=q->rear){
			q->front=-1;
			q->rear=-1;
		}
		else
			q->front=(q->front+1)%size;
	}
	return NULL;
}

void display(queue q){
	int i;
	if(q.front==-1)
		printf("\nQueue is empty");
	else{
		printf("\n Queue contents are: ");
		for(i=q.front;i!=q.rear;i=(i+1)%size)
			printf("%s ",q.data[i]);
		printf("%s ",q.data[i]);
	}
}

int main(){
	int ch;
	char *del;
	char item[20];
	queue q;
	q.rear=-1;
	q.front=-1;
	for(;;){
		printf("\n1.Send\n2.Receive\n3.Display\n4.Exit\nRead choice: ");
		scanf("%d",&ch);
		getchar();
		switch(ch){
		case 1:printf("\n Enter the element you want to insert: ");
			fgets(item,sizeof(item),stdin);
			send(&q,item);
			getchar();
			break;
		case 2:
			del=receive(&q);
			if(del!=NULL)
				printf("\n the deleted element is: %s",del);
			break;
		case 3: display(q);
			break;
		default:exit(0);
		
		}
	}
	return 0;
}
