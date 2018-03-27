#include<iostream>
using namespace std;
typedef
struct node
{
	int coef;
	int exp;
	struct node *next;
} *lptr;
void add_end(lptr l,int c,int e)
{
	lptr t=l;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=new struct node;
	t=t->next;
	t->coef=c;
	t->exp=e;
	t->next=NULL;
}
void create(lptr l)
{
	int d,e,c;lptr t;
	t=l;
	cout<<"Enter the coef of first element\n";
	cin>>c;
	cout<<"Enter the  exp of first element or -1 to exit\n";
	cin>>e;
	if(c!=-1)
	{
		t->coef=c;
		t->exp=e;
		t->next=NULL;
	}
	while(c!=-1)
	{
	   cout<<"Enter the coef element or -1 to exit\n";
		cin>>c;
		cout<<"Enter the exp \n";
		cin>>e;
		if(c!=-1)
		add_end(l,c,e);
	}
}
void display(lptr l)
{
	lptr t=l;
	while(t!=NULL&&t->coef<100000)
	{
		cout<<t->coef<<"X^"<<t->exp;
		if(t->next!=NULL)
		cout<<"+";	
		t=t->next;
	}cout<<endl;	
}
void merge(lptr l1,lptr l2,lptr l)
{
	lptr t1,t2,t;
	t1=l1;
	t2=l2;
	t=l;
	t->exp=-1;
	t->coef=-1;		
	if(t1==NULL)
	cout<<"NULL\n";
	while(t1!=NULL&&t2!=NULL)
	{
	if(t1->exp>t2->exp)
	{	

		t->exp=t1->exp;
		t->coef=t1->coef;
		t1=t1->next;			
t->next=NULL;
if(t1||t2)
	{
		t->next=new node;
		t=t->next;
		}
	}
	else if (t1->exp<t2->exp)
	{
		t->exp=t2->exp;
		t->coef=t2->coef;
		t->next=NULL;
if(t1||t2)
		{
		t->next=new node;
		t=t->next;
		}
		t2=t2->next;
	
	}
	else
	{	

	t->exp=t1->exp;
	

	t->coef=t1->coef+t2->coef;
	

	t1=t1->next;
		

	t2=t2->next;
		
t->next=NULL;
if(t1||t2)
	{
	t->next=new node;
	t=t->next;
	
}

	}
  }
  while(t1!=NULL)
  {
  	t->exp=t1->exp;
  	t->coef=t1->coef;
  	t->next=NULL;
if(t1||t2)
  	{
   t->next=new node;
  	t=t->next;
  }
  	t1=t1->next;
  
  }
  while(t2!=NULL)
  {
  	t->exp=t2->exp;
  	t->coef=t2->coef;
  	t->next=NULL;
if(t1||t2)
  {
	  	t->next=new node;
  	t=t->next;}
  	t2=t2->next;
  }
t->next=NULL;
}
 
int main()
{
	lptr l1,l2,l;
	l1=new struct node;
	l2=new struct node;
	create(l1);
	create(l2);
	l=new struct node;
	display(l1);
	display(l2);
	merge(l1,l2,l);
	display(l);
	
}
