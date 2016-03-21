//////////////////////////////////////////////////////////////////////////////////////////
//Name 			: file.cpp
//Copyright 	: Copyright Vivek Malik;2011
//Created on	: 20-Nov-2011
//Author		: Vivek Malik
//Description 	: Creation of Binary File and display its data
//////////////////////////////////////////////////////////////////////////////////////////

#include<fstream>
#include<iostream>
#include<stdio.h>
using namespace std;
class student{
	char name[50];
	int roll_number;
public:
	void getdata(){
		cout<<"Enter name of the Student: ";
		gets(name);
		cout<<"Enter Roll Number:";
		cin>>roll_number;
	}
	void putdata(){
		cout<<"\nName:"<<name<<"\n";
		cout<<"Roll Number:"<<roll_number<<"\n";
	}
};
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	//Store data in file
	ofstream o1;
	student s,s2;
	s.getdata();
	o1.open("Student_DB",ios::binary);
	o1.write((char*)&s,sizeof(s));
	o1.close();

	//Now we will retrieve data
	ifstream o2;
	o2.open("Student_DB",ios::binary);
	o2.read((char*)&s2,sizeof(s2));
	cout<<"\nOutput from the file is as follows:";
	s2.putdata();
	o2.close();
	return 0;
}
