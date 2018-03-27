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
	int rear;
	int front;
	lptr l;
	int size;
};
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
void deletebegin(lptr &l)
{
	lptr t;
	t=new struct node;
	t=l;
	cout<<t->data<<endl;
	l=l->next;
	delete t;
}
void enque(queue &q,int x)
{
	if((q.rear+1)%q.size==q.front)
	{
		cout<<"Queue is overloaded\n";
	}
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%q.size;
		addend(q.l,x);
	}
}
int deque(queue &q)
{
	int t;
	
	if(q.front==-1)
	{
		cout<<"Queue is Empty\n";
	}
	else
	{
		t=q.front;
		if(q.front==q.rear)
		{
			deletebegin(q.l);
			q.front=-1;
			q.rear=-1;
		}
		else
		{
			deletebegin(q.l);
			q.front=(q.front+1)%q.size;
		}
    }    	
}
int main()
{
	queue q;
	q.front=-1;
	q.rear=-1;
	q.size=50;
	q.l=new node;
	int i,j,k,n,d;
	cout<<"Enter the first node\n";
	cin>>i;
	q.l->data=i;
	q.l->next=NULL;
	q.front=0;
	q.rear=0;
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
