/*
 * stack_array.c
 *
 *  Created on: 29-Nov-2011
 *      Author: vivek
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

void push(char);
char pop();
void display();
char stack[50];
int top=-1;

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char expr_input[50],c1,c2;
	int num1, num2,num3;
	int i,len;
	//char garbage;
	printf("Enter the Infix Expression:");
	gets(expr_input);
	len=strlen(expr_input);
	for(i=0;i<len;i++){
		if(isdigit(expr_input[i])){
			push(expr_input[i]);
		}
		else{
			c1=pop();
			c2=pop();
			num1=c1-48;
			num2=c2-48;
			switch(expr_input[i]){
			case '+':
				num3=num1+num2;
				break;
			case '-':
				num3=num2-num1;
				break;
			case '*':
				num3=num1*num2;
				break;
			case '/':
				num3=num2/num1;
				break;
			case '^':
				num3=1;
				for(i=0;i<num1;i++)
				{
					num3=num3*num2;
				}
				break;
			default:
				printf("Unknown operator");
				break;
			}
			num3=num3+48;
			push(num3);
		}
	}
	display();
	return(0);
}

void push(char x)
{
	top++;
	stack[top]=x;
}

char pop()
{
	int temp;
	temp=top;
	if(top=='-1')
	{
		printf("underflow");
		exit(2);
	}
	else
	{
		top--;
		return stack[temp];
	}
}

void display(){
	int temp;
	temp=top;
	printf("%c",stack[temp]);
	temp--;
}
