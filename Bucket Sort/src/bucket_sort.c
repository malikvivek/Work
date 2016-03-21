/////////////////////////////////////////////////////////////////////////////////////////
//Name			:bucket_sort.c
//Copyright 	:Copyright Vivek Malik, 2012
//Created on	:01-Apr-2012
//Author		:Vivek Malik
//Description 	:Sorting an array using Bucket Sort Algorithm
/////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

void bucketSort(int array[], int n) {
	int i, j;
	int count[n];
	for(i=0; i < n; i++) {
		count[i] = 0;
	}
	for(i=0; i < n; i++) {
		(count[array[i]])++;
//		printf("%d\n",count[array[i]]);
	}
	for(i=0,j=0; i < n; i++) {
		for(; count[i]>0; (count[i])--) {
			array[j++] = i;
		}
	}

}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int array[100];
	int n;
	int i;
	printf("Enter number of elements in array : ");
	scanf("%d",&n);
	printf("Enter the elements to be sorted:\n");
	for(i = 0; i < n; i++ ){
		scanf("%d",&array[i]);
	}
	printf("\nThe array of elements before sorting : \n");
	for (i = 0;i < n;i++) {
		printf("%d ", array[i]);
	}
	printf("\nThe array of elements after sorting : \n");
	bucketSort(array, n);
	for (i = 0;i < n;i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	return(0);
}
