/////////////////////////////////////////////////////////////////////////////////////////
//Name 			: Linked List Operations
//Copyright		: Copyright Vivek Malik;2011
//Created on	: 08-Sep-2011
//Author		: Vivek Malik
//Description	: Performing various linked list operations like creation,insertion,
//				  deletion, reversal etc.
//Functions		: 1. create_end()-to insert a node at the end.(No return value)
//				  2. create_beg()-to insert a node in the begining.(No return value)
//				  3. display()-to display the list.(No return value)
//				  4. insert()- to insert a new node at specified location
/////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

struct list{
	int data;
	struct list *next;
};
struct list *start=NULL;

void create_end();
void create_beg();
void display();
void insert();
void delete_beg();
void delete_end();
void delete_pos();
void reverse();
void search(int);

int main(){
	int i,n;
	printf("Enter no. of nodes to insert in end:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		create_end();
	}
	printf("Enter no of nodes to insert in begining:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		create_beg();
	}
//	reverse();
//	insert();
//	delete_beg();
//	delete_end();
//	delete_pos();
//	search(5);
	printf("\n\nThe list is:");
	display();
	return(0);
}

void create_end(){
	struct list *node;
	node = (struct list*)malloc(sizeof(struct list));
	if(node==NULL){
		printf("Overflow");
		exit(0);
	}
	scanf("%d",&node->data);
	node->next=NULL;
	if(start==NULL){
		start=node;
	}
	else{
		struct list *temp;
		temp=start;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=node;
	}
}

void display(){
	struct list *temp;
	temp=start;
	printf("The list is :");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

void create_beg(){
	struct list *node;
	node = (struct list*)malloc(sizeof(struct list));
	if(node==NULL){
		printf("Overflow");
		exit(0);
	}
	scanf("%d",&node->data);
	node->next=NULL;
	if(start==NULL){
		start=node;
	}
	else{
		node->next=start;
		start=node;
	}
}

void insert(){
	int pos=1;
	int pos2;
	struct list *temp;
	struct list *new_node;
	new_node = (struct list*)malloc(sizeof(struct list));
	if(new_node==NULL){
		printf("Overflow");
		exit(0);
	}
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	printf("Please Enter the position after which new node is to be inserted :");
	scanf("%d",&pos2);
	temp=start;
	while(temp!=NULL){
		if(pos==pos2){
			break;
		}
		else{
			temp=temp->next;
			pos++;
		}
	}
	new_node->next=temp->next;
	temp->next=new_node;
}

void delete_beg(){
	struct list *temp;
	temp=start;
	start=start->next;
	free(temp);
}

void delete_end(){
	struct list *temp;
	struct list *temp2;
	struct list *free_ptr;
	temp2=start;
	temp=start->next;
	while(temp->next!=NULL){
		temp=temp->next;
		temp2=temp2->next;
	}
	free_ptr=temp;
	free(free_ptr);
	temp2->next=NULL;
}

void delete_pos(){
	int pos=1;
	int pos2;
	struct list *temp;
	struct list *temp2;
	temp=start;
	printf("Enter the Position of node to be deleted :");
	scanf("%d",&pos2);
	while(temp!=NULL){
		if(pos==(pos2-1)){
			break;
		}
		else{
			temp=temp->next;
			pos++;
		}
	}
	temp2=temp->next;
	temp->next=temp2->next;
	free(temp2);
}

void reverse(){
	struct list *s,*r,*q;
	r=NULL;
	q=start;
	while(q!=NULL){
		s=r;
		r=q;
		q=q->next;
		r->next=s;
	}
	start=r;
}

void search(int num){
	int flag = 0;
	struct list *temp;
	temp=start;
	while(temp!=NULL){
		if(num==temp->data)
			flag=1;
		temp=temp->next;
	}
	if (flag==1)
		printf("\nFound: %d", num);
	else
		printf("\nNot Found: %d", num);
}
