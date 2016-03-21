//////////////////////////////////////////////////////////////////////////////////////
//Name 			:extended_euclid.c
//Copyright		:Copyright Vivek Malik,2012
//Created on	:23-Apr-2012
//Author		:Vivek Malik
//Description	:Find GCD of 2 numbers using extended euclid algorithm
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<math.h>

void extended_euclid (int a, int b, int *gcd, int *x, int *y) {
	*x=0;
	*y=1;
	int u=1, v=0, m, n, q, r;
	*gcd = b;
	while (a!=0){
		q=*gcd/a;
		r=*gcd%a;
		m=(*x)-u*q;
		n=(*y)-v*q;
		*gcd=a;
		a=r;
		*x=u;
		*y=v;
		u=m;
		v=n;
	}
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int num1,num2,gcd,x,y;
	printf("Enter 1st number	:");
	scanf("%d",&num1);
	printf("Enter 2nd number	:");
	scanf("%d",&num2);
	extended_euclid(num1,num2,&gcd,&x,&y);
	printf("The eqn is 		:ax + by =gcd");
	printf("\nGCD is 			:%d",gcd);
	printf("\nValue of x is		:%d",x);
	printf("\nValue of y is 		:%d",y);
	return(0);
}
