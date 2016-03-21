//////////////////////////////////////////////////////////////////////////////////////////
//Name 			: student.cpp
//Copyright 	: Copyright Vivek Malik;2011
//Created on	: 19-Nov-2011
//Author		: Vivek Malik
//Description 	: Calculate percentage of a student
//////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<stdio.h>
using namespace std;

class student{
	int roll_no;
	char name[20];
	int class_st;
	int marks[5];
	int per;
	int calculate(){
		int sum=0;
		for(int i=0;i<5;i++){
			sum+=marks[i];
		}
		 per=sum/5;
		return per;
	}
public:
	void readmarks();
	void displaydata();

};

void student::readmarks(){
	cout<<"Enter Name 		:";
	gets(name);
	cout<<"Enter Roll No. 		:";
	cin>>roll_no;
	cout<<"Enter Class  		:";
	cin>>class_st;
	cout<<"Please Enter marks of 5 subjects :"<<endl;
	for(int i=0;i<5;i++){
		cin>>marks[i];
	}
	calculate();
}

void student::displaydata(){
	cout<<endl<<"Name 		:"<<name;
	cout<<endl<<"Roll No.	:"<<roll_no;
	cout<<endl<<"Class 		:"<<class_st;
	cout<<endl<<"Percentage 	:"<<per<<"%";

}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	student obj;
	obj.readmarks();
	obj.displaydata();
}
