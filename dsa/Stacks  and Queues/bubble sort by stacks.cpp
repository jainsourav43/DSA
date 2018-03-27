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
	int ele[50];
};
void push(stack1 &sm,int x )
{
	if(sm.top==sm.size-1)
	{
		cout<<"Overflow of stack\n";
	}
	else
	{
		sm.top++;
		sm.ele[sm.top]=x;
	}
}
int pop(stack1 &su)
{
	if(su.top==-1)
	{
		cout<<"Underflow\n";
	}
	else
	{	
	return (su.ele[su.top--]);
	}
}
void push(stack2 &sn,int x )
{
	if(sn.top==sn.size-1)
	{
		cout<<"Overflow of stack\n";
	}
	else
	{
		sn.top++;
		sn.ele[sn.top]=x;
	}
}
int pop(stack2 &si)
{
	if(si.top==-1)
	{
		cout<<"Underflow\n";
	}
	else
	{	
	return (si.ele[si.top--]);
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
	int i,j,k,l;
	cout<<"Enter the number of elements less then 50\n";
	int n;
	cin>>n;int a[n];
	cout<<"Enter  "<<n<<" Integers \n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=n-1;i>=0;i--)
    push(s1,a[i]);
	int temp1,temp2,temp3,temp4=0,temp5;
	for(j=0;j<n;j++)
	{
	  temp1=s1.ele[s1.top];
	temp2=s1.top;
	for(i=s1.top-1;i>=0;i--)
	{
		if(s1.ele[i]>temp1)
		{
			temp2=i;
			temp1=s1.ele[i];
		}
	}
	push(s2,temp1);
	temp4++;
	for(k=s1.top;k>temp2;k--)
	{
		temp3=pop(s1);
		push(s2,temp3);
	}
	pop(s1);
	for(l=s2.top;l>=temp4;l--)
	{
		temp5=pop(s2);
		push(s1,temp5);
	}
}
   for(i=s2.top;i>=0;i--)
   cout<<pop(s2)<<"  ";
}
