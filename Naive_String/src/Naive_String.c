/*
 ============================================================================
 Name        : Naive_String.c
 Author      : Vivek
 Version     :
 Copyright   : Copyright Vivek Malik, 2011
 Description : Hello World in C, Ansi-style
 ============================================================================

*/

#include<string.h>
#include<stdio.h>

void naive_string_matcher(char text[],char pat[]){
	char temp[100];
	int n=strlen(text);
	int m=strlen(pat);
	int j,s,k;
	for(s=0;s<=n;s++){
		for(j=s,k=0;j<m;j++,k++)
			temp[k]=text[s+k];
		temp[k]='\0';
		if(strcmp(pat,temp)==0)
			printf("\nPATTERN OCCURS WITH SHIFT :  %d\n",s+1);
		m++;

	}
}
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char text[100],pat[100];
	printf("ENTER THE TEXT    : ");
	gets(text);
	printf("ENTER THE PATTERN : ");
	gets(pat);
	naive_string_matcher(text,pat);
	return(0);
}

