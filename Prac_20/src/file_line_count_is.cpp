//////////////////////////////////////////////////////////////////////////////////////////
//Name 			: file.cpp
//Copyright 	: Copyright Vivek Malik;2011
//Created on	: 20-Nov-2011
//Author		: Vivek Malik
//Description 	: Convert lower case characters to upper case in a text file
//////////////////////////////////////////////////////////////////////////////////////////

#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
using namespace std;

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	ofstream f1;
	char ln[80], ch;
	f1.open("text.txt", ios::out);
	if(!f1){
		cout<<"file opening error";
		exit(0);
	}
	cout<<"Enter a line of text(Enter ## to terminate) :"<<endl;
	do{
		gets(ln);
		for(int i=0;i<strlen(ln);i++){
			f1.put(ln[i]);
		}
		f1.put('\n');
	}while(strcmp(ln,"##")!=0);
	f1.close();
	ifstream f2;
	f2.open("text.txt",ios::in);
	ofstream f3;
	f3.open("text1.txt",ios::out);
	while(!f2.eof()){
		f2.getline(ln,80);
//		if(strcmp(ln,"")!=0)
//		{
			for(int i=0;i<strlen(ln);i++){
				ch=toupper(ln[i]);
				f3.put(ch);
			}
			f3.put('\n');
//		}
	}
	f2.close();
	f3.close();
	ifstream f4;
	f4.open("text1.txt", ios::in);
	while(!f4.eof()){
		f4.getline(ln,80);
		if(strcmp(ln,"##")!=0)
		{
			cout<<ln<<"\n";
		}
	}
	f4.close();
	return(0);
}
