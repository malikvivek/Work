//////////////////////////////////////////////////////////////////////////////////////
//Name        : Warshal.c
//Author      : Vivek
//Copyright   : Copyright Vivek Malik, 2012
//Date		  : 1-May-2012
//Description : Implementing Floyd Warshall Algorithm to find all pair shortest path
//////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int min(int a, int b){
	if(a<b)
		return a;
	else
		return b;
}

void floyd(int);
int w[MAX][MAX], d[MAX][MAX][MAX];

void main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int i, j,k,v;
	printf("enter the no. of vertices\n");
	scanf("%d",&v);
	printf("enter the weights \n");
	for(i=1;i<=v;i++){
		for(j=1;j<=v;j++){
			scanf("%d",&w[i][j]);
		}
	}
	floyd(v);
// getch();
}//end of main

void floyd(int v){
	int k,i,j;
	k=0;
	for(i=1;i<=v;i++){
		for(j=1;j<=v;j++){
			d[k][i][j]=w[i][j];
		}
	}
	for(k=1;k<=v;k++){
		for(i=1;i<=v;i++){
			for(j=1;j<=v;j++){
				d[k][i][j]=min(d[k-1][i][j], d[k-1][i][k]+ d[k-1][k][j]);
			}
		}
	}
 //displayin matrix
	for(k=0;k<=v;k++){
		printf("k=%d ",k);
		for(i=1;i<=v;i++){
			printf("\n");
			for(j=1;j<=v;j++){
				printf("\t %d",d[k][i][j]);
			}
		}
		printf("\n");
	}
}
