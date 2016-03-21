//////////////////////////////////////////////////////////////////////////////////////////
//Name			: bubblesort.c
//Copyright		: Copyright, Vivek Malik;2011
//Created on	: 22-Sep-2011
//Author		: Vivek Malik
//Description	: Sorting an array using Exchange Sort algorithm and Exchange Sort Algorithm
//////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void exchange_sort(int b[], int *);
void bubble_sort(int b[], int *);
void display(int b[], int);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int arr[50],n,i;
	printf("Enter no. of elements in the array:");
	scanf("%d",&n);
	printf("Enter elements of the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	bubble_sort(arr,&n);
	display(arr,n);
	return(0);
}

void exchange_sort(int b[], int *high){
	int i,j;
	for(i=0;i<*high-1;i++){
		for(j=i+1;j<*high;j++){
			if(b[i]>b[j]){
				int temp;
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
}

void bubble_sort(int b[], int *high){
	int i,j;
	for(i=0;i<*high;i++){
		for(j=*high-1;j>=i+1;j--){
			if(b[j]<b[j-1]){
				int temp;
				temp=b[j];
				b[j]=b[j-1];
				b[j-1]=temp;
			}
		}
	}
}

void display(int b[], int high){
	int i;
	printf("The Sorted Array is :\n");
	for(i=0;i<high;i++){
		printf("%d ",b[i]);
	}

}
