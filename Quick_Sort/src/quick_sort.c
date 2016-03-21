//////////////////////////////////////////////////////////////////////////////////////////
//Name 			:quick_sort.c
//Copyright		:Copyright Vivek Malik, 2011
//Created on	:29-Nov-2011
//Author		:Vivek Malik
//Description	:Sorting an Array using Quick Sort Algorithm
//////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void swap(int *, int *);
void quicksort(int a[], int, int);
int partition(int a[], int, int);

int array_to_display[50];

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
	printf("\nThe sorted array is :\t");
	for(i=0;i<n;i++){
		printf("%d\t",array_to_display[i]);
	}
	return(0);
}

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void quicksort(int a[], int p, int r){
	int i,q;
	if(p<r){
		q=partition(a,p,r);
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
