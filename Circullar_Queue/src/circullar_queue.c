/*
 * circullar_queue.c
 *
 *  Created on: 29-Nov-2011
 *      Author: vivek
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int cirque[5];
int front=-1;
int rear=-1;

void push_cirq(){
	int i,data;
	if(front==0&&rear==4){
		printf("Overflow\n");
		exit(0);
/*		for(i=0;i<5;i++){
			printf("%d",cirque[i]);
		}
		exit(2);*/
	}
	printf("Eneter Data :");
	scanf("%d",&data);
	if(front==-1){
		front=rear=0;
	}
	else if(rear==4){
		rear=0;
	}
	else{
		rear=rear+1;
	}
	cirque[rear]=data;
}

void pop(){
	int temp;
	temp=front;
	if(front==4){
		printf("Underflow");
	}
	front=front+1;
	cirque[temp]=0;
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int i;
	for(i=0;i<5;i++){
		push_cirq();
	}
/*	printf("Deleted 2 elements \n");
	pop();
	pop();
	for(i=0;i<5;i++){
		printf("%d",cirque[i]);
	}*/
	printf("\n");
	push_cirq();
//	pop();
//	pop();
//	push_cirq();
	for(i=0;i<5;i++){
		printf("%d",cirque[i]);
	}
	return(0);
}
