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
  stack s;
  s.size=50;
  s.top=-1;
  char a1[]={'(','{','['};
  char a2[]={')','}',']'};
  int u,flag=0;
  char arr[50];
  cout<<"Enter your expression\n";
  cin>>arr;
  int i,j;
  for(i=0;i<strlen(arr);i++)
  {
  	for(j=0;j<3;j++)
  	{
  		if(arr[i]==a1[j])
  		{
  			push(s,j);
  			break;
		}
		  if(arr[i]==a2[j])
		  {
		  	u=pop(s);
		  	if(j!=u)
		  	{
		  		flag=1;
			}
		  	break;
		  }
	  }
	  if(flag==1)
	  {
	  	cout<<"Expression is not balanced\n";
	  	break;
	  }
  }
  if(flag==0)
  {
  	cout<<"Expression is balanced\n";
  }
  return 0;
}
