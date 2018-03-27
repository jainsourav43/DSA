#include<iostream>
#include<time.h>
#include<cmath>
#include <stdlib.h>  
using namespace std;
typedef
struct node
{
	int data;
	struct node *next;
} *lptr;
void display1(lptr l)
{
	lptr t=l;
	cout<<t->data<<" ";
	t=t->next;
	while(t!=l)
	{
		cout<<t->data<<" ";	
		t=t->next;
	}cout<<endl;	
}
void display(lptr l,int n)
{
	lptr t=l;int j;
	for(j=0;j<=n;j++)
	{
		cout<<t->data<<" ";	
		t=t->next;
	}
	cout<<endl;	
}
void add_end(lptr l,int d)
{
	lptr t=l;
	while(t->next!=l)
	{
		t=t->next;
	}
	t->next=new struct node;
	t=t->next;
	t->data=d;
	t->next=l;
}
 
void deleteatpos(lptr l,int p)
{
	lptr t=l;int d;
	while(t->next->data!=p)
	t=t->next;
	lptr t2=t->next;
	t->next=t->next->next;
	delete t2;
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
		t->next=l;
	}
	while(d!=-1)
	{
	    cout<<"Enter the element or -1 to exit\n";
		cin>>d;
		if(d!=-1)
		add_end(l,d);
	}
}
void deletebegin(lptr &l)
{
	lptr t;
	t=new struct node;
	t=l;
	l=l->next;
	delete t;
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
void removedice(lptr &l,int n)
 {
 	int i,j,k;
 	lptr t1=l;lptr t2;
 		int d;
 		srand(time(NULL));
 	for(j=1;j<n;j++)
 	{
	 
 	d=rand()%10+1;
 	cout<<"  RAND  "<<d<<endl;
 	for(i=1;i<=d;i++)
 	{
 		t1=t1->next;
 		l=l->next;
	} 
	 t1=t1->next;l=l->next;
	 deletebefore(l,t1->data);
	
    }
    display1(l);
}
 int main()
 {
 	lptr l;int n;
 	l=new node;
 	cout<<"Enter the no. of soilders\n";
 	cin>>n;
 	create(l);
 	cout<<"Checking whether the link is circular or not\n";
 	display(l,n);
 	removedice(l,n);
 //	display1(l);
 	return 0;
 
 }

