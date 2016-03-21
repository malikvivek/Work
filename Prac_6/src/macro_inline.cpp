//////////////////////////////////////////////////////////////////////////////////////////
//Name 			: macro_inline.cpp
//Copyright 	: Copyright Vivek Malik;2011
//Created on	: 07-Nov-2011
//Author		: Vivek Malik
//Description 	: Show the use of macros and inline functions
//////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<stdio.h>
#define NO_OF_OBJ 2
using namespace std;

class max_of_num{
private:
	int num1;
	int num2;
	int num3;
	void input(){
		cout<<"Please Enter 1st number : ";
		cin>>num1;
		cout<<"Please Enter 2nd number : ";
		cin>>num2;
		cout<<"Please Enter 3rd number : ";
		cin>>num3;
	}
public:
	void maximum(){
		input();
		if(num1>num2&&num1>num3){
			cout<<"The Greatest of the three is :"<<num1<<endl;
		}
		else if(num2>num1&&num2>num3){
			cout<<"The Greatest of the three is :"<<num2<<endl;
		}
		else{
			cout<<"The Greatest of the three is :"<<num3<<endl;
		}

	}
};

int main(){
	max_of_num ob1[NO_OF_OBJ];
	for(int i=0;i<NO_OF_OBJ;i++){
		ob1[i].maximum();
	}
}
