/*
 * queue.c
 *
 *  Created on: 16-Sep-2011
 *      Author: vivek
 */
#include<stdio.h>
#include<stdlib.h>

struct node{
	int n;
	struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void push();
void pop();
void display();
void push_cirq();
void pop_cirq();
void display_cirq();
void push_front();

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int n,i,m;
	printf("Enter no. of nodes to insert in Queue :");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		push_cirq();
		//push_front();
	}
	printf("\nThe Current Queue is :\n");
	display_cirq();
	printf("\n");
	printf("\nEnter no. of nodes to pop from queue :");
	scanf("%d",&m);
	for(i=0;i<m;i++){
		pop_cirq();
	}
	//pop();
	printf("\nThe Current Queue is \n");
	display_cirq();
	push_front();
	display_cirq();
/*	front=NULL;
	rear=NULL;
	printf("\nEnter no. of nodes to insert in circular queue :");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		push_cirq();
	}
	display_cirq();
	printf("\n");
	pop_cirq();
	display_cirq();*/
	return(0);
}

void push(){
	struct node *queue;
	queue=(struct node*)malloc(sizeof(struct node));
	if(queue==NULL){
		printf("Overflow");
		exit(0);
	}
	scanf("%d",&queue->n);
	queue->next=NULL;
	if(front==NULL){
		front=rear=queue;
	}
	else{
		rear->next=queue;
		rear=queue;
	}
}

void pop(){
	struct node *temp;
	temp=front;
	if(temp==NULL){
		printf("\nUnderflow");
	}
	else{
		front=temp->next;
		printf("\n%d Deleted from Queue ",temp->n);
		free(temp);
	}
}

void display(){
	struct node *temp;
	temp=front;
	while(temp!=NULL){
		printf("%d ",temp->n);
		temp=temp->next;
	}
}

void push_cirq(){
	struct node *cqueue;
	cqueue=(struct node*)malloc(sizeof(struct node));
	if(cqueue==NULL){
		printf("Overflow");
		exit(0);
	}
	scanf("%d",&cqueue->n);
	cqueue->next=NULL;
	if(front==NULL){
		front=rear=cqueue;
	}
	else{
		rear->next=cqueue;
		cqueue->next=front;
		rear=cqueue;
	}
}

void pop_cirq(){
	struct node *temp;
	temp=front;
	front=temp->next;
	rear->next=front;
	free(temp);
}

void display_cirq(){
	struct node *temp;
	temp=front;
	while(temp->next!=front){
		printf("%d ",temp->n);
		temp=temp->next;
	}
	printf("%d ",temp->n);
}

void push_front(){
	struct node *queue;
	queue=(struct node*)malloc(sizeof(struct node));
	if(queue==NULL){
		printf("overflow");
		exit(0);
	}
	scanf("%d",&queue->n);
	queue->next=NULL;
	if(front==NULL){
		front=rear=queue;
	}
	else{
		queue->next=front;
		front=queue;
	}
}
