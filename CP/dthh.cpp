#include<iostream>
using namespace std;
int c=0;
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
void addbegin(lptr &l1,int d)
{
	lptr t;
	t=new struct node;
	t->data=d;
	t->next=l1;
	l1=t;	
}
void addbefore(lptr l,int d,int b)
{
	lptr t,t2;
	t=l;int n;
	while(t->next->data!=d)
	{
		t=t->next;
	}
	t2=t->next;
	t->next=new struct node;
	t=t->next;
	t->data=b;
	t->next=t2;
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
void deleteatpos(lptr l,lptr p)
{
lptr t1;
t1=l;
while(t1->next!=p)
{
	t1=t1->next;
}
if(t1->next->next!=NULL)
t1->next=t1->next->next;
else
{
	t1->next=NULL;
}

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
void insertion(lptr &l,lptr &l1)
{
cout<<"ENTER \n";
 lptr t1,t2,t3;
 t1=l;
t2=l1;
int flag=0;c++;
	t3=t1;
	while(t2!=t1)
	{flag++;cout<<"**  "<<endl;display(l1);
		if(t2->data>t1->data)
		{cout<<"##  "<<endl;
		if(flag==1)
		addbegin(l1,t1->data);
		else
			addbefore(l1,t2->data,t1->data);
			deleteatpos(l1,t3);cout<<"&&  "<<endl;
			break;
		}
		t2=t2->next;
	}
	  if(t1!=NULL&&c<4)
	 insertion( t1->next,l1);
}
int main()
{
	lptr l;
	l=new node;
	 lptr l1=l;
	create(l);lptr l3=l->next;
	display(l);
	insertion(l3,l1);
	display(l1);
//	display(l1);

	return 0;
}

