#include<iostream>
#include<string.h>
using namespace std;
struct stack
{
int size;
int top;
int ele[50];	
};
void push(stack &s1,int x )
{
	if(s1.top==s1.size-1)
	{
		cout<<"Overflow of stack\n";
	}
	else
	{
		s1.top++;
		s1.ele[s1.top]=x;
	}
}
int pop(stack &s1)
{
	if(s1.top==-1)
	{
		cout<<"Underflow\n";
	}
	else
	{	
	return (s1.ele[s1.top--]);
	}
}
int main()
{
	char arr[50];
	stack s;
	int i,j,res;
	s.top=-1;
	s.size=50;
	cout<<"Enter the postfix expression\n";
	cin>>arr;int a,b,temp;
	for(i=0;i<strlen(arr);i++)
	{
		if(arr[i]<='9'&&arr[i]>='0')
		{
			push(s,arr[i]-'0');
		}
		else
		{
			a=pop(s);
			b=pop(s);
			if(arr[i]=='+')
			{
				temp=b+a;
			}
			else if(arr[i]=='-')
			{
				temp=b-a;
			}
			else if(arr[i]=='*')
			{
				temp=b*a;
			}
			else if(arr[i]=='^')
			{
				temp=b^a;
			}
			else if(arr[i]=='/')
			{
				temp=b/a;
			}
			else if(arr[i]='%')
			{
				temp=b%a;
			}
			push(s,temp);
		}
	}
	res=pop(s);
cout<<"Result \n"<<res;
return 0;
}
