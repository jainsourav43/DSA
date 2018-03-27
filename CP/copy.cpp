#include<iostream>
#define null NULL
using namespace std;
typedef
struct  btnode
{
	int data;
	btnode *lchild;
	btnode *rchild;
}*btptr;
struct stack
{
	btptr ele[50];
	int top;
	int size;
};
btptr pop(stack &s)
{
	if(s.top==-1)
	{
		cout<<"Under flow\n";
	}
	else
	{
		return s.ele[s.top--];
	}
}
void push(stack &s,btptr t)
{
	if(s.top==s.size-1)
	{
		cout<<"Underflow\n";
	}
		else
		{
			s.top=s.top+1;
			s.ele[s.top]=t;
	}
}
void create(btptr &t)
{
	if(t==null)
	{
		int d;
		cout<<"Enter the data to enter or -1 to return \n";
		cin>>d;
		if(d!=-1)
		{
		t=new btnode;
		t->data=d;
		t->lchild=null;
		t->rchild=null;
	   }
	   else
	   return ;
	}
	cout<<"Your current position is "<<t->data<<"\n ";
	create(t->lchild);
		cout<<"Your current position is "<<t->data<<"\n";

	create(t->rchild);
}
void ldr(btptr t)
{
	if(t!=null)
	{
	ldr(t->lchild);
	cout<<t->data<<"   ";
	ldr(t->rchild);
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
void postit(btptr t)
{
	btptr t1,t2,t3,t4;
	t1=t;t2=t;
	stack s;
	s.top=-1;
	s.size=50;
	push(s,t);
	while(!empty(s))
	{//cout<<"ppp  ";
		t3=pop(s);
		if(t3->lchild==null&&t3->rchild==null)
		{
			if(t3!=null)
		   	cout<<t3->data<<"  ";
			if(!empty(s))
			{
			    t4=pop(s);
			    
			while(t4->rchild==t3||t4->lchild==t3)
			{
				if(t4!=null)
				cout<<t4->data<<" ";
				if(t4==t2)
				{  
					//cout<<t3->data<<" ";
					exit(1);
				}
				t3=t4;
				t4=pop(s);
			}
				push(s,t4);
		}
		}
		else
		{
			push(s,t3);
          
		  if(t3->rchild!=null)
		  {
		  	push(s,t3->rchild);
		  }
		  if(t3->lchild!=null)
          {
          	push(s,t3->lchild);
          	
		  }
		}
		
	}
}
int main()
{
btptr t=null;
int i,j,k;
create(t);
ldr(t);	cout<<endl;
postit(t);
}
