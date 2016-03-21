//////////////////////////////////////////////////////////////////////////////////////////
//Name			: sope_resolution.cpp
//Copyright		: Copyright Vivek Malik; 2011
//Created on	: 09-Oct-2011
//Author		: Vivek Malik
//Description	: Show the use of scope resolution operator
//////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<stdio.h>
using namespace std;

int a;

class scope_resolution{
	int a;
	int b;
	int c;
	void display(){
		cout<<"The sum is :"<<c;
	}
public:
	void result();
};

void scope_resolution::result(){
	cout<<"Enter value of Global a :";
	cin>>::a;
	cout<<"Enter Value of Local  a :";
	cin>>a;
	cout<<"Enter Value of b 	:";
	cin>>b;
	c=(::a+b);
	cout<<"Using Global value of a ";
	display();
	c=(a+b);
	cout<<"\nUsing Local value of a  ";
	display();
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	scope_resolution ob1;
	ob1.result();
	return(0);
}
