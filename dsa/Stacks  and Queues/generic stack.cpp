#include<iostream>
#include<string.h>
using  namespace std;
union u1
{
	int a;
	char b;
	float c;
	char d[10]; 
};
struct s1
{
	int tag;
	u1 u;
};
struct stack
{
	int size;
	int top;
	s1 st[50];
};
void push(stack &si,s1 x )
{
	if(si.top==si.size-1)
	{
		cout<<"Overflow of stack\n";
	}
	else
	{
		si.top++;
		si.st[si.top]=x;
	}
}
s1 pop(stack &s1)
{
	if(s1.top==-1)
	{
		cout<<"Underflow\n";
	}
	else
	{	
	return (s1.st[s1.top--]);
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
   s1 str;
   s.top=-1;
   s.size=50;
   s1 e;
   int i,j,k,l;
   char ch;
   float f;
   string str1;
   	cout<<"Enter the no. of elements u wanna to store in stack\n";
   	int n;
   	cin>>n;
   	for(j=0;j<n;j++)
   	{
   		cout<<"Enter 1 for int  2 for char 3 for float 4 for string\n";
   		cin>>str.tag;
   		if(str.tag==1)
   		{
   			cin>>str.u.a;
   			push(s,str);
		}
		else if(str.tag==2)
		{
			cin>>str.u.b;
   			push(s,str);
		}
		else if(str.tag==3)
		{
			cin>>str.u.c;
   			push(s,str);
		}
		else if(str.tag==4)
		{
			cin>>str.u.d;
   			push(s,str);
		}
	}cout<<"THE POPED CONTENT OF THE STACK ARE\n";
	for(k=s.top;k>=0;k--)
	{e=pop(s);
	if(e.tag==1)
	{
	    cout<<e.u.a<<" "<<endl;
	}
	if(e.tag==2)
	{
		cout<<e.u.b<<" "<<endl;
	}if(e.tag==3)
	{
		cout<<e.u.c<<" "<<endl;
	}if(e.tag==4)
	{
		cout<<e.u.d<<" "<<endl;
	}
		
	}
	return 0;
}

