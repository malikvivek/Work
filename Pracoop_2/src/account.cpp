/*
 * account.cpp
 *
 *  Created on: 07-Nov-2011
 *      Author: vivek
 */
#include<iostream>
#include<stdio.h>
using namespace std;

class account{
	char name[20];
	int acc_no;
	char type_of_acc;
	float balance;
public:
	void initialise();
	void deposit();
	void withdraw();
	void details();
};

void account::initialise(){
	char ch = 'y';
	int choice;
	cout<<"Please Enter your Name  				:";
	gets(name);
	cout<<"Your Account no. please 				:";
	cin>>acc_no;
	cout<<"Account Type(s=savings, c=current)			:";
	cin>>type_of_acc;
	balance=10000.0;
	do{
		cout<<endl<<"1. Deposit Money";
		cout<<endl<<"2. Withdraw Money";
		cout<<endl<<"3. View Account Details";
		cout<<endl<<"Please enter your choice	:";
		cin>>choice;
		switch(choice){
		case 1:
			deposit();
			break;
		case 2:
			withdraw();
			break;
		case 3:
			details();
			break;
		default:
			cout<<"Invalid Entry. Please Enter a Valid choice";
			break;
		}
		cout<<endl<<"Do you wish to continue :";
		cin>>ch;
	}while(ch=='y');
}

void account::deposit(){
	int deposit_amt;
	cout<<"Please enter the amount to deposit Rs. ";
	cin>>deposit_amt;
	balance=balance+deposit_amt;
	cout<<"Your new balance is Rs. "<<balance;
}

void account::withdraw(){
	int withdraw_cash;
	cout<<"Please Enter the amount to withdraw : Rs. ";
	cin>>withdraw_cash;
	if(balance<=10000.0){
		cout<<"Minimum Balance requirement not met. Please Deposit before withdrawal";
	}
	else if((balance - withdraw_cash)<=10000.0){
		cout<<"You can withdraw a maximum of Rs. "<<(balance-10000.0);
	}
	else{
		cout<<"Please collect your cash of Rs. "<<withdraw_cash;
		balance=balance - withdraw_cash;
		cout<<endl<<"Your new balance is Rs. "<<balance;
	}
}

void account::details(){
	cout<<endl<<"Your Account Details are :"<<endl;
	cout<<"Name					:"<<name;
	cout<<endl<<"Account No. 				:"<<acc_no;
	cout<<endl<<"Account type(s=savings, c=current)	:"<<type_of_acc;
	cout<<endl<<"Current Balance				: Rs."<<balance;
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	account ob;
	ob.initialise();
	return(0);
}

