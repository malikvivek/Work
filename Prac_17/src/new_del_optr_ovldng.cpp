//////////////////////////////////////////////////////////////////////////////////////////
//Name 			: new_del_optr_ovldng.cpp
//Copyright 	: Copyright Vivek Malik;2011
//Created on	: 20-Nov-2011
//Author		: Vivek Malik
//Description 	: Overloading new and delete operator
//////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stdio.h>
using namespace std;

class stud{
	int *a;
public:
	void * operator new(unsigned int l){
		stud * my_stud;
		my_stud=::new stud;
		my_stud->a=new int[5];
		return my_stud;
	}
	void operator delete(void * stu){
		stud * my_stud;
		my_stud=(stud *)stu;
		delete (int *)my_stud->a;
		::delete stu;
	}
	void enter(){
		int i;
		for(i=0;i<5;i++){
			cin>>a[i];
		}
	}
	void display(){
		int i;
		for(i=0;i<5;i++){
			cout<<a[i]<<endl;
		}
	}
};

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	stud *s=new stud;
	cout<<"ENTER DATA"<<endl;
	s->enter();
	cout<<"DISPLAYING DATA"<<endl;
	s->display();
	delete s;
	return(0);
}
