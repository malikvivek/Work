//////////////////////////////////////////////////////////////////////////////////////
//Name			:binary_search
//Copyright		:Copyright, Vivek Malik;2011
//Created on	:21-Aug-2011
//Author		:Vivek Malik
//Description	:Finding element in an array(Sorted) using Binary Search Algorithm
//////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

int binsearch(int b[],int,int,int);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int arr[50], pos, ele, n, i;
	printf("Enter no. of elements in the array(Sorted in ascending order):");
	scanf("%d",&n);
	printf("Enter elements of the array\n");
	//fflush(stdout);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter element to find :");
	//fflush(stdout);
	scanf("%d",&ele);
	pos=binsearch(arr,ele,0,n);
	if(pos==0){
		printf("Element Not Found");
	}
	else{
		printf("Found at %d location",pos);
	}
	return(0);
}

int binsearch(int b[], int ele, int low, int high){
	static int mid;
	if(low<=high){
		mid=(low+high)/2;
		if(ele<b[mid]){
			high=mid-1;
			binsearch(b,ele,low,high);
		}
		else if(ele>b[mid]){
			low=mid+1;
			binsearch(b,ele,low,high);
		}
		else if(ele==b[mid]){
			return(mid+1);
		}
		else{
			return(0);
		}
	}
	else{
		return(0);
	}
}
