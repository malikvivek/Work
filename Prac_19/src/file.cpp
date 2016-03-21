//////////////////////////////////////////////////////////////////////////////////////////
//Name 			: file.cpp
//Copyright 	: Copyright Vivek Malik;2011
//Created on	: 20-Nov-2011
//Author		: Vivek Malik
//Description 	: Find the no. of spaces in a text file
//////////////////////////////////////////////////////////////////////////////////////////

/*#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int count=0;
	fstream f1;
	char ch[80];
	f1.open("abc.txt", ios::out);
	if(!f1){
		cout<<"File opening error";
		exit(0);
	}
	cout<<"Enter data of file(Enter ## to terminate)"<<endl;
	do{
		gets(ch);
		for(int i=0;i<strlen(ch);i++){
			f1.put(ch[i]);
		}
		f1.put('\n');
	}while(strcmp(ch,"##")!=0);
	f1.close();
	f1.open("abc.txt", ios::in);
	cout<<"The Data of file is :"<<endl;
	while(!f1.eof()){
		f1.getline(ch,80);
		cout<<ch<<"\n";
		for(int i=0;i<strlen(ch);i++){
			if(ch[i]==' '){
				count++;
			}
		}
	}
	cout<<"The no. of spaces are :"<<count;
	f1.close();
	return(0);
}
*/

//------------------------------------
//  tree.cpp
//  Expression tree
//  (c) Bartosz Milewski, 1994
//------------------------------------

#include <iostream>
using std::cout;
using std::endl;

class Node
{
public:
    virtual ~Node () {}
    virtual double Calc () const = 0;
};

class NumNode: public Node
{
public:
    NumNode (double num) : _num (num) {}
    double Calc () const;
private:
    const double _num;
};

class BinNode: public Node
{
public:
    BinNode (Node * pLeft, Node * pRight)
    : _pLeft (pLeft), _pRight (pRight) {}
    ~BinNode ();
protected:
    Node * const _pLeft;
    Node * const _pRight;
};

class AddNode: public BinNode
{
public:
    AddNode (Node * pLeft, Node * pRight)
    : BinNode (pLeft, pRight) {}
    double Calc () const;
};

class MultNode: public BinNode
{
public:
    MultNode (Node * pLeft, Node * pRight)
    : BinNode (pLeft, pRight) {}
    double Calc () const;
};

BinNode::~BinNode ()
{
    delete _pLeft;
    delete _pRight;
}

double NumNode::Calc () const
{
    cout << "Numeric node "<< _num << endl;
    return _num;
}

double AddNode::Calc () const
{
    cout << "Adding\n";
    return _pLeft->Calc() + _pRight->Calc ();
}

double MultNode::Calc () const
{
    cout << "Multiplying\n";
    return _pLeft->Calc () * _pRight->Calc ();
}

int main ()
{
    // ( 20.0 + (-10.0) ) * 0.1
    Node* pNode1 = new NumNode (20.0);
    Node* pNode2 = new NumNode (-10.0);
    Node* pNode3 = new AddNode (pNode1, pNode2);
    Node* pNode4 = new NumNode (0.1);
    Node* pNode5 = new MultNode (pNode3, pNode4);
    cout << "Calculating the tree\n";
    double x = pNode5->Calc ();
    cout << x << endl;
    delete pNode5; // and all children
    return(0);
}
