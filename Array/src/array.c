//////////////////////////////////////////////////////////////////////////////////////////
//Name			: Array operations
//Copyright		: Copyright, Vivek Malik;2011
//Created on	: 22-Aug-2011
//Author		: Vivek Malik
//Description	: Performing array operations on an array using insertion, deletion
//				  and traversal algorithms for arrays.
//////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

void insert(int b[],int *);
void display(int b[],int);
void delete(int b[],int *);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int arr[50];
	int n,i,choice;
	char ch='y';
	printf("Enter no. of elements in the array:");
	scanf("%d",&n);
	printf("Enter elements of the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	while(ch=='y'){
		printf("Please Enter your choice :\n\n");
		printf("1.) Insert into an array");
		printf("\t2.) Delete from an array");
		printf("\t3.) Traverse the array");
		printf("\t0.) Exit");
		printf("\nYour Choice :");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			insert(arr, &n);
			printf("\nArray after insertion is :\n");
			display(arr,n);
			break;
		case 2:
			delete(arr,&n);
			printf("\nArray after deletion  is :\n");
			display(arr,n);
			break;
		case 3:
			printf("\nArray is :");
			display(arr,n);
			break;
		case 0:
			exit(0);
		default:
			printf("Invalid Entry");
			break;
		}
		printf("\nDo you wish to continue :");
		scanf("%s",&ch);
	}
	return(0);
}

void insert(int b[], int *high){
	int i,ele,pos;
	printf("Please Enter the no. to insert :");
	scanf("%d",&ele);
	printf("Please enter the position where element is to be inserted :");
	scanf("%d",&pos);
	for(i=*high;i>=pos-1;i--){
		b[i+1]=b[i];
	}
	b[pos-1]=ele;
	*high=*high+1;
}

void display(int b[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("\n%d", b[i]);
	}
}

void delete(int b[], int *high){
	int pos,i;
	printf("Enter the position of element to be deleted : ");
	scanf("%d",&pos);
	//b[pos-1]=temp;
	for(i=pos-1;i<*high;i++){
		b[i]=b[i+1];
	}
	*high=*high-1;
}
