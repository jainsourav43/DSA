#include<iostream>
using namespace std;
typedef
struct node
{
	int data;
	struct node *next;
} *lptr;
void display(lptr l)
{
	lptr t=l;
	while(t!=NULL)
	{
	    if(t->data!=0&&t->data<1000)
		cout<<t->data<<" ";	
		t=t->next;
	}cout<<endl;	
}
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
int search(lptr l,int d)
{
	lptr t;
	t=l;
	while(t!=NULL)
	{
		if(t->data==d)
		return 0;
		t=t->next;
	}
	return 1;
}
int search1(lptr l2,int d)
{
	lptr t2;
	t2=l2;
	while(t2!=NULL)
	{
		if(t2->data==d)
		{
			return 1;
		}
		t2=t2->next;
	}
	return 0;
}
void unionlist(lptr l1,lptr l2,lptr l)
{
	lptr t1,t2,t;
	t1=l1;
	t2=l2;
	t=l;
	while(t1!=NULL)
	{
	    t->data=t1->data;
		t1=t1->next;
		t->next=NULL;
		t->next=new node;
		t=t->next;	
	}
	t->next=NULL;
	while(t2!=NULL)
	{
		if(search(l,t2->data))
		{
			t->data=t2->data;
			t->next=NULL;
			if(t2->next!=NULL)
			{
				t->next=new node;
		 		t=t->next;
			}
		}
		t->next=NULL;
		t2=t2->next;
	}
	t->next=NULL;
}
void intersect(lptr l1,lptr l2,lptr l3)
{
	lptr t1,t2,t3;
	t1=l1;
	t2=l2;
	t3=l3;
	while(t1!=NULL)
	{
		if(search1(l2,t1->data))
		{
			t3->data=t1->data;
			t3->next=new node;
			t3=t3->next;
		}
		t1=t1->next;
	}

	t3->next=NULL;
}
int main()
{	int d;
	lptr l1,l2,l,l3;
	l1=new node;
	l2=new node;
    l=new node;
    l3=new node;
	create(l1);
	create(l2);
	display(l1);
	display(l2);
	cout<<"Union of the lists is \n";
	unionlist(l1,l2,l);
	display(l);
	intersect(l1,l2,l3);
	cout<<"Intersection  of the list is \n";
	display(l3);
	return 0;
}
