
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
void insert(stack &s,int e)
{
if(s.top==-1||e>s.ele[s.top])
{
	push(s,e);
	return;
}	
	int temp=pop(s);
	insert(s,e);
	push(s,temp);
}
void sorting(stack &s)
{
if(s.top!=-1)
{
	int e=pop(s);
	sorting(s);
    insert(s,e);
}
}
int main()
{
	stack s;int c,n;
		cout<<"Enter 1 for push  else -1\n";
	cin>>c;

	while(c==1)
	{
	cout<<"Enter the element to push\n";
	cin>>n;
	push(s,n);
	cout<<"Enter 1 for push  else -1\n";
	cin>>c;
    }
    //sorting(s,s.ele[s.top]);
    sorting(s);
  while(s.top>=0)
  {
  	cout<<pop(s)<<"  ";
  }

  }

