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

int  empty(stack s)
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
	btptr t2,t3;
	stack s1,s2;
	s1.top=-1;
	s1.size=50;
	s2.top=-1;
	s2.size=50;int c=0;
	if(t!=null)
	{
		push(s1,t);
	}
	t=t->lchild;
	t2=t;
	while(!empty(s1))
	{
		cout<<"While 1\n";t=t2;
		while(t!=null&&k==0)
		{
		   cout<<"While 2\n";
			push(s1,t);
			t=t->lchild;
		}
		if(k==1)
		push(s1,t2);
		t2=pop(s1);
		if(t2->rchild!=null)
		{cout<<"IF\n";
			push(s2,t2);
			t2=t2->rchild;k=0;
			continue;
		}
		else
		{
			cout<<t2->data<<"  ";cout<<"ELSE !\n";
		}
		if(empty(s2)==0)
		{
		    cout<<"empty\n";
			t2=pop(s2);
			cout<<t2->data<<"   ";
        	t2=pop(s1);			
			k=1;//cout<<"KKK%\n";t3=s1.ele[s1.top];//cout<<"T3  "<<t3->data<<"  ";
		
        	if(t->rchild!=null)
        	{
        		push(s2,t2);
        		t2=t2->rchild;
        		k=0;
			}
				//cout<<t2->data<<"   ";
		}
		else
		{cout<<"ELSE\n";
			t2=pop(s1);

		}
		
		}
	
return 0;
}
