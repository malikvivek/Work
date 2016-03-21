/*
 * try.c
 *
 *  Created on: 06-Sep-2011
 *      Author: vivek
 */
#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *next;
};
struct node *top=NULL;
void push();
void display();
void pop();
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int n,i,m;
	printf("Enter no. of nodes in the list");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		push();
	}
	printf("\nCurrent Stack is:\n");
	display();
	printf("\nEnter no. of nodes to pop from stack :");
	scanf("%d",&m);
	for(i=0;i<m;i++){
		pop();
	}
	//pop();
	printf("\nCurrent Stack is:\n");
	display();
	//pop();
	return(0);
}
void push(){
	struct node *stack;
	stack = (struct node*)malloc(sizeof(struct node));
	if(stack==NULL){
		printf("\nOverflow");
		exit(0);
	}
	scanf("%d",&stack->n);
	stack->next=top;
	top=stack;
}
void display(){
	struct node *temp;
	temp=top;
	while(temp!=NULL)
	{
		printf("%d, ",temp->n);
		temp=temp->next;
	}
}
void pop(){
	struct node *temp;
	temp=top;
	if(temp==NULL){
		printf("\nUnderflow");
	}
	else{
		top=top->next;
		printf("\n%d Deleted from Stack",temp->n);
		free(temp);
	}
}
