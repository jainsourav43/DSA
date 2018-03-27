#include<iostream>
#define null NULL
using namespace std;
struct node;
struct tnode
{
node* p;
tnode *next;
};
typedef
struct node
{
	int id;
	node *next;
	tnode *trail;
	int count;
}  *toptr;
struct queue
{
	int size;
	toptr element[50];
	int front;
	int rear;
};
void display(toptr t)
{
	cout<<"Call\n";
	toptr t2=t;
	while(t2!=null)
	{
		cout<<"  t2->id=  "<<t2->id<<"  \n";
		cout<<" t2-<count  =  "<<t2->count<<"\n";
		while(t2->trail!=null)
		{
			cout<<"t2->trail->p2->data== "<<t2->trail->p->id<<" \n ";
			t2->trail=t2->trail->next;
		}
		t2=t2->next;
	}
}
void enque(queue &q,toptr x)
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
		q.element[q.rear]=x;
	}
}
toptr search(toptr t,int c)
{
	toptr t1=t;
	while(t1!=null)
	{
		if(t1->id==c)
		{
			return t1;
		}
		t1=t1->next;
	}
}
toptr deque(queue &q)
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
			q.front=-1;
			q.rear=-1;
		}
		else
		{
			q.front=(q.front+1)%q.size;
		}
		return q.element[t];
    }    	
}
void addend(toptr t,int a)
{
	int b;toptr t2,t4;
	while(t->next!=null)
	{
		t=t->next;
	}
	t->next=new node;
	t=t->next;
	t->id=a;
	cout<<"Enter the no count\n";
	cin>>b;
  	t->count=b;
	t->next=null;
 	t->trail=null;
 	 
}

/*void addend1(tnode* l,toptr t2)
{
	while(l->next->next!=null)
	{
		l=l->next;
	}
	l->next=new tnode;
	l=l->next;
	l->p=t2;
	l->next=null;
}*/
void create(toptr t3)
{
	  int a=1,b;toptr t2,t4,t5,t;
	  t=t3;
	  while(a!=-1)
	  {
	  	cout<<"Enter the  data to be entered\n";
	  	cin>>a;
	  	if(a!=-1)
	  	{
	  		addend(t3,a);
		}
	   
		 //t=t->next;
	}
}
void print(toptr t)
{cout<<"Calling\n";
	queue q;
	q.front=-1;
	q.rear=-1;
	q.size=50;
 toptr t2,t3=t;
 t2=t;toptr p;
while(t2!=null)
{ 
	if(t2->count==0)
	{
      	enque(q,t2);
      	t2->count=-1;
      }
		 t2=t2->next;	  
}
while(q.front!=-1)
{cout<<"Calling   2\n";
	t2=deque(q);
	cout<<t2->id<<"  ";
	 while(t2->trail!=null)
     {cout<<"KKKK\n";
		 	if(t2->trail->p->count>0)
		 	{
		 		t2->trail->p->count=t2->trail->p->count-1;
			 }
	   }
	   t3=t;
	   while(t3!=null)
	   {cout<<"YYY\n";
	   	if(t3->count==0)
	   	{
	   		enque(q,t3);
	   		t3->count=-1;
	   		
		   }
		   	t3=t3->next;
		}
		
	}
	
}
void addbegin1(toptr &t,toptr t2)
{toptr t5=t;
		t5->trail=new tnode;
	  	t5->trail->p=t2;//cout<<"t5->trail->p->id  =  "<<t5->trail->p->id<<"\n";
	  	t5->trail->next=null;
}
void addend1(toptr t,toptr t2)
{
	toptr t4=t;
	while(t4->trail->next!=null)
	  	 	{
	  	 		t4->trail=t4->trail->next;
			}
			   t4->trail->next=new tnode;
			   t4->trail=t4->trail->next;
			   t4->trail->p=t2;//cout<<"t5->trail->p->id = "<<t5->trail->p->id<<" \n ";
			   t4->trail->next=null;
}
int main()
{
	toptr t=null;
	int a,b,i=0;
	toptr t2,t4,t5;
	int c=1;
	  cout<<"Enter the first data to be entered\n";
	  cin>>a;
	  if(a!=-1)
	  {
	  	t=new node;
	  	t->id=a;
	  	cout<<"Enter the no count\n";
	  	cin>>b;
	  	t->count=b;
	  	t->next=null;
	  	t->trail=null;
	  }	create(t);
	  t5=t;
	  while(t5!=null)
	  {cout<<"starting\n";
	  c=1;i=0;
	  	while(c!=-1)
	  	{i++;
	     cout<<"Enter the first element else -1\n";
	     cin>>c;
	     if(c!=-1)
	     {
	  	 t2= search(t,c);
	  	 toptr t6=t5;
	  	 
//	  	 if(i==1)
//	  	 {
//		   	/*t5->trail=new tnode;
//	  	 	t5->trail->p=t2;cout<<"t5->trail->p->id  =  "<<t5->trail->p->id<<"\n";
//	  	 	t5->trail->next=null;*/
//	  	 	addbegin1(t5,t2);
//		   }
//	  	 else
//	  	 {
//	  	 	addend1(t5,t2);
//		    //cout<<"B  ";
//			/*t4=t5;
//	  	 	while(t4->trail->next!=null)
//	  	 	{
//	  	 		t4->trail=t5->trail->next;
//			}
//			   t4->trail->next=new tnode;
//			   t4->trail=t4->trail->next;
//			   t4->trail->p=t2;cout<<"t5->trail->p->id = "<<t5->trail->p->id<<" \n ";
//			   t4->trail->next=null;*/
		  while(t6->trail!=null)
		{cout<<"5555\n";
			cout<<"t2->trail->p2->data== "<<t6->trail->p->id<<" \n ";
			t6->trail=t6->trail->next;
		}
		   }
		 }
		 }
		 t5=t5->next;
	}
	display(t);
	print(t);
}
