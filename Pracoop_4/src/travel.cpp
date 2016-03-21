//////////////////////////////////////////////////////////////////////////////////////////
//Name			: travel.cpp
//Copyright		: Copyright Vivek Malik;2011
//Created on	: 02-Oct-2011
//Author		: Vivek Malik
//Description	: Find the no.of busses required depending upon no. of passengers.
//////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstdlib>
#include<time.h>

using namespace std;

class travel{
	int no_of_bus;
	char name[20];
	int no_of_passengers;
	int ticket_no;
	void calc_ticket_no(){
		srand(time(NULL));
		ticket_no=rand()%10000;
	}
public:
	void calculate_no_of_bus();
	void get_data();
	void dispaly();
};

void travel::calculate_no_of_bus(){
	srand(time(NULL));
	no_of_passengers=rand()%5;
	if(no_of_passengers==0){
		no_of_bus=1;
	}
	else if(no_of_passengers==1){
		no_of_bus=2;	}
	else if(no_of_passengers==3){
		no_of_bus=3;
	}
	else{
		no_of_bus=4;
	}
	for(int i=0;i<=no_of_passengers;i++){
		get_data();
	}

}

void travel::get_data(){
	cout<<"Please Enter your name :";
	gets(name);
	calc_ticket_no();
	cout<<"Your ticket no is :"<<ticket_no<<endl;
}

void travel::dispaly(){
	cout<<"No. of Busses required :"<<no_of_bus;
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	travel ob1;
//	ob1.get_data();
	ob1.calculate_no_of_bus();
	ob1.dispaly();
	return(0);
}
