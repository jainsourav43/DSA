#include<iostream>
#include<string.h>
using namespace std;
struct stack1
{
int size;
int top;
int ele[50];	
};
struct stack2
{
	int size;
	int top;
	char ch[50];
};
int prior(char ch)
{
	if(ch=='*'||ch=='/')
	return 2;
	else if(ch=='+'||ch=='-')
	return 1;
	else if(ch=='^')
	return 3;
}
void push(stack1  &s1,int x )
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
int pop(stack1 &s1)
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
void push(stack2 &s1,char x )
{
	if(s1.top==s1.size-1)
	{
		cout<<"Overflow of stack\n";
	}
	else
	{
		s1.top++;
		s1.ch[s1.top]=x;
	}
}
char pop(stack2 &s1)
{
	if(s1.top==-1)
	{
		cout<<"Underflow\n";
	}
	else
	{	
	return (s1.ch[s1.top--]);
	}
}
int main()
{
	stack1 s1;
	stack2 s2;
	s1.size=50;
	s1.top=-1;
	s2.size=50;
	s2.top=-1;
	char arr[50];
	cout<<"Enter the infix \n";
	cin>>arr;
	int i,j,k,l,res,temp;char c;int flag=0;
	for(i=0;i<strlen(arr);i++)
	{
		if(arr[i]=='+'||arr[i]=='-'||arr[i]=='*'||arr[i]=='/')
		{
			if(s2.top==-1)
			push(s2,arr[i]);
			else
			{
				
				for(j=s2.top;j>=0;j--)
				{
					if(prior(s2.ch[s2.top])<prior(arr[i]))
					{
						push(s2,arr[i]);
						break;
					}
					else
					{
						c=pop(s2);
				     	if(c=='+')
				     	{
				     	temp=(pop(s1))+(pop(s1));push(s1,temp);}
				     	else if(c=='-')
				     	{
				     	temp=(pop(s1))-(pop(s1));
				     	push(s1,temp);}
				     	else if(c=='*')
				     	{
						
				     	temp=(pop(s1))*(pop(s1));push(s1,temp);}
				     	else
				     	{
						 
				     	temp=(pop(s1))+(pop(s1));
				     	push(s1,temp);}
				     	
						if(prior(s2.ch[s2.top])<prior(arr[i]))
					    push(s2,arr[i]);
					}					
				}
			}
			
		}
		else
		{
			if(flag==0)
			{
			push(s1,arr[i]-'0');
			flag++;
		   }
		else
		{             push(s1,arr[i]-'0');
						c=pop(s2);
				     	if(c=='+')
				     	{
				     	temp=(pop(s1))+(pop(s1));push(s1,temp);
						}
				     	else if(c=='-')
				     	{
				     	temp=(pop(s1))-(pop(s1));
				     	push(s1,temp);}
				     	else if(c=='*')
				     	{
						
				     	temp=(pop(s1))*(pop(s1));push(s1,temp);}
				     	else
				     	{
						 
				     	temp=(pop(s1))+(pop(s1));
				     	push(s1,temp);}
						if(prior(s2.ch[s2.top])<prior(arr[i]))
						push(s2,arr[i]);	
						flag--;	
		}
		}
	}
	res=pop(s1);
	cout<<"REsult\n"<<res;
}

