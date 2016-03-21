/*
 ============================================================================
 Name        : RSA_Algo.c
 Author      : Vivek
 Version     :
 Copyright   : Copyright Vivek Malik, 2011
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int phi,M,n,e,d,C,FLAG;

int check(){
	int i;
	for(i=3;e%i==0 && phi%i==0;i+2){
		FLAG = 1;
		return;
	}
	FLAG = 0;
}

void encrypt(){
	int i;
	C = 1;
	for(i=0;i< e;i++)
		C=C*M%n;
	C = C%n;
	printf("\n\tEncrypted keyword : %d",C);
	//printf(“\n\tEncrypted keyword : %d”,C);
}

void decrypt(){
	int i;
	M = 1;
	for(i=0;i< d;i++)
		M=M*C%n;
	M = M%n;
	printf("\n\tDecrypted keyword : %d",M);
//	printf(“\n\tDecrypted keyword : %d”,M);
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int p,q,s;

	printf("Enter Two Relatively Prime Numbers\t:");
	scanf("%d%d",&p,&q);
	//printf(“Enter Two Relatively Prime Numbers\t: “);
	//scanf(“%d%d”,&p,&q);

	n = p*q;
	phi=(p-1)*(q-1);
	printf("\n\tF(n) phi value\t= %d",phi);
	//printf(“\n\tF(n) phi value\t= %d”,phi);
	do{
		//printf(“\n\nEnter e which is prime number and less than phi \t: “,n);
		//scanf(“%d”,&e);
		printf("\n\nEnter e which is prime number and less than phi \t:");
		scanf("%d",&e);

		check();
	}while(FLAG==1);
	d = 1;

	do{
		s = (d*e)%phi;
		d++;
	}while(s!=1);
	d = d-1;

//	printf(“\n\tPublic Key\t: {%d,%d}”,e,n);
//	printf(“\n\tPrivate Key\t: {%d,%d}”,d,n);
	printf("\n\tPublic Key\t: {%d,%d}",e,n);
	printf("\n\tPrivate Key\t: {%d,%d}",d,n);

	printf("\n\nEnter The Plain Text\t:");
	scanf("%d",&M);
//	printf(“\n\nEnter The Plain Text\t: “);
//	scanf(“%d”,&M);

	encrypt();
	printf("\n\nEnter the Cipher text\t:");
//	printf(“\n\nEnter the Cipher text\t: “);
	scanf("%d",&C);
//	scanf(“%d”,&C);
	decrypt();
	return(0);
}
