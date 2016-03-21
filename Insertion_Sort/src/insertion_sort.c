//////////////////////////////////////////////////////////////////////////////////////////
// Name			: insertion_sort.c
// Copyright	: Copyright Vivek Malik, 2012
// Created on	: 26-Feb-2012
// Author		: Vivek Malik
// Description 	: Sorting an array using Insertion Sort Algorithm
/////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int arr[], int *);

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
	insertion_sort(arr,&n);
	printf("Sorted Array is\n");
	for(i=0;i<n;i++){
		printf("%d  ",arr[i]);
	}
	return(0);
}

void insertion_sort(int arr[], int *high){
	int j,k;
	for(k=1;k<*high;k++){
		int temp=arr[k];
		j=k-1;
		while((temp<arr[j])&&j>=0){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}
