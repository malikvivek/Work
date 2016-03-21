//////////////////////////////////////////////////////////////////////////////////////////
//Name 			: date_inc_optr_ovldng.cpp
//Copyright 	: Copyright Vivek Malik;2011
//Created on	: 20-Nov-2011
//Author		: Vivek Malik
//Description 	: Increment date by overloading unary plus operator
//////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stdio.h>
using namespace std;

class date{
	int day,month,year;
public:
	date(int d,int m,int y){
		day=d;
		month=m;
		year=y;
	}
	void show(){
		cout<<endl<<"The next date is :";
		cout<<day<<"-"<<month<<"-"<<year<<endl;
	}
	int maxday(){
		int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		if(month==2){
			if(((year%4==0)&&(year%100!=0))||(year%400==0)){
				return 29;
			}
		}
		else{
			return m[month-1];
		}
	}
	void operator ++(){
		++day;
		if(day>maxday()){
			day=1;
			month++;
			if(month>12){
				month=1;
				year++;
			}
		}
		else if(day>maxday()&&month>12){
			day=1;
			month=1;
			year++;
		}
		else if(month>=12){
			day=1;
			month=1;
			year++;
		}
	}
};

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int d,m,y;
	cout<<"ENTER DAY:";
	cin>>d;
	cout<<"ENTER MONTH:";
	cin>>m;
	cout<<"ENTER YEAR:";
	cin>>y;
	date d1(d,m,y);
	++d1;
	d1.show();
	return(0);
}
