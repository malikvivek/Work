//////////////////////////////////////////////////////////////////////////////////////////
//Name 			: func_overloding.cpp
//Copyright 	: Copyright Vivek Malik;2011
//Created on	: 20-Nov-2011
//Author		: Vivek Malik
//Description 	: overloading area function
//////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

void area(int a,int b,int c){
	int s;
	s=(a+b+c)/2;
	float area;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	cout<<"AREA IS:"<<area<<endl;
}

void area(int a,int b){
	int area;
	area=a*b;
	cout<<"AREA IS:"<<area<<endl;
}

void area(int a){
	int area;
	area=a*a;
	cout<<"AREA IS:"<<area<<endl;
}

void area(float a){
	float area;
	area=3.14*a*a;
	cout<<"AREA IS:"<<area<<endl;
}

int main(){
	int ch,a,b,c;
	float d;
	do{
		cout<<"1.TRIANGLE"<<endl;
		cout<<"2.RECTANGLE"<<endl;
		cout<<"3.SQUARE"<<endl;
		cout<<"4.CIRCLE"<<endl;
		cout<<"0.Exit"<<endl;
		cout<<"ENTER CHOICE:";
		cin>>ch;
		switch(ch){
		case 1:
			cout<<"ENTER THREE SIDES:";
			cin>>a>>b>>c;
			area(a,b,c);
			break;
		case 2:
			cout<<"ENTER TWO SIDES:";
			cin>>a>>b;
			area(a,b);
			break;
		case 3:
			cout<<"ENTER SIDE:";
			cin>>a;
			area(a);
			break;
		case 4:
			cout<<"ENTER RADIUS:";
			cin>>d;
			area(d);
			break;
		case 0:
			exit(0);
		default:
			cout<<"WRONG OPTION";
			break;
		}

	}while(ch!=0);
	return(0);
}
