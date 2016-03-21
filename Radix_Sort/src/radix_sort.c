//////////////////////////////////////////////////////////////////////////////////////////
//Name 			:radix_sort.c
//Copyright		:Copyright Vivek Malik,2012
//Created on	:28-Feb-2012
//Author		:Vivek Malik
//Description	:Sorting an array using Radix Sort Algorithm
//////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

void radix_sort(int arr[],int *, int *, int *);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int arr[50],i,n, max_ele,digit;
	printf("Please Enter the size of the array(Maximum 50):");
	scanf("%d",&n);
	printf("\nEnter digit size of each element in array :");
	scanf("%d",&digit);
	printf("\nPlease Enter the unsorted array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	max_ele=arr[0];
	for(i=1;i<n;i++){
		if(max_ele<arr[i]){
			max_ele=arr[i];
		}
	}
//	printf("%d",max_ele);
	radix_sort(arr,&n,&max_ele,&digit);
	return(0);
}

void radix_sort(int arr[],int *high, int *k, int *digits){
//	printf("in counting_sort\n");
//	printf("%d\n%d\n",*high,*k);
	int i, size_arr_c,j;
	int arr2[*high];
	size_arr_c=*k+1;
	int c[size_arr_c];
	for(i=0;i<*digits;i++){
		for(i=0;i<size_arr_c;i++){
			c[i]=0;
		}
		for(j=0;j<*high;j++){
			c[arr[j]]=c[arr[j]]+1;
		}
		for(i=1;i<size_arr_c;i++){
			c[i]=c[i]+c[i-1];
		}
	/*	for(i=0;i<size_arr_c;i++){
	//		printf("%d",c[i]);
		}*/
		printf("\n\n");
		for(j=*high-1;j>=0;j--){
			arr2[c[arr[j]]-1]=arr[j];
			//printf("arr2 - %d, c-arr-j = %d, j=%d\n",arr2[c[arr[j]]],c[arr[j]],j);
			c[arr[j]]=c[arr[j]]-1;
			//printf("arr - %d\n",c[arr[j]]);
		}
		printf("Sorted Array is\n");
		for(i=0;i<*high;i++){
			printf("%d  ",arr2[i]);
		}

	}
}

