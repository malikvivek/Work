//////////////////////////////////////////////////////////////////////////////////////
//Name 			:lngst_cmn_sbsqunc.c
//Copyright 	:Copyright Vivek Malik,2012
//Created on	:22-Apr-2012
//Author		:Vivek Malik
//Description 	:Finding longest common subsequence from two sequences
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_lcs(char b[][20],char x[],int i,int j){
	if(i==0 || j==0){
		return;
	}
	if(b[i][j]=='c'){
		print_lcs(b,x,i-1,j-1);
		printf(" %c",x[i-1]);
	}
	else if(b[i][j]=='u'){
		print_lcs(b,x,i-1,j);
	}
	else{
		print_lcs(b,x,i,j-1);
	}
}

void lcs_length(char x[],char y[]){
	int m,n,i,j,c[20][20];
	char b[20][20];
	m=strlen(x);
	n=strlen(y);
	for(i=0;i<=m;i++){
		c[i][0]=0;
	}
	for(i=0;i<=n;i++){
		c[0][i]=0;
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(x[i-1]==y[j-1]){
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]='c'; //c stands for left upright cross
			}
			else if(c[i-1][j]>=c[i][j-1]){
				c[i][j]=c[i-1][j];
				b[i][j]='u'; //u stands for upright or above
			}
			else{
				c[i][j]=c[i][j-1];
				b[i][j]='l'; //l stands for left
			}
		}
	}
	print_lcs(b,x,m,n);
}

int main(){
//	setvbuf(stdout, NULL, _IONBF, 0);
//	setvbuf(stderr, NULL, _IONBF, 0);
	char x[20], y[20];
	printf("1st sequence : ");
	gets(x);
	printf("2nd sequence : ");
	gets(y);
	printf("Longest Common Subsequence is :");
	lcs_length(x,y);
	return(0);
}
