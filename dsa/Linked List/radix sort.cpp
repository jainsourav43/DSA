#include<iostream>
using namespace std;
int maxe,h=0;int c=0,k=0;
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
		cout<<t->data<<" ";	
		if(maxe<t->data)
		  maxe=t->data;
		t=t->next;
	}
	cout<<endl;	
}
void addbegin(lptr &l1,int d)
{
	lptr t;
	t=new struct node;
	t->data=d;
	t->next=NULL;
	l1=t;	
}
int number(int max)
{
	while(max!=0)
	{
		max=max/10;
		k++;
	}
}
void addend(lptr l,int d)
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
	//cin>>d;
	d=10000;
	if(d!=-1)
	{
		t->data=d;
		t->next=NULL;
	}
	d=9999;
	while(1)
	{
	   //cout<<"Enter the element or -1 to exit\n";
		//cin>>d;
		d--;
		if(d==0)
		break;
		addend(l,d);
	}
}
int funcn(int nd,int n)
{
	int j,k1,l;
	for(j=1;j<nd;j++)
	{
		n=n/10;		
	}
	k1=n%10;
	return k1;
}
void radix(lptr &l,int h)
{
  c++;lptr t1;int j=0;
  int n=10;int i;
  static int m=maxe,hi=k;lptr l2;
   t1=l;
  static int mi=k;
   lptr a[10],t[10];
for(i=0;i<10;i++)
{
	a[i]=NULL;
	t[i]=NULL;
}
while(t1!=NULL)
{
if(t[funcn(h,t1->data)]==NULL)
{
a[funcn(h,t1->data)]=new node;
a[funcn(h,t1->data)]->data=t1->data;
a[funcn(h,t1->data)]->next=NULL;
t[funcn(h,t1->data)]=a[funcn(h,t1->data)];
}
else
{	
t[funcn(h,t1->data)]->next=new node;
t[funcn(h,t1->data)]=t[funcn(h,t1->data)]->next;
t[funcn(h,t1->data)]->data=t1->data;
t[funcn(h,t1->data)]->next=NULL;
}
t1=t1->next;
}
for(int g=0;g<=9;g++)
t[g]=a[g];
for(i=0;i<=9;i++)
{  
	while(t[i]!=NULL)
	{
	j++;
	if(j==1)
	{   
	    l2=new node;
		addbegin(l2,t[i]->data);
	}
	else
	addend(l2,t[i]->data);
	t[i]=t[i]->next;
    }
}
hi--;
h++;
if(hi>=0)
radix(l2,h);
else
display(l2);
}
int main()
{
	lptr l;
	l=new node;
	create(l);
	display(l);
	number( maxe);
	radix(l,h);	
}
