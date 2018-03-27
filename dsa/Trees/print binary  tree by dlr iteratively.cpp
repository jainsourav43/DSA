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
	create(t);int k;
	bool v[50];
	for(int i=0;i<c;i++){
		v[i]=false;
	}
	btptr t2;
	stack s;
	s.top=-1;
	s.size=50;
	t2=t;
	push(s,null);
	while(!empty(s))
	{
	 t=t2;
	while(t!=null)
	{//k=0;
	   cout<<t->data<<"  ";
		if(t->rchild!=null)
		{
		push(s,t->rchild);k=1;
	    }	
		t=t->lchild;
	}
	t2=pop(s);
   }
}
