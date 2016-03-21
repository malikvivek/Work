//============================================================================
// Name        : Diffie_Hellman.cpp
// Author      : Vivek
// Version     :
// Copyright   : Copyright Vivek Malik, 2011
// Description : Hello World in C++, Ansi-style
//============================================================================

/*#include <iostream>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}*/
#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int alice(int,int,int);
int bob(int,int,int);

int main(){
/*	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);*/

	long int g,x,y,a,b,k1,k2,n;

	cout<<"\n\t Enter value of n & g";
	cin>>n>>g;

	cout<<"\n\t Enter value of x & y";
	cin>>x>>y;

	a=alice(n,g,x);
	cout<<"\n\t alice end value:"<<a;

	b=bob(n,g,y);
	cout<<"\n\t bob end value:"<<b;

	k1=alice(n,b,x);
	cout<<"\n\t valueof k1 :"<<k1;

	k2=alice(n,a,y);
	cout<<"\n\t valueof k2 :"<<k2;

	return(0);
}

int alice(int n,int g,int x){
	long int a,a1;
	a1=pow(g,x);
	a=a1%n;
	return(a);
}

int bob(int n,int g,int y){
	long int b,b1,k2,t2;
	b1=pow(g,y);
	b=b1%n;
	return(b);
}
