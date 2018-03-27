#include<iostream>
using namespace std;
int s=0;
typedef
struct node
{
	int data;
	node *next;
}*lptr;
void addend(lptr l,int d)
{
	lptr t,t1=l;int n,c;
	t=l;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	cout<<"Enter 1 for loop else -1\n";
	cin>>c;
	if(c==1)
	{
		cout<<"Enter the data which u want to loop\n";
		cin>>n;
		t->next=new node;
		t=t->next;
		t->data=d;
		while(t1->data!=n)
		{
			t1=t1->next;
		}
		t->next=t1;
    }
    else
    {
	t->next=new node;
	t=t->next;
	t->data=d;
	t->next=NULL;
   }
}
int  detectloop(lptr l)
{
	lptr t1=l,t2=l;
	lptr t3=l;
	int k;
	cout<<"CALLING  2\n";
	while(t1!=NULL)
	{cout<<"CALLING  3\n";
		t2=l;
		while(t2->next!=t1)
		{
			if(t2->data!=t1->data)
			{
				
				t2=t2->next;
				continue;
			}
			else if(t2->data==t1->data)
			{
				k=1;	return k;
			//	t3->next=NULL;
			
			}
		}
		//t3=t1;
		t1=t1->next;
	}
	return 0;
	
}

void addbegin(lptr &l,int d)
{
	lptr t;
	t=new node;
	t->data=d;
	t->next=l;
	l=t;
}
void create(lptr &l)
{
	lptr t=l;
	int d;
	if(l==NULL)
	{s++;
		cout<<"Enter the data to enter \n";
		cin>>d;
		addbegin(l,d);
	}
	t=l;
	while(d!=-1)
	{s++;
		cout<<"Enter the data to enter or -1 to exist\n";
		cin>>d;
		if(d!=-1)
		{
			addend(t,d);
		}
	}
}
void display(lptr l)
{cout<<"CALLING\n";
	lptr t;
	t=l;
	for(int i=0;i<s;i++)
	{
		cout<<t->data<<"  ";
		t=t->next;
	}
}
void display1(lptr l)
{
	lptr t;
	t=l;
	while(t!=NULL)
	{
		cout<<t->data<<"  ";
		t=t->next;
	}
}
int main()
{
	lptr l=NULL;
	create(l);
	display(l);
	int i=0;
	 i=detectloop(l);
	if(i)
	{
		cout<<"LOOP found \n";
	}
	else
	{
		cout<<"LOOP not found\n";
	}
	//display1(l);
}
