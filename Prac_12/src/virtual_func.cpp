//////////////////////////////////////////////////////////////////////////////////////////
//Name 			: virtual_func.cpp
//Copyright 	: Copyright Vivek Malik;2011
//Created on	: 20-Nov-2011
//Author		: Vivek Malik
//Description	: Show use of virtual functions
//////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class triangle{
	int h,b;
	float area;
public:
	virtual void input(){
		cout<<"ENTER HEIGHT:";
		cin>>h;
		cout<<"ENTER BASE:";
		cin>>b;
	}
	virtual void calc(){
		area=0.5*b*h;
		cout<<"AREA IS:"<<area<<endl<<endl;
	}
};

class rectangle:public triangle{
	int a,b;
	float area;
public:
	void input(){
		cout<<"ENTER 2 SIDES:"<<endl<<endl;
		cin>>a>>b;
	}
	void calc(){
		area=a*b;
		cout<<"AREA IS:"<<area<<endl<<endl;
	}
};

class circle:public rectangle{
	int r;
	float area;
public:
	void input(){
		cout<<"ENTER RADIUS:";
		cin>>r;
	}
	void calc(){
		area=3.14*r*r;
		cout<<"AREA IS:"<<area<<endl<<endl;
	}
};

int main(){
	int ch;
	do{
		cout<<"1.TRIANGLE"<<endl;
		cout<<"2.RECTANGLE"<<endl;
		cout<<"3.CIRCLE"<<endl;
		cout<<"0.Exit"<<endl;
		cout<<"ENTER CHOICE:";
		cin>>ch;
		switch(ch){
		case 1:{
			triangle t;
			t.input();
			t.calc();
			break;
		}
		case 2:{
			rectangle r;
			r.input();
			r.calc();
			break;
		}
		case 3:{
			circle c;
			c.input();
			c.calc();
			break;
		}
		case 0:
			exit(0);
			break;
		default:
			cout<<"Invalid Choice";
			break;
		}
	}while(ch!=0);
	return(0);
}
