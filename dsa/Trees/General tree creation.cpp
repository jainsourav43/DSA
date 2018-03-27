//General tree creation(Iteratively and Recursively) along with BFT nd DFT 
#include<iostream>
#define null NULL
using namespace std;
typedef
struct gtnode
{
	char  data;
	gtnode *fc;
	gtnode *ns;
}*gtptr;
struct queue
{
	int size;
    gtptr element[50];
	int front;
	int rear;
};
bool empty(queue q)
{
	if(q.front==-1)
	return 1;
	else
	return 0;
}
void enque(queue &q,gtptr x)
{//cout<<"ENQUUE\n";
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
gtptr deque(queue &q)
{
	int t;
//cout<<"DEQUE\n";
	
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
		//cout<<"END OF DEQUE\n";
		return q.element[t];
    }    	
}
void create(gtptr &t)
{   
    char  d;
    cout<<"Enter the data to enter or '.' to next sibling\n";
    cin>>d;
    if(d=='.')
    return ;
    else if(t==null)
	{
		t=new gtnode;
		t->data=d;
		t->fc=null;
		t->ns=null;
	}
	cout<<"Again enter the first child\n";
	create(t->fc);
	cout<<" Your current  position is  "<<t->data<<endl;
	cout<<"Enter the next sibling at your current position\n";
	create(t->ns);
	cout<<" Your current  position is  "<<t->data<<endl;
}
void create1(gtptr &t)
{
	 char d;int c;
     gtptr t1,t2,t3;
     d='a';
     cout<<"Enter the data to enter or '.' to next sibling\n";
     cin>>d;
     t=new gtnode;
     t->fc=null;
     t->ns=null;
     t->data=d;
	while(d!='.')
	{
	 t2=t;t1=t;int k1,k2;
	 cout<<"Enter the data to enter or '.' to next sibling\n";
     cin>>d;
     if(d!='.')
     {
       while(t2!=null)
       {k1=0;k2=0;
       	cout<<"Enter 1 for first child or 2 to next sibling\n";
       	cin>>c;
       	if(c==1)
        { 
	       k1=1;
       		if(t1->fc!=null)
       		t1=t1->fc;
       		t2=t2->fc;
       		if(t2!=null)
       		cout<<"Your current location is  "<<t2->data<<"\n";
		}
		else if(c==2)
		{  
		    k2=1;
			if(t1->ns!=null)
			t1=t1->ns;
			t2=t2->ns;
			if(t2!=null)
			cout<<"Your current location is  "<<t2->data<<"\n";
		}
	   }
	   if(k1==1)
	   {
	   	t1->fc=new gtnode;
	   	t1=t1->fc;
	   	t1->data=d;
	   	t1->ns=null;
	   	t1->fc=null;
	   }
	   else if(k2==1)
	   {
	   	 t1->ns=new gtnode;
	     t1=t1->ns;
	     t1->data=d;
	     t1->fc=null;
	     t1->ns=null;
	   }
	 }
	}
	
}
//void create3(gtptr t)
//{
//	stack k;
	
//}
//void dispersion()
void dlr(gtptr t)
{
	if(t!=null)
	{
	cout<<t->data<<"   ";
	dlr(t->fc);
	dlr(t->ns);
    }
}
void dft(gtptr t)
{
	if(t!=null)
	{
		dft(t->fc);
		cout<<t->data<<"   ";
		dft(t->ns);
    }
}
void dft1(gtptr g)
{
	if(g!=null)
	{
		cout<<g->data<<"   ";
		dft1(g->ns);
		dft1(g->fc);
	}
}
void levelorder(gtptr t)
{
	if(t!=null)
	{
		cout<<t->data<<"  ";
		levelorder(t->ns);
		levelorder(t->fc);
	}
}
void levelorder1(gtptr t)
{
	queue q;
	gtptr t1,t2;
	q.size=50;
    q.rear=-1;
    q.front=-1;
    enque(q,t);int c=0,c1=0;
    while(!empty(q))
    {
    	t1=deque(q);
    	cout<<t1->data<<"   ";
		if(t1->fc!=null&&c1==0)
		{
			enque(q,t1->fc);
			t1=t1->fc;
		while(t1->ns!=null&&((q.element[q.front]->data!=t1->data)||c==0))
    	{
    		enque(q,t1->ns);
    		t1=t1->ns;
    		c++;
		}
		}
		c--;t2=t1;
	}
}
int main()
{
	gtptr t=null;
	create(t);cout<<endl<<endl;
	levelorder1(t);cout<<endl<<endl;
	dlr(t);cout<<endl;
	dft(t);cout<<endl;
	dft1(t);
//	dispersion(t);
	
	return 0;
}
