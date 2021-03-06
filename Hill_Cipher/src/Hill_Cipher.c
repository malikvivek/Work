/*
 ============================================================================
 Name        : Hill_Cipher.c
 Author      : Vivek
 Version     :
 Copyright   : Copyright Vivek Malik, 2011
 Description : Hill Cipher
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!!
	return EXIT_SUCCESS;
}*/

//Aim:To implement Hill Cipher in C
//Program:

#include<stdio.h>

int check(int x){
	if(x%3==0)
		return 0;
	int a=x/3;
	int b=3*(a+1);
	int c=b-x;
	return c;
}

int main(){

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int l,i,j;
	int temp1;
	int k[3][3];
	int p[3][1];
	int c[3][1];
	char ch;
	printf("\nThe cipher has a key of length 9. i.e. a 3*3 matrix.\nEnter the 9 character key. ");

	for(i=0;i<3;++i){
		for(j=0;j<3;++j){
			scanf("%c",&ch);
			if(65<=ch && ch<=91)
				k[i][j]=(int)ch%65;
			else
				k[i][j]=(int)ch%97;
		}
	}

	for(i=0;i<3;++i){
		for(j=0;j<3;++j){
			printf("%d ",k[i][j]);
		}
		printf("\n");
	}


	printf("\nEnter the length of string to be encoded(without spaces). ");
	scanf("%d",&l);

	temp1=check(l);

	if(temp1>0)
		printf("You have to enter %d bogus characters.",temp1);

	char pi[l+temp1];
	printf("\nEnter the string. ");
	for(i=-1;i<l+temp1;++i){
		scanf("%c",&pi[i]);
	}

	int temp2=l;
	int n=(l+temp1)/3;
	int temp3;
	int flag=0;
	int count;
	printf("\n\nThe encoded cipher is : ");

	while(n>0){
		count=0;
		for(i=flag;i<flag+3;++i){
			if(65<=pi[i] && pi[i]<=91)
				temp3=(int)pi[i]%65;
			else
				temp3=(int)pi[i]%97;

			p[count][0]=temp3;
			count=count+1;
		}

		int k1;
		for(i=0;i<3;++i)
			c[i][0]=0;

		for(i=0;i<3;++i){
			for(j=0;j<1;++j){
				for(k1=0;k1<3;++k1)
					c[i][j]+=k[i][k1]*p[k1][j];
			}
		}

		for(i=0;i<3;++i){
			c[i][0]=c[i][0]%26;
			printf("%c ",(char)(c[i][0]+65));
		}

		n=n-1;
		flag=flag+3;
	}
	return(0);
}

/*OUTPUT
[adi@localhost Desktop]$ gcc hill.c
[adi@localhost Desktop]$ ./a.out

The cipher has a key of length 9. ie. a 3*3 matrix.
Enter the 9 character key. GYBNQKURP
6 24 1
13 16 10
20 17 15

Enter the length of string to be encoded(without spaces). 6

Enter the string. actCAt


The encoded cipher is : P O H F I N


[adi@localhost Desktop]$ gcc hill.c
[adi@localhost Desktop]$ ./a.out

The cipher has a key of length 9. ie. a 3*3 matrix.
Enter the 9 character key. GYBNQKURP
6 24 1
13 16 10
20 17 15

Enter the length of string to be encoded(without spaces). 7
You have to enter 2 bogus characters.
Enter the string. actcatact


The encoded cipher is : P O H F I N P O H

*/
