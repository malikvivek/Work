//////////////////////////////////////////////////////////////////////////////////////
//Name			:selection_sort.c
//Copyright		:Copyright Vivek Malik,2012
//Created on	:26-Feb-2012
//Author		:Vivek Malik
//Description	:Sorting an array using Selection Sort Algorithm
//////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

void selection_sort(int arr[], int *);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int arr[50],i,n;
	printf("Please Enter the size of the array(Maximum 50):");
	scanf("%d",&n);
	printf("\nPlease Enter the unsorted array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	selection_sort(arr,&n);
	printf("Sorted Array is\n");
	for(i=0;i<n;i++){
		printf("%d  ",arr[i]);
	}
	return(0);
}

void selection_sort(int arr[], int *high){
	int i,j,min,pos,temp;
	for(i=0;i<(*high)-1;i++){
		min=arr[i];
		pos=i;
		for(j=i+1;j<*high;j++){
			if(min>arr[j]){
				min=arr[j];
				pos=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[pos];
		arr[pos]=temp;
	}
}

