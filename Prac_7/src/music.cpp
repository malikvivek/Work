//////////////////////////////////////////////////////////////////////////////////////////
//Name 			: Serial.cpp
//Copyright 	: Copyright, Vivek Malik; 2011
//Created on	: 07-Nov-2011
//Author		: Vivek Malik
//Description 	: Accepting Serial Data and displaying the airtime and no. of episodes
//////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<stdio.h>
using namespace std;

class serial{
		int serial_code;
		char title[20];
		float duration;
		int noofepisodes;
public:
		serial(){
				duration=30.0;
				noofepisodes=10;
		}
		void newserial();
		void otherentries();
		void dispdata();
};

void serial::newserial(){
	char choice='y';
	cout<<"Please Enter Title		:";
	gets(title);
	cout<<"Please Enter Serial Code	:";
	cin>>serial_code;
	cout<<"Do you want custom no. of episodes and duration for the serial(y=yes;n=no) :";
	cin>>choice;
	if(choice=='y'){
		otherentries();
	}
}

void serial::otherentries(){
	float num1;
	int num2;
	cout<<"Please Enter Duration 	:";
	cin>>num1;
	cout<<"Please Enter No. Of Episodes :";
	cin>>num2;
	duration=num1;
	noofepisodes=num2;
}

void serial::dispdata(){
	cout<<endl<<"Serial Code 		:"<<serial_code;
	cout<<endl<<"Title 			:"<<title;
	cout<<endl<<"No. Of Episodes 	:"<<noofepisodes;
	cout<<endl<<"Duration 		:"<<duration<<"min. per episode";
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	serial ob;
	ob.newserial();
	ob.dispdata();
	return(0);
}
