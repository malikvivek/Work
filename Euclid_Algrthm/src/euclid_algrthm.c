//////////////////////////////////////////////////////////////////////////////////////
//Name 			:euclid_algrthm.c
//Copyright 	:Copyright Vivek Malik, 2012
//Created on	:23-Apr-2012
//Author		:Vivek Malik
//Description	:Finding GCD of two numbers using Euclid algorithm
//////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<math.h>

int euclid(int a, int b){
	if(b==0){
		return(a);
	}
	else{
		return euclid(b,(a%b));
	}
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int num1,num2,gcd;
	printf("Enter 1st number	:");
	scanf("%d",&num1);
	printf("Enter 2nd number	:");
	scanf("%d",&num2);
	gcd=euclid(num1,num2);
	printf("The GCD of %d and %d is 	:%d",num1,num2,gcd);
	return(0);
}
