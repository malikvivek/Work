/*
 * postfix_eval.c
 *
 *  Created on: 29-Nov-2011
 *      Author: vivek
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int len,i;
	char arr[5];
	gets(arr);
	len=strlen(arr);
	for(i=0;i<len;i++){
		if(isdigit(arr[i])){
			printf("yes");
		}
	}
	return(0);
}
