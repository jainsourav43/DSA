#include<iostream>
#define null NULL
using namespace std;
int c=0;
typedef
struct btnode
{
	btnode *lchild;
	char data ;
	btnode *rchild;
} *btptr;
struct stack
{
	int size;
	int top;
	btptr ele[50];
};
btptr converttreetoList(btptr t)
{
	if(t==null)
	return t;
	if(t->lchild)
	{
		btptr temp=converttreetoList(t->lchild);
		for(; temp->rchild!=null;temp=temp->rchild);
		temp->rchild=t;
		t->lchild=temp;
		
		
	}
	else if(t->rchild)
	{
		btptr temp=converttreetoList(t->rchild);
		for(; t->lchild!=null;t=t->lchild)
		temp->lchild=t;
		t->rchild=temp;
	}
}
void push(stack &s1,btptr x )
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
btptr pop(stack &s1)
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
bool empty(stack s)
{
	if(s.top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void create(btptr &t)
{
	btptr t1,t2;
	char ch;
	cout<<"Enter the character to input or '.' to return \n";
	cin>>ch;
	if(ch=='.')
	return;
	else if(t==null)
	{
	    c++;
		t=new btnode;
		t->data=ch;
		t->lchild=null;
		t->rchild=null;
	}
    cout<<"AGAIN ENTER THE LEFT NODE\n";
	create(t->lchild);
	cout<<" Your current  position is  "<<t->data<<endl;
	cout<<"ENTER THE RIGHT NODE AT YOUR CURRENT POSITION\n";
	create(t->rchild);
	cout<<"Your current   position is  "<<t->data<<endl;
}
int main()
{
	btptr t=null;
	create(t);int k=0;
	bool v[50];
	for(int i=0;i<c;i++){
		v[i]=false;
	}
	btptr t2,t3,t4;
	stack s1,s2;
	s1.top=-1;
	s1.size=50;
	s2.top=-1;
	s2.size=50;int c=0;
	t4=t;
	if(t!=null)
	{
		push(s1,t);
	}
	while(!empty(s1))
	{
		t2=pop(s1);
		if(t2->lchild==null&&t2->rchild==null)
		{   if(t2!=null)
			cout<<t2->data<<" ";
			if(!empty(s1))
			{
				t3=pop(s1);
				while(t3->rchild==t2||t3->lchild==t2)
				{
				    if(t3!=null)
					cout<<t3->data<<" ";
					if(t3==t4)
					{
						exit(1);
					}
					t2=t3;
					t3=pop(s1);
				}
				push(s1,t3);
			}
		}
		else
		{
			push(s1,t2);
			if(t2->rchild!=null)
			push(s1,t2->rchild);
			if(t2->lchild!=null)
			push(s1,t2->lchild);
			
		}
	}
return 0;
}
