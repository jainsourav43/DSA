#include<iostream>
#define null NULL
int no_of_digits=0,MAX=0;
using namespace std;
typedef struct node
{
int data;
node *next;	
} *lptr ;

typedef struct rnode
{
	lptr bkptr;
	rnode * right;
} *rptr ;

void swappair(lptr &l)
{
	lptr temp=l->next,t=l,prev=null;
	l=temp;
	while(t&&t->next!=null)
	{
		cout<<"t->data= "<<t->data<<"\n";
		temp=t->next;
		t->next=t->next->next;
		if(t->next) cout<<"t->next= "<<t->next->data<<"\n";
		temp->next=t;
		if(prev)
		prev->next=temp;
		
		prev=t;
		
		t=t->next;
	//	if(t)
	//	t=t->next;
	}
	
}
void addbegin(lptr &l,int n)
{
	lptr t;
	t=new node;
	t->data=n;
	t->next=l;
	l=t;
}

void addend(lptr l,int n)
{
	lptr t=l;
	while(t->next!=null)
	{
		t=t->next;
	}
	t->next=new node;
	t=t->next;
	t->data=n;
	t->next=null;
}

void findmaxanddigit(lptr l)
{
	lptr t=l;
	int max=0;
	while(t!=null)
	{
		if(t->data>max)
		{
			max=t->data;
		}
		t=t->next;
	}
	MAX=max;
	while(max)
	{
		no_of_digits++;
		max/=10;
	}
	
}

int findDigit(int n,int k)
{
	int i=0;
	for(i=1;i<k;i++)
	{
		n=n/10;
	}
	return n%10;
	
}
void display(lptr l)
{
	lptr t=l;
	while(t)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
	cout<<endl;
}
lptr radix(lptr &l,rptr r,int h)
{
 	rptr tr1=r,tr2=r;
 	for(int i=0;i<10;i++)
 	{
	 tr1->bkptr=null;
	 tr1=tr1->right;
 	}
 tr1=r;
 lptr t1=l,t2=l;int i,j;
 while(t1!=null)
 {	
 	int dig=findDigit(t1->data,h);
 	
	for(i=0;i<dig;i++)
	{
		tr1=tr1->right;
	}
	
	if(tr1->bkptr==null)
	{
		addbegin(tr1->bkptr,t1->data);
	}
	else
	{
		addend(tr1->bkptr,t1->data);
	}
	t1=t1->next;
	tr1=r;	
 }
 
 tr1=r;
 lptr l2=null;int flag=0;
for(i=0;i<=9;i++)
{
	t2=tr1->bkptr;
	if(t2!=null&&flag==0)
	{
		flag=1;
		addbegin(l2,t2->data);
	    t2=t2->next;	  
	}
	while(t2!=null)
	{
		addend(l2,t2->data);
		t2=t2->next;
	}
	tr1=tr1->right;
}
if(h+1<=no_of_digits)
{
cout<<"LIST AFTER EACH PASS\n";
display(l2);
radix(l2,r,h+1);
}
else
{
display(l2);
return l2;
}
}



int main()
{
	lptr l=null;
//	l=new node;
	int n;
	cout<<"Entert the first data to enter\n";
	cin>>n;
	addbegin(l,n);
	while(n!=-1)
	{
		cout<<"Enter the  data to enter\n";
		cin>>n;
		if(n!=-1)
		{
			addend(l,n);
		}
	}
	display(l);
	
	rptr r;
	r=new rnode;
	r->bkptr=null;
	r->right=null;
	rptr tr1=r;
	for(int i=0;i<9;i++)
	{
		tr1->right=new rnode;
		tr1=tr1->right;
		tr1->right=null;
		tr1->bkptr=null;
	}
	findmaxanddigit(l);
	cout<<no_of_digits<<endl;
	cout<<"RAdix start\n";
	l=radix(l,r,1);
	cout<<"Dispaying main list After Sorting\n";
	display(l);
	swappair(l);
	display(l);
}
