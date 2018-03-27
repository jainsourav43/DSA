#include<iostream>
#include<string.h>
#define null NULL
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

 typedef
struct st2
{
  int tag1;
  union u2
  {
  int data;
 
  struct etnode
  {
	char data1;
    st2 *lchild;
	st2 *rchild; 
} etp;
} un;
} *etptr;
struct stack2
{
	int size;
	int top;
	etptr e[50];
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
void push(stack2 &s1,etptr x)
{
	if(s1.top==s1.size-1)
	{
		cout<<"Overflow of stack\n";
	}
	else
	{
		s1.top++;
		s1.e[s1.top]=x;
	}
}
etptr pop(stack2 &s1)
{
	if(s1.top==-1)
	{
		cout<<"Underflow\n";
	}
	else
	{	
	return (s1.e[s1.top--]);
	}
}
int prior(char ch)
{
	if(ch=='/')
	return 3;
	else if(ch=='*')
	return 2;
	else if(ch=='+'||ch=='-')
	return 1;
	else if(ch=='^')
	return 4;
}
int evaluate(etptr t)
{   
    // cout<<"CALLING\n";
	int a,b;
	if(t->tag1==1)
	{ // cout<<"t->un.data  "<<t->un.data;
		return (t->un.data);
	}
	else
	{//cout<<"ELSE\n";
	a=evaluate(t->un.etp.lchild);//cout<<"a  "<<a;
	b=evaluate(t->un.etp.rchild);//	cout<<"b  "<<b;
	}
	switch(t->un.etp.data1)
	{
		case '+':
			{
				return a+b;
				break;
			}
			case '-':
				{
					return a-b;
					break;
				}
				case '*':
					{
						return a*b;
						break;
					}
					case '/':
						{
							return a/b;
							break;
						}
						case '^':
							{
								return pow(a,b);
								break;
							}
			
	}
}
int main()
{
	etptr et,t1,t2,t3;
	char str[50];
	stack s;
	stack2 stk;
	stk.size=50;
	stk.top-1;int k;
	struct  s1 p[50];
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
    	a1=a1*10+(str[i]-48);
    	i++;
	}
	i--;
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
						p[j1].u.b=pop(s);
						p[j1].tag=0;j1++;
						if(prior(s.ele[s.top])<prior(str[i]))
						push(s,str[i]);
					}
					
				}
			}
		}
   }
  for(int j2=s.top;j2>=0;j2--)
	{
			p[j1].u.b=pop(s);
			p[j1].tag=0;j1++;		
	}
	for(k=0;k<j1;k++)
	{
		if(p[k].tag==1)
		{
			et=new st2;
			et->un.data=p[k].u.a;
			et->tag1=1;
		//	cout<<"et->un.data  \n"<<et->un.data;
			//et->lchild=null;
			//et->rchild=null;
			push(stk,et);
		}
		else
		{
			t1=pop(stk);
			t2=pop(stk);
			et=new st2;
			et->tag1=0;
			et->un.etp.data1=p[k].u.b;//cout<<"et->un.etp.data1  "<<et->un.etp.data1;
			et->un.etp.lchild=t2;
			et->un.etp.rchild=t1;
			push(stk,et);
		}
	}
int ans=evaluate(et);
cout<<"Answer \n"<<ans;
	return 0;
}
