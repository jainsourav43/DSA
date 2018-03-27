#include<iostream>
using namespace std;
typedef
struct node
{
	int data;
	struct node *next;
} *lptr;
void add_end(lptr l,int d)
{
	lptr t=l;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=new struct node;
	t=t->next;
	t->data=d;
	t->next=NULL;
}
void display(lptr l)
{
	lptr t=l;
	while(t!=NULL)
	{
		cout<<t->data<<" ";	
		t=t->next;
	}cout<<endl;	
}
void create(lptr l)
{
	int d;lptr t;
	t=l;
	cout<<"Enter the first element or -1 to exit\n";
	cin>>d;
	if(d!=-1)
	{
		t->data=d;
		t->next=NULL;
}
	while(d!=-1)
	{
	    cout<<"Enter the element or -1 to exit\n";
		cin>>d;
		if(d!=-1)
		add_end(l,d);
	}
}
void adde(lptr l1,lptr l2,int n1)
{
	lptr t1,t2,t3;
	t1=l1;
	t2=l2;
	while(t1->next->data!=n1)
	{
		t1=t1->next;
	}
	while(t2->next!=NULL)
	{
		t2=t2->next;
	}
	t2->next=t1->next;
}
void split(lptr &l1,lptr &l2)
{
	lptr t1,t2;
	t1=l1;
	t2=l2;
	int flag=0;
	while(t1->next!=NULL)
	{
	while(t2->next!=NULL)
	{
	    if(t2->next->data==t1->data)
	    {
		  flag=1;  

	      break;
	    }
		t2=t2->next;
	}
	if(flag==1)
	break;	
	t1=t1->next;
   }
   
    t2->next=NULL;
    cout<<t2->data<<endl;
    
}
int main()
{
	lptr l1,l2,l3;
	l1=new node;int n;
	l2=new node;
	l3=new node;
	create(l1);
	create(l2);
	cout<<"Enter the element after u wanna to connect l2 list\n";
	cin>>n;
	adde(l1,l2,n);
	display(l1);
	display(l2);
	split(l1,l2);
	display(l1);
	display(l2);
	
}
