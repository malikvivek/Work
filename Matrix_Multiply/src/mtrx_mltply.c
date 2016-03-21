//////////////////////////////////////////////////////////////////////////////////////
//Name			:mtrx_mltply.c
//Copyright 	:Copyright Vivek Malik, 2012
//Created on	:23-Apr-2012
//Author		:Vivek Malik
//Description	:To perform Matrix Multiplication
//////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<math.h>

void matrix_multiply(){
	int matrix_A[50][50],matrix_B[50][50],i,j,k,m,n,p,q;
	do{
		printf("Enter the order of Matrix A (mXn)[max order 50x50]:");
		scanf("%d%d",&m,&n);
		printf("Enter the order of Matrix B (pXq)[max order 50x50]:");
		scanf("%d%d",&p,&q);
		if(n!=p){
			printf("\nCannot Multiply, order doesn't satisfy criteria of n=p\n\n");
		}
	}while(n!=p);
	int matrix_C[m][q];
	printf("\nEnter Matrix A :\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matrix_A[i][j]);
		}
	}
	printf("\nEnter Matrix B :\n");
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			scanf("%d",&matrix_B[i][j]);
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<q;j++){
			matrix_C[i][j]=0;
			for(k=0;k<m;k++){
				matrix_C[i][j]=matrix_C[i][j]+(matrix_A[i][k]*matrix_B[k][j]);
			}
		}
	}
	printf("\nThe Resultant Matrix after Multiplication is :\n");
	for(i=0;i<m;i++){
		for(j=0;j<q;j++){
			printf("%d\t",matrix_C[i][j]);
		}
		printf("\n");
	}
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	matrix_multiply();
	return(0);
}
