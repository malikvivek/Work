//////////////////////////////////////////////////////////////////////////////////////
//Name 			:bin_srch_itrtv.c
//Copyright		:Copyright Vivek Malik, 2012
//Created on	:19-Apr-2012
//Author		:Vivek Malik
//Description	:Search an element using Iterative Binary Search
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<math.h>

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int c, first, last, middle, n, search, array[100];
	printf("Enter number of elements :");
	scanf("%d",&n);
	printf("\nEnter %d integers in ascending order\n", n);
	for ( c = 0 ; c < n ; c++ ){
		scanf("%d",&array[c]);
	}
	printf("Enter value to find : ");
	scanf("%d",&search);
	first = 0;
	last = n - 1;
	middle = (first+last)/2;
	while( first <= last ){
		if ( array[middle] < search ){
			first = middle + 1;
		}
		else if ( array[middle] == search ){
			printf("%d found at location : %d\n", search, middle+1);
	        break;
		}
		else{
			last = middle - 1;
		}
		middle = (first + last)/2;
	}
	if ( first > last )
		printf("Not found! %d is not present in the list.\n", search);
	return(0);
}
