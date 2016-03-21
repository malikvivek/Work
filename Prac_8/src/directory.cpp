//////////////////////////////////////////////////////////////////////////////////////////
//Name  		: directory.cpp
//Copyright		: Copyright Vivek Malik;2011
//Created on	: 12-Nov-2011
//Author		: Vivek Malik
//Description	: User Telephone Directory data
//////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<stdio.h>
using namespace std;

struct name{
	char first[40];
	char mid[40];
	char last[60];
};

struct phone{
		char area[4];
		char exch[4];
		long number;
};

class p_rec{
	name name_obj;
	phone phone_obj;
public:
	p_rec(){
		phone_obj.number=0;
	}
	void add_record();
	void disp_record();
};

void p_rec::add_record(){
	cout<<"Enter First Name 	:";
	gets(name_obj.first);
	cout<<"Enter Middle Name 	:";
	gets(name_obj.mid);
	cout<<"Enter Last Name 	:";
	gets(name_obj.last);
	cout<<"Enter Area Code 	:";
	gets(phone_obj.area);
	cout<<"Enter Exchange Code 	:";
	gets(phone_obj.exch);
	cout<<"Enter Number 		:";
	cin>>phone_obj.number;
}

void p_rec::disp_record(){
	cout<<endl<<"Name 		:"<<" "<<name_obj.first<<" "<<name_obj.mid<<" "<<name_obj.last;
	cout<<endl<<"Area Code 	:"<<phone_obj.area;
	cout<<endl<<"Exchange Code 	:"<<phone_obj.exch;
	cout<<endl<<"Number 		:"<<phone_obj.number;
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	p_rec record;
	record.add_record();
	record.disp_record();
	return(0);
}
