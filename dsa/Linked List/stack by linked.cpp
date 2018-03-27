#include<iostream>
using namespace std;
typedef
struct node
{
	int data;
	struct node *next;
} *lptr;
struct stack
{
	int top;
	int size;
	lptr l;
};
void deleteend(lptr l)
{
lptr t;
t=l;
	while(t->next->next!=NULL)
	{
		t=t->next;
	}
	lptr t2;
	t2=t->next;
	cout<<t2->data<<endl;
	t->next=NULL;
	//delete(t2);
}
 void  deletebegin(lptr &l)
{
	lptr t;
	t=new struct node;
	t=l;
	cout<<t->data<<endl;
	l=l->next;
	delete t;
}
void addbegin(lptr &l1,int d)
{
	lptr t;
	t=new struct node;
	t->data=d;
	t->next=l1;
	l1=t;	
}
void push(stack &s1,int d)
{
	lptr t1;
	t1=s1.l;s1.top++;
	addbegin(s1.l,d);
}
int pop(stack &s)
{s.top--;
	if(s.top>=-1)
	deletebegin(s.l);
	else
	cout<<"Underflow\n";
}
int main()
{
	int n,d,i,j;
	stack s;
	s.top=-1;
	s.size=50;
	s.l=new node;
	while(1){
	cout<<"Enter 1 for push 2 for pop 3 for exit\n";
	cin>>n;
	if(n==1)
	{
		cout<<"Entert the number u wanna push\n";
		cin>>d;
		push(s,d);
	}
	else if (n==2)
	{
		cout<<"The poped element is\n";
		pop(s);
	}
	else
	{
		exit(1);
	}
}
    return 0;
}
