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
void display(lptr l)
{
	lptr t=l;
	while(t!=NULL)
	{
		cout<<t->data<<" ";	
		t=t->next;
	}cout<<endl;	
}
void deletebefore(lptr l,int p)
{
	lptr t,t2;
	t=l;
	while(t->next->next->data!=p)
	{
		t=t->next;
	}
	t2=t->next;
	t->next=t->next->next;
	delete t2;
}
void deleteafter(lptr l,int d)
{
	lptr t,t2;
	t=l;
	while(t->data!=d)
	{
		t=t->next;
	}
	t2=t->next;
	t->next=t->next->next;
	delete t2;
}
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
	t->next=NULL;
	delete(t2);
}
void deleteat(lptr l,lptr p)
{
	lptr t=l;
	while(t->next!=p)
	{
		t=t->next;
	}
	lptr t2=t->next;
	
	t->next=t->next->next;
//	p=t->next;
//	delete t2;
	
	
}
void remove(lptr l)
{
	lptr t1,t2,t3;
	t1=l;t2=l;
	while(t1!=NULL)
	{
		while(t2!=NULL)
		{
		//	cout<<"hi\n";
		//	cout<<"t2->data = "<<t2->data<<endl;
	    if(t1->data==t2->data&&t2!=t1)
	    {
	    //	cout<<"t2->data = "<<t2->data<<endl;
	    	//t3=t2;
	    	deleteat(l,t2);	
	    //	cout<<"after delete\n";
	    	display(l);
		}
		t2=t2->next;
     	}
	t1=t1->next;
	t2=l;
	
	//cout<<"hii\n";
	}
}
int main()
{
	lptr l1,l2,l3;
	l1=new node;
	create(l1);
	display(l1);
//	lptr t4;
//	t4=l1;
//	while(t4->next!=NULL)
//	{
//		t4=t4->next;
//	}
//	if(t4->data==l1->data)
//	deleteend(l1);
	remove(l1);
	display(l1);
	return 0;
}
