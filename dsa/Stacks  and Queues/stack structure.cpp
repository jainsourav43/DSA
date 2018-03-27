#include<iostream>
using namespace std;
struct s1
{
	int a;
	char b;
	float c;
};
struct stack
{
	int size;
	int top;
	s1 st[50];
};
void push(stack &s1,int x,char y ,float z)
{
	if(s1.top==s1.size-1)
	{
		cout<<"Overflow of stack\n";
	}
	else
	{
		s1.top++;
		s1.st[s1.top].a=x;
		s1.st[s1.top].b=y;
		s1.st[s1.top].c=z;
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
int main()
{
	stack s;s1 e;
	s.size=50;
	s.top=-1;
	int i,j,k,l,a1,n
	;char b1;float c1;
	cout<<"Enter the no of structure u wanna to maintain\n";
	cin>>n;
	for(i=0;i<n;i++)
	{ 
	    cin>>a1>>b1>>c1;
		push(s,a1,b1,c1);
	}
	for(j=0;j<n;j++)
	{
		e=pop(s);
		cout<<e.a<<"  ";
		cout<<e.b<<"  ";
		cout<<e.c<<"  ";
		cout<<endl;
	}
	return 0;
}
