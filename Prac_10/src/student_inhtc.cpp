//////////////////////////////////////////////////////////////////////////////////////////
// Name 			: student_inhtc.cpp
// Copyright  		: Copyright Vivek Malik;2011
// Created on		: 19-Nov-2011
// Author			: Vivek Malik
// Description 		: Display student result using multiple inheritance
//////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<stdio.h>
using namespace std;

class student{
protected:
	char name[20];
	int roll_no;
public:
	void student_data();
};

class marks{
protected:
	int marks[5];
public:
	void get_marks();
};

class result:public student,public marks{
	int per;
public:
	int percentage();
	void display();
};

void student::student_data(){
	cout<<"Enter Name 		:";
	gets(name);
	cout<<"Enter Roll No. 		:";
	cin>>roll_no;
}

void marks::get_marks(){
	cout<<"Enter marks of 5 subjects :"<<endl;
	for(int i=0;i<5;i++){
		cin>>marks[i];
	}
}

int result::percentage(){
	student_data();
	get_marks();
	int sum=0;
	for(int i=0;i<5;i++){
		sum+=marks[i];
	}
	per=sum/5;
	return per;
}

void result::display(){
	cout<<endl<<"Name 		:"<<name;
	cout<<endl<<"Roll No.	:"<<roll_no;
	cout<<endl<<"Percentage 	:"<<per<<"%";
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	result obj;
	obj.percentage();
	obj.display();
}
