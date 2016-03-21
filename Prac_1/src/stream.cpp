//====================================================================================
//	Name		:Stream
//	Copyright	:Copyright Vivek Malik, 2011
//  Created on	:15-Aug-2011
//	Author		:Vivek
//	Description	:Assignment of the stream on the basis of percentage
//====================================================================================
#include<iostream>
#include<stdio.h>
using namespace std;

class student{

private:
	char name[20];
	int roll_no;
	int marks[5];
	int percentage(){
		int sum=0;
		for(int i=0;i<5;i++){
			sum+=marks[i];
		}
		int pctg=sum/5;
		return pctg;
	}
	void input(){
		cout<<"Please Enter Name			:";
		gets(name);
		cout<<"Please Enter Roll no.			:";
		cin>>roll_no;
		cout<<"Please Enter Marks of 5 subjects	:\n";
		for(int i=0;i<5;i++){
			cin>>marks[i];
		}
	}

public:
	void assign();
};

void student::assign(){
	input();
	int pctg;
	pctg=percentage();
	if(pctg>=96){
		cout<<"You have been offered Computer Science Engineering";
	}
	else if(pctg>=91&&pctg<96){
		cout<<"You have been offered Electronics Engineering";
	}
	else if(pctg>=86&&pctg<91){
		cout<<"You have been offered Mechanical Engineering";
	}
	else if(pctg>=81&&pctg<86){
		cout<<"You have been offered Electrical Engineering";
	}
	else if(pctg>=76&&pctg<81){
		cout<<"You have been offered Chemical Engineering";
	}
	else{
		cout<<"Civil";
	}
}

int main(){
	student s;
	s.assign();
	return 0;
}
