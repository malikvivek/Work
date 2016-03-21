//////////////////////////////////////////////////////////////////////////////////////////
//Name 			: add_cmplx_optr_ovldng.cpp
//Copyright 	: Copyright Vivek Malik;2011
//Created on	: 20-Nov-2011
//Author		: Vivek Malik
//Description 	: Add two complex number by overloading binary plus operator
//////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stdio.h>
using namespace std;

class complex{
	float r,i;
public:
	complex(){
		r=0.0;
		i=0.0;
	}
	void getdata(){
		cout<<"ENTER REAL PART:";
		cin>>r;
		cout<<"ENTER IMAGINARY PART:";
		cin>>i;
	}
	complex operator +(complex c2){
		complex temp;
		temp.r=r+c2.r;
		temp.i=i+c2.i;
		return temp;
	}
	void outdata(){
		cout<<"AFTER ADDITION:";
		cout<<endl<<r<<"+ "<<i<<"i";
	}
};

int main(){
	complex c1,c2,c3;
	cout<<"ENTER FIRST COMPLEX NUMBER"<<endl;
	c1.getdata();
	cout<<"ENTER SECOND COMPLEX NUMBER"<<endl;
	c2.getdata();
	c3=c1+c2;
	c3.outdata();
	return(0);
}
