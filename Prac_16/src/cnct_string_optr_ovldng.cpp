//////////////////////////////////////////////////////////////////////////////////////////
//Name 			: cnct_string_optr_ovldng.cpp
//Copyright 	: Copyright Vivek Malik;2011
//Created on	: 20-Nov-2011
//Author		: Vivek Malik
//Description 	: Join two strings by overloading binary plus operator
//////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class strings{
	char str[50];
public:
	strings(){
		str[0]='\0';
	}
	void enter(){
		cout<<"ENTER STRING 	:";
		gets(str);
	}
	strings operator + (strings s){
		strings temp;
		strcat(temp.str,str);
		strcat(temp.str,s.str);
		return (temp);
	}
	void display(){
		cout<<"STRINGS AFTER JOINING IS:"<<str<<endl;
	}
};

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	strings s1,s2,s3;
	s1.enter();
	s2.enter();
	s3=s1+s2;
	s3.display();
}
