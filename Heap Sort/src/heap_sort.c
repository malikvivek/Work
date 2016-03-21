/////////////////////////////////////////////////////////////////////////////////////
//Name 			:heap_sort.c
//Copyright 	:Copyright Vivek Malik,2012
//Created on	:15-Mar-2012
//Author		:Vivek Malik
//Description	:Sorting an array using Heap Sort Algorithm
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int a[50],n,heap_size;

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void heap_fy(int x){
    int left=(2*x);
    int right=(2*x)+1;
    int large;
    if((left<=heap_size)&&(a[left]>a[x])){
        large=left;
    }
    else{
        large=x;
    }
    if((right<=heap_size)&&(a[right]>a[large])){
        large=right;
    }
    if(x!=large){
        swap(&a[x],&a[large]);
        heap_fy(large);
    }
}

void BuildMaxHeap(){
	int i;
    heap_size=n;
	for(i=n/2;i>0;i--){
        heap_fy(i);
    }
}

void HeapSort(){
	int i;
    BuildMaxHeap();
//    hs=n;
    for(i=heap_size;i>1;i--){
        swap(&a[1],&a[i]);
        heap_size--;
        heap_fy(1);
    }
}

int main(){
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
	int i;
    printf("Enter length:\t");
    scanf("%d",&n);
    printf("\nEnter elements:\n");
    for(i=1;i<=n;i++){       //Read Array{
        scanf("%d",&a[i]);
    }
    HeapSort();
    printf("\nSorted Array is :\t");
    for(i=1;i<=n;i++){       //Print Sorted Array{
    	printf("%d\t",a[i]);
    }
    return(0);
}

/*
int PARENT(int i){
	return(abs(i/2));
}
int LEFT(int i){
	return((2*i)+1);
}
int RIGHT(int i){
	return((2*i)+2);
}

void MAX_HEAPFY(int arr[], int, int);
void BUILD_MAX_HEAP(int arr[], int);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int arr[5],i,j;
	printf("Enter array\n");
	for(i=0;i<5;i++){
		scanf("%d",&arr[i]);
	}
	MAX_HEAPFY(arr,1,5);
	j=PARENT(1);
	printf("%d",arr[j]);
/*	j=LEFT(1);
	printf("%d",arr[j]);
	return(0);
}

void MAX_HEAPFY(int arr[], int i, int n){
	int l, r, largest,j;
	l=LEFT(i);
	r=RIGHT(i);
	if((l<=n) && (arr[l-1]>arr[i-1])){
		largest=l;
	}
	else{
		largest=i;
	}
	if((r<=n) && (arr[r-1]>arr[largest-1])){
		largest=r;
	}
	if(largest!=i){
		arr[i]=arr[i]+arr[largest];
		arr[largest]=arr[i]-arr[largest];
		arr[i]=arr[i]-arr[largest];
		MAX_HEAPFY(arr,largest,n);
	}
}
/*
void BUILD_MAX_HEAP(int arr[],int n){
	int i;
	i=abs((n-1)/2);
	for(i;i>=0;i--){
		MAX_HEAPFY(arr,i);
	}
}

void HEAP_SORT(int arr[],int n){
	BUILD_MAX_HEAPFY(arr,n);
	for(i=n-1;i>=1;i--){
		arr[1]=arr[1]+arr[i];
		arr[i]=arr[1]-arr[i];
		arr[1]=arr[1]-arr[i];
		n=n-1;
		MAX_HEAPFY(arr,1);
	}
}
*/
