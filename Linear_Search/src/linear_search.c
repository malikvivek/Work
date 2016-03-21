//////////////////////////////////////////////////////////////////////////////////////
//Name			:Linear Search
//Copyright		:Copyright, Vivek Malik;2011
//Created on	:21-Aug-2011
//Author		:Vivek Malik
//Description	:Finding element in an array using Linear Search Algorithm
//////////////////////////////////////////////////////////////////////////////////////
/*#include<stdio.h>
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int arr[50];
	int ele,n,i,flag=0;
	printf("Enter no. of elements in the array:");
	scanf("%d",&n);
	printf("Enter elements of the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter element to find :");
	scanf("%d",&ele);
	for(i=0;i<n;i++){
		if(arr[i]==ele){
			printf("Element %d found at position :%d",ele,i+1);
			flag=1;
		}
	}
	if(flag==0){
		printf("Element not Found in the Array");
	}
	return(0);
}
*/

#include <stdio.h>
#include<math.h>
int main()
{
	int test_case,x,y,i,j,flag,rem,z,count,t[100][2];
	scanf("%d", &test_case);
	for(i=0;i<test_case;i++)
	{
    	scanf("%d %d",&t[i][0],&t[i][1]);
	}
	for(i=0;i<test_case;i++)
	{
		x=t[i][0];
		y=t[i][1];
		count=0;
		for(j=x;j<=y;++j)
		{
			z=2;
			flag=0;
			do{
				rem=(j%(z*z));
				if(rem==0)
				{
					flag=1;
					break;
				}
				z++;
			}while(z<j);
			if(flag==0){
				count++;
			}
		}
		printf("%d\n",count);
	}

    return 0;
}
