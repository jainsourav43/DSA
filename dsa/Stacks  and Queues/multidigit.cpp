#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
struct stack
{
int size;
int top;
char ele[50];	
};
union u1
{
	int a;
	char b;
};
struct s1
{
	int tag;
	u1 u;
};
struct stack1
{
int size;
int top;
int ele[50];	
};
void push(stack1 &s1,int x )
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
	char str[50];
	stack s;
	stack1 stk2;
	struct  s1 p[50];int y1,y2;
	int i,j1=0,res,a1,j,temp;
	s.top=-1;
	s.size=50;
	cout<<"Enter the expression\n";
	cin>>str;
	for(i=0;i<strlen(str);i++)
   {
   	if(str[i]>=48&&str[i]<=57)
   	{a1=0;
    while(str[i]>=48&&str[i]<=57)
    {
    	a1=a1*10+(str[i]-'0');
    	i++;
	}
	i--;
//cout<<"\nI after while \n  "<<i;
	p[j1].u.a=a1;
	p[j1].tag=1;
	j1++;
    }
    else
    	if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^')
		{
			if(s.top==-1)
			push(s,str[i]);
			else
			{
				for(j=s.top;j>=0;j--)
				{
					if(prior(s.ele[s.top])<prior(str[i]))
					{
						push(s,str[i]);
						break;
					}
					else
					{
						//cout<<pop(s);cou
					//	cout<<"POP\n";
						p[j1].u.b=pop(s);
						p[j1].tag=0;j1++;
						if(prior(s.ele[s.top])<prior(str[i]))
						{
						push(s,str[i]);break;
					   }
						//break;
					}
					
				}
			}
		}
		//cout<<"\nI BEFORE FOR \n "<<i;
   }
  // cout<<"J 1  "<<j1<<endl;
  for(int j2=s.top;j2>=0;j2--)
	{
		//cout<<pop(s);
			p[j1].u.b=pop(s);
			p[j1].tag=0;j1++;
		
	}
   for(int k=0;k<j1;k++)
   {
   	if(p[k].tag==0)
   	{
   		cout<<p[k].u.b<<" ";
 	  }
 	  else
 	 {
     	cout<<p[k].u.a<<" ";
	  }
   }
   cout<<"hhii\n";
   for(int k=0;k<j1;k++) 
   {
   	if(p[k].tag==1)
   	{//cout<<"p[k].u.a   "<<p[k].u.a;
   		push(stk2,p[k].u.a);
	}
	else
	{
	
		y1=pop(stk2);//cout<<"Y1   "<<y1;
		y2=pop(stk2);//cout<<"Y2   "<<y2;
			if(p[k].u.b=='+')
			{
				temp=y2+y1;
			}
			else
			 if(p[k].u.b=='-')
			{
				temp=y2-y1;
			}
			else if(p[k].u.b=='*')
			{
				temp=y1*y2;
			}
			else if(p[k].u.b=='^')
			{
				//temp=y2^y1;
				temp=pow(y2,y1);
			}
			else if(p[k].u.b=='/')
			{
				temp=y2/y1;
			}
			else if(p[k].u.b='%')
			{
				temp=y2%y1;
			}
			push(stk2,temp);
	}

   }
res=pop(stk2);
cout<<"\nResult \n"<<res;
   return 0;
}
