/////////////////////////////////////////////////////////////////////////////////////////
//Name			:Randomized Quick Sort
//Copyright		:Copyright, Vivek Malik;2011
//Created on	:21-Aug-2011
//Author		:Vivek Malik
//Description	:Sorting an array using Randomized Quick Sort Algorithm
////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

int array_to_display[50];

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int randomized_partition(int a[],int p,int r){
	int i;
	fflush(stdin);
	fflush(stdout);
	srand(time(NULL));
	i=rand()%(r+1);
	swap(&a[i],&a[r]);
	return partition(a,p,r);
	fflush(stdin);
	fflush(stdout);
}

void quicksort(int a[], int p, int r){
	int i,q;
	if(p<r){
		q=randomized_partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
		for(i=0;i<=r;i++){
			array_to_display[i]=a[i];
		}
	}
}

int partition(int a[],int p, int r){
	int i,x,j;
	x=a[r];
	i=p-1;
	for(j=p;j<r;j++){
		if(a[j]<=x){
			i=i+1;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[r]);
	return(i+1);
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int arr[50], i,n;
	printf("Enter no. of elements in array(max 50) :");
	scanf("%d",&n);
	printf("Elements of array :\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,n-1);
	printf("The sorted array is :\t");
	for(i=0;i<n;i++){
		printf("%d\t",array_to_display[i]);
	}
	return(0);
}
