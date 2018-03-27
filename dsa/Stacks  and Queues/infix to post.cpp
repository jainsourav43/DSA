#include<iostream>
#include<string.h>
using namespace std;
struct stack
{
	int size;
	int top;
	char ele[50];
};
void push(stack &s1,char x )
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
char pop(stack &s1)
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
int prior(char ch)
{
	if(ch=='*'||ch=='/')
	return 2;
	else if(ch=='+'||ch=='-')
	return 1;
	else if(ch=='^')
	return 3;
}
int main()
{
	stack s;
	s.top=-1;
	s.size=50;
	int i,j,k,l;
	char arr[50];
	cout<<"Enter the infix expression \n";
	cin>>arr;
	for(i=0;i<strlen(arr);i++)
	{
		if(arr[i]=='+'||arr[i]=='-'||arr[i]=='*'||arr[i]=='/'||arr[i]=='^')
		{
			if(s.top==-1)
			push(s,arr[i]);
			else
			{
				for(j=s.top;j>=0;j--)
				{
					if(prior(s.ele[s.top])<prior(arr[i]))
					{
						push(s,arr[i]);
						break;
					}
					else
					{
						cout<<pop(s);
						if(prior(s.ele[s.top])<prior(arr[i]))
						push(s,arr[i]);
					}
					
				}
			}
		}
		else
		{
			cout<<arr[i];
		}
	}
	for(j=s.top;j>=0;j--)
	{
		cout<<pop(s);
	}
	return 0;
}
