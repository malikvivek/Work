/////////////////////////////////////////////////////////////////////////////////////////
// infix-post-pre.c
//
//  Created on: 25-Sep-2011
//      Author: vivek
/////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

#include<string.h>
char stack[50];
char top=-1;
void push(char x);
char pop();
int priority(char x);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char expr_input[50];
	char expr_output[50];
	int i=0,j=0;
	char garbage;
	printf("Enter the Infix Expression:");
	gets(expr_input);
	fflush(stdin);
	for(i=0;i<strlen(expr_input);i++)
	{
		if(((expr_input[i]>='a')&&(expr_input[i]<='z'))||((expr_input[i]>='A')&&(expr_input[i]<='Z'))||((expr_input[i]>='0')&&(expr_input[i]<='9')))
		{
			expr_output[j]=expr_input[i];
			j++;
		}
		else
		{
			if((expr_input[i]=='&')||(expr_input[i]=='|')||(expr_input[i]=='!')||(expr_input[i]=='^')||(expr_input[i]=='+')||(expr_input[i]=='-')||(expr_input[i]=='/')||(expr_input[i]=='*')||(expr_input[i]=='%'))
			{
				while((priority(expr_input[i])<=priority(stack[top]))&&(stack[top]!='('))
				{
					expr_output[j]=pop();
					j++;
				}
				push(expr_input[i]);
			}
			else
			{
				if(expr_input[i]=='(')
				{
					push(expr_input[i]);
				}
				else
				{
					if(expr_input[i]==')')
					{
						while(stack[top]!='(')
						{
							expr_output[j]=pop();
							j++;
						}
						garbage=pop();
					}
				}
			}
		}
	}
	while(top!=-1)
	{
		expr_output[j]=pop();
		j++;
	}
	expr_output[j]='\0';
	printf("\n\nThe output postfix is: %s",expr_output);
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
int priority(char x)
{
	int p=0;
	switch(x)
	{
	case '!': p=3;
			break;
	case '&': p=2;
			break;
	case '|': p=1;
			break;
	case '(': p=4;
			break;
	case '^': p=3;
			break;
	case '*':
	case '/':
	case '%':
			  p=2;
			break;
	case '+':
	case '-':
			  p=1;
			break;
	case ')': p=0;
			break;
	}
	return p;
}
