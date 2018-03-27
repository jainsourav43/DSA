#include<iostream>
using namespace std;
typedef
struct node
{
	int data;
	struct node *next;
} *lptr;
struct queue
{
	lptr rear;
	lptr l;
	int size;
};
void addend(lptr &l,int d)
{
	if(l==NULL)
	{
		l=new struct node;
		l->data=d;
		l->next=NULL;
	}
	else
	{
	lptr t=l;
	t->next=new struct node;
	t=t->next;
    t->data=d;
    l=t;
	t->next=NULL;
   }
}
void deletebegin(lptr &l)
{
	if(l==NULL)
	cout<<"Queue is empty\n";
	else
	{
	lptr t;
	t=new struct node;
	t=l;
	cout<<t->data<<endl;
	l=l->next;
	delete t;
}
}
void enque(queue &q,int x)
{
	addend(q.rear,x);
}
int deque(queue &q)
{
	int t;
	deletebegin(q.l);    	
}
int main()
{
	queue q;
	q.size=50;
	q.l=new node;
	int i,j,k,n,d;
	cout<<"Enter the first node\n";
	cin>>i;
	q.l->data=i;
	q.l->next=NULL;
	q.rear=q.l;
	while(1)
	{
	cout<<"Enter 1 for enque and 2 for deque and 3 for exit\n";
	cin>>n;
	if(n==1)
	{
		cout<<"Enter the number u wanna enter \n";
		cin>>d;
		enque(q,d);
	}
	else if (n==2)
	{
		deque(q);
	}
	else 
	{
		exit(1);
	}
	
   }
   return 0;
   }
