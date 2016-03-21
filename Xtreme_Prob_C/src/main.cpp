////////////////////////////////////////////////////////////////////////////////////////
//Name: Problem C-IEEEXtreme 5.0
//Created on: 22-Oct-2011
//Author: CodersGtbit
////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<stdio.h>
using namespace std;

void bubble_sort(int b[],int c[], int *);
void display(int b[],int c[], int);

int main(){
	int l[20],n[20];
	int i,j,k;
	static int g=0;
	int counter=0;
	int d,x=0;
	cout<<"Please Enter Distance :";
	cin>>d;
	int max=0;
	cout<<"Please Enter values of length of each rod and corresponding max no. of rods \n";
	for(i=0;i<20;i++){
		cin>>l[i]>>n[i];
		max=max+1;
		if (l[i]==0&&n[i]==0){
			break;
		}
	}
	bubble_sort(l,n,&max);
	for(i=0;i<max-1;i++){
		for(g,k=1;k<=n[g];k++){
			x=x+(l[i]*k);
			counter=counter+k;
			if(x>d){
				k=k-1;
				x=x+(l[i]*k);
				g=g+1;
				break;
			}
		}
		if(x==d){
			break;
		}
	}
	if(x==d){
		cout<<"\n\nThe no. of joints is :"<<counter-6;
	}
	else{
		cout<<"No Solution Possible";
	}
	return(0);
}

void bubble_sort(int b[], int c[], int *high){
	int i,j;
	for(i=0;i<*high-1;i++){
		for(j=i+1;j<*high;j++){
			if(b[i]<b[j]){
				int temp,temp2;
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
				temp2=c[i];
				c[i]=c[j];
				c[j]=temp2;
			}
		}
	}
}

/*void display(int b[],int c[], int high){
	int i;
	printf("The Sorted Array is :\n");
	for(i=0;i<high-1;i++){
		cout<<b[i]<<" "<<c[i]<<"\n";
	}

}*/
