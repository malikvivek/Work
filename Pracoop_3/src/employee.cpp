//////////////////////////////////////////////////////////////////////////////////////////
//Name 			: employee.cpp
//Copyright		: Copyright Vivek Malik;2011
//Created on	: 25-Sep-2011
//Author		: Vivek Malik
//Description	: Calculation of Net Salary using basic pay
//////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

class employee{
	int empno;
	char ename[20];
	float basic_pay;
	float hra;
	float da;
	float netpay;
	void calculate(){
		hra=(10.0/100)*basic_pay;
		da=(20.0/100)*basic_pay;
		netpay=basic_pay+hra+da;
	}
public:
	void havedata();
	void dispdata();
};

void employee::havedata(){
	cout<<"Please Enter your Employee Name		:";
	gets(ename);
	cout<<"Please Enter your Employee No.		:";
	cin>>empno;
	cout<<"Please Enter your basic pay 		: Rs.";
	cin>>basic_pay;
	calculate();
}

void employee::dispdata(){
	cout<<endl<<"Name 		:"<<ename;
	cout<<endl<<"Employee No. 	:"<<empno;
	cout<<endl<<"Net Salary 	:Rs. "<<netpay;
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	employee emp;
	emp.havedata();
	emp.dispdata();
	return(0);
}
