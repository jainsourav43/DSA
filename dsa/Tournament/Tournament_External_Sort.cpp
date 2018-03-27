#include<iostream>
#define null NULL
int n;
using namespace std;
int maxe(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
typedef
struct tonode
{
	int data;
	int flag=0;
	tonode *lchild;
	tonode *rchild;
}*toptr;
struct stack
{
	int size;
	int top;
	toptr e[50];
};
struct queue
{
	int size;
	toptr element[50];
	int front;
	int rear;
};
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
void push(stack &s1,toptr x )
{
	if(s1.top==s1.size-1)
	{
		cout<<"Overflow of stack\n";
	}
	else
	{
		s1.top++;
		s1.e[s1.top]=x;
	}
}
toptr pop(stack &s1)
{
	if(s1.top==-1)
	{
		cout<<"Underflow\n";
	}
	else
	{	
	return (s1.e[s1.top--]);
	}
}
void create(toptr &t1)
{	
	cout<<"Enter the no. of players \n";
	cin>>n;
    queue q;
	q.rear=-1;
	q.front=-1;
	q.size=50;
	toptr t[2*n-1];
	cout<<"Enter the scores of the players\n";
	int a[n];
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	t[i]=new tonode;
	t[i]->data=a[i];
	t[i]->lchild=null;
	t[i]->rchild=null;
	enque(q,t[i]);
	}
	toptr t2,t3;int j=n,k=0;int a2=0,a1=0,i1,i2,k1=0;
	while(j<2*n-1)
	{  // cout<<"%%\n";
	    k++;
	    if(q.front!=-1)
	    {
		t2=deque(q);
		t3=deque(q);
		t[j]=new tonode;
		t[j]->data=min(t2->data,t3->data);
		t[j]->lchild=t2;
		t[j]->rchild=t3;
		enque(q,t[j]);
		j++;
	    }
	}
	t1=t[2*n-2];
}
void create2(toptr &t)
{
	int  ch;
	cout<<"Enter the character to input or '-2' to return \n";
    cin>>ch;
	if(ch==-2)
	return;
	else if(t==null)
	{
    	
		t=new tonode;
		t->data=ch;
		t->lchild=null;
		t->rchild=null;
	}
    cout<<"AGAIN ENTER THE LEFT NODE\n";
	create2(t->lchild);
	cout<<" Your current  position is  "<<t->data<<endl;
		cout<<"ENTER THE RIGHT NODE AT YOUR CURRENT POSITION\n";
	create2(t->rchild);
	cout<<"Your current   position is  "<<t->data<<endl;
}
void restore2(toptr t)
{
	if(t!=null)
	{
		restore2(t->lchild);
		if(t->lchild!=null&&t->rchild!=null)
		{
			t->data=max(t->lchild->data,t->rchild->data);
			//t->data=t->lchild->data+t->rchild->data;
		}
		restore2(t->rchild);
		if(t->lchild!=null&&t->rchild!=null)
		{
		t->data=max(t->lchild->data,t->rchild->data);
		//t->data=t->lchild->data+t->rchild->data;
		}
	
	}
}
void restore1(toptr &t,int d)
{
	if(t!=null)
	{
	//cout<<"OOO\n";
	if(t->lchild==null&&t->rchild==null)
	{   
	    //cout<<"h\n";
		t->data=10000;
		t->flag=-1;
	}
	 if(t->lchild!=null)
	 {
	if(t->lchild->data==d)
	{
	//cout<<"y\n";
    	restore1(t->lchild,d);
    	t->data=min(t->lchild->data,t->rchild->data);
    }
    }
	 if(t->rchild!=null)
	{//cout<<"i\n";
	if(t->rchild->data==d)
	restore1(t->rchild,d);
	t->data=min(t->lchild->data,t->rchild->data);
    
	}
	}
}
void sorting(toptr t,int n1)
{
	int u=0;
 // cout<<"FF\n";
  //cout<<"t->data   "<<t->data<<" ";
	while(u<n1)
	{
	 u++;
//	cout<<"ttt\n";
	cout<<"  "<<t->data<<"  ";

	restore1(t,t->data);
    }	//cout<<"KK\n";
}
void dlr(toptr t)
{
	if(t!=null)
	{
		cout<<t->data<<"  ";
		dlr(t->lchild);
		dlr(t->rchild);
	}
}
int main()
{
	toptr t=null;	
	create(t);//restore2(t);
	cout<<"DLR if \n";
	dlr(t);cout<<endl;	
	sorting(t,n);cout<<endl;
	//	dlr(t);cout<<endl;
//	dlr(t);
	return 0;
}
