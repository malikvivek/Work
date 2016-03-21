//////////////////////////////////////////////////////////////////////////////////////
//Name 			:fib_srch.c
//Copyright 	:Copyright Vivek Malik,2012
//Created on	:25-Apr-2012
//Author		:Vivek Malik
//Description 	:Search an element using Fibonacci Search
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

int fibonacci_search(int list[],int n,int a){
	int f1,f2,mid,first,index;
	f1=1; f2=0; mid=2;                      //initialise the first two fibonacci
											//numbers. F1 will be the main
	while (f1<n){                          //set F1 to a number >= n
		f1=f1+f2;
		f2=f1-f2;
		mid++;
	}
	f2=f1-f2;                               //set F1 to the largest number <=n
	f1=f1-f2;
	mid--;
	first=0;
	while (mid>0){                         //loop
		index=first+f1;
//		printf("\nfirst:%d,index:%d,f1:%d,list:%d,mid:%d,a:%d",first,index,f1,list[index],mid,a);
		if (index>=n || a<list[index]){
			mid--;                    //if the number is bigger, move back
			f2=f1-f2;                 //to a smaller fibonacci number
			f1=f1-f2;
		}
		else if (a==list[index]){
            return(index);			//found: return the index
		}
		else{
			first=index;              //if the number is smaller, move to the
			mid=mid-2;                //second part of the list and
			f1=f1-f2;                 //reduce F1 back two F-numbers
			f2=f2-f1;
		}
	}
	return(-1);                             //bad luck: not found
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int arr[50], pos, ele, n, i;
	printf("Enter no. of elements in the array:");
	scanf("%d",&n);
	printf("Enter elements of the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter element to find :");
	scanf("%d",&ele);
	pos=fibonacci_search(arr,n,ele);
	if(pos==-1){
		printf("Element Not Found");
	}
	else{
		printf("\nFound at %d location",(pos+1));
	}

	return(0);
}
