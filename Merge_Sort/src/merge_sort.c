//////////////////////////////////////////////////////////////////////////////////////////
//Name			:Merge_Sort.c
//Copyright		:Copyright Vivek Malik, 2011
//Created on	:28-Nov-2011
//Author		:Vivek Malik
//Description	:Sorting an array using Merge Sort Algorithm
//////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<math.h>

void mergesort(int array_to_sort[], int, int);
void merge(int array_to_sort[], int, int, int);

int array_to_display[50];

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int i,arr[50],n;
	printf("Please Enter the size of the array(Maximum 50):");
	scanf("%d",&n);
	printf("Elements of the array :\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	mergesort(arr,0,n-1);
	printf("\nThe Sorted array is :  ");
	for(i=0;i<n;i++){
		printf("%d\t",array_to_display[i]);
	}
	return(0);
}

void mergesort(int array_to_sort[],int left, int right){
    int splitpos;
    if (left < right){
        // Partition the array into two subarrays, sort these subarrays recursively and then merge them into
        // a correctly sorted array.
        splitpos = (left + right) / 2;
        mergesort(array_to_sort,left, splitpos);
        mergesort(array_to_sort,splitpos + 1, right);
        merge(array_to_sort,left, splitpos, right);
    }
}

void merge(int array_to_sort[],int left, int splitpos, int right){
    int size_array1 = splitpos - left + 1;
    int size_array2 = right - splitpos;
    int array1[size_array1];
    int array2[size_array2];
    int i = 0;
    int j = 0;
    int k;

    // Copy both sub-arrays to auxilary arrays.

    for (i = 0; i < size_array1; i++){
        array1[i] = array_to_sort[left + i];
    }

    for (j = 0; j < size_array2; j++){
        array2[j] = array_to_sort[splitpos + j + 1];
    }
    i = 0;
    j = 0;
    for (k = left; k <= right; k ++){
    	if ( j == size_array2 ){
            array_to_sort[k] = array1[i];
            i++;
        }
        else if ( i == size_array1 ){
            array_to_sort[k] = array2[j];
            j++;
        }
        else if (array1[i] <= array2[j]){
            array_to_sort[k] = array1[i];
            i++;
        }
        else{
            array_to_sort[k] = array2[j];
            j++;
        }
    }
    for(i=0;i<=right;i++){
    	array_to_display[i]=array_to_sort[i];
    }
}

/*
void merge_sort(int a[],int low,int high){
	int mid;
	if(low<high){
		mid = (low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge_arr(a,low,mid,high);
	}
}

void merge_arr(int a[], int low, int mid, int high){
	int n,m,i,j,k,x;
	n=mid-low+1;
	m=high-mid;
	int left[n+1];
	int right[m+1];
	for(i=0;i<n;i++){
		left[i]=a[low-i+1];
	}
	for(j=0;j<m;j++){
		right[i]=a[mid+j];
	}
//	left[n+1]=INF;
//	right[m+1]=INF;
	i=0;
	j=0;
	for(k=low;k<high;k++){
		if(left[i]<right[j]){
			a[k]=left[i];
			i=i+1;
		}
		else{
			a[k]=right[j];
			j=j+1;
		}
	}
	printf("Sorted array is : ");
	for(x=1;x<=high;x++){
		printf("%d ",a[x]);
	}
}*/
