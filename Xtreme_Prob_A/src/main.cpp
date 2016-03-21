//////////////////////////////////////////////////////////////////////////////////////////
//Name: Problem A - IEEEXtreme 5.0
//Created on: 22-Oct-2011
//Author: CodersGtbit
//////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<math.h>
using namespace std;

#define max 100

float mean(int b[], int*);
float std_dev(int b[], int*);

int main(){
	int x[max],y[max];
	int i=0;
	int counter=0;
	float numerator=0;
	float p;
	for(i=0;i<max;i++){
		cin>>x[i]>>y[i];
		counter++;
		if(x[i]==char('-')){
			cout<<x[i];
			break;
		}
	}
	float ux=mean(x,&counter);
	float uy=mean(y,&counter);
	float sd_x=mean(x,&counter);
	float sd_y=mean(y,&counter);
	for(i=0;i<counter;i++){
		numerator=numerator+((x[i]-ux)*(y[i]-uy));
	}
	p=numerator/(sd_x*sd_y);
	if(p<1&&p>(-1)){
		cout<<p;
	}
	//else{
		//cout<<"invalid input";
	//}
	return(0);
}

float mean(int b[], int *high){
	float u;
	int sum=0;
	for(int i=0;i<*high;i++){
		sum=sum+b[i];
	}
	u=sum/(*high);
	return(u);
}

float std_dev(int b[], int *high){
	float u;
	int sum=0;
	float square;
	float sum_sq=0;
	for(int i=0;i<*high;i++){
		sum=sum+b[i];
	}
	u=sum/(*high);
	for(int i=0;i<*high;i++){
		square=pow((b[i]-u),2);
		sum_sq=sum_sq+square;
	}
	float sd=(sqrt(sum_sq))/(*high);
	return(sd);
}
