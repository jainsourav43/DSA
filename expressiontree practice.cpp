#include<iostream>
#include<stack>
#define null NULL
#include<string.h>
using namespace std;
char postfix[50];
int count1=0;
struct post
{
	union u2
	{
		int a;
		char b;
	}u3;
	int tag;
};
post multifix[50];
typedef
struct expnode
{
	union u
	{
		int operand;
		char operator1;
	}u1;
	int tag;
	expnode *lchild;
	expnode *rchild;
}*expptr;
typedef struct advanced
{
	union u5
	{
		int data;
		struct expnode
		{
			char ch;
			advanced *lchild;
			advanced *rchild;
		}ex;
	}un;
	int tag;
}*advanceptr;
int priority(char ch)
{
	if(ch=='+'||ch=='-')
	return 1;
	if(ch=='*'||ch=='/')
	return 2;
	if(ch=='^')
	return 3;
}
void infixtopostfix(char str[])
{
	int len=strlen(str);
	stack<char> st;
	int i=0;
	while(i<len)
	{
	//	cout<<"copy = "<<str[i]<<endl;
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			if(st.empty())
			{
				st.push(str[i]);	
			}
			else if(priority(st.top())<priority(str[i]))
			{
			
				st.push(str[i]);
			}
			else
			{
				while((!st.empty())&&priority(st.top())>=priority(str[i]))
				{
					multifix[count1].tag=0;
					multifix[count1++].u3.b=st.top();
					st.pop();
				}
				st.push(str[i]);
			}
		}
		else
		{
			int mynum=0;
			while(str[i]>=48&&str[i]<=57)
			{
				mynum=mynum*10+(str[i]-'0');
				i++;
			}
			multifix[count1].tag=1;
			multifix[count1++].u3.a=mynum;
			i--;
		}
		i++;
	}
	
	while(!st.empty())
	{
		multifix[count1].tag=0;
		multifix[count1++].u3.b=st.top();
		st.pop();
	}
//	for(i=0;i<count1;i++)
//	{
//		if(multifix[i].tag==1)
//		{
//			cout<<multifix[i].u3.a<<"  ";
//		}
//		else
//		{
//			cout<<multifix[i].u3.b<<"  ";
//		}
//	}
	cout<<endl;
}
void infixtopost(char str[])
{
	int len=strlen(str);
	int count1=0;
	stack<char> st;
	int i=0;
	while(i<len)
	{
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			if(st.empty())
			{
				st.push(str[i]);	
			}
			else if(priority(st.top())<priority(str[i]))
			{
			
				st.push(str[i]);
			}
			else
			{
				while((!st.empty())&&priority(st.top())>=priority(str[i]))
				{
					postfix[count1++]=st.top();
					st.pop();
				}
				st.push(str[i]);
			}
		}
		else
		{
			postfix[count1++]=str[i];
		}
		i++;
	}
	while(!st.empty())
	{
		postfix[count1++]=st.top();
		st.pop();
		//	cout<<"st.top()= "<<st.top()<<endl;
	}
}
void create(expptr &t)
{
	int i=0;
	expptr t1,t2,t3;
	stack<expptr> st;
	int len=strlen(postfix);
	while(i<len)
	{
		if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='^')
		{
			t1=st.top();
			st.pop();
			t2=st.top();
			st.pop();
			t3=new expnode;
			t3->tag=1;
			t3->u1.operator1=postfix[i];
			t3->rchild=t1;
			t3->lchild=t2;
			st.push(t3);
		}
		else
		{
			t3=new expnode;
			t3->tag=0;
			t3->u1.operand=postfix[i]-'0';
			t3->rchild=null;
			t3->rchild=null;
			st.push(t3);
		}
		i++;
	}
	t=st.top();
	st.pop();
}

int calculate(advanceptr t)
{
	if(t->tag==1)
	{
		return t->un.data;
	}
	int a=calculate(t->un.ex.lchild);
	int b=calculate(t->un.ex.rchild);
	if(t->tag==0)
	{
		switch(t->un.ex.ch)
		{
			case '+':return a+b;
			case '-': return a-b;
			
			case'*':return a*b;
			case '/': return a/b;
		}
	}
}
int calculate(expptr t)
{
	if(t->tag==0)
	return t->u1.operator1;
	int a=calculate(t->lchild);
	int b=calculate(t->rchild);
	if(t->tag==1)
	{
		switch(t->u1.operator1)
		{
			case '+': return a+b;
			break;
			case '-': return a-b;
			break;
			case '*': return a*b;
			break;
			case '/': return a/b;
			break;
		}
	}	
}

void create(advanceptr &t)
{
	int i=0;
	stack<advanceptr> st;	
	advanceptr t1,t2,t3;
	while(i<count1)
	{
		if(multifix[i].tag==1)
		{
			t3=new advanced;
			t3->tag=1;
			t3->un.data=multifix[i].u3.a;
			st.push(t3);
		}
		else
		{
			t1=st.top();
			st.pop();
			t2=st.top();
			st.pop();
			t3=new advanced;
			t3->tag=0;
			t3->un.ex.ch=multifix[i].u3.b;
			t3->un.ex.lchild=t2;
			t3->un.ex.rchild=t1;
			st.push(t3);
		}
		i++;
	}
	t=st.top();
	st.pop();	
}

int main()
{
	char infix[50];
	cout<<"ENter the Infix with single digit\n";
	cin>>infix;
	infixtopostfix(infix);
	advanceptr t;
//	cout<<postfix<<endl;
	//expptr t;
	create(t);
	cout<<"Your Sweet answer = "<<calculate(t)<<endl;
	
	
}
