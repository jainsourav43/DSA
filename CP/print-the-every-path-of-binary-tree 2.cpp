#include<iostream>
#define null NULL
#include<cmath>
using namespace std;
//int a[30];
typedef
struct btnode
{
	btnode *lchild;
	int  data ;
	btnode *rchild;
} *btptr;
struct queue
{
	int size;
    btptr element[50];
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
void enque(queue &q,btptr x)
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
btptr deque(queue &q)
{
	int t;
//	cout<<"DEQUE\n";
	
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
void levelorder(btptr t)
{
	//out<<"CALLING\n";
	queue q;btptr t1;
	q.size=50;
q.rear=-1;
q.front=-1;
	enque(q,t);
	while(!empty(q))
	{
		t1=deque(q);
		//cout<<"t1"<<t1<<endl;
		cout<<t1->data<<" ";
		if(t1->lchild!=null)
		{//cout<<"IF1\n";
			enque(q,t1->lchild);
		}
		if(t1->rchild!=null)
		{//cout<<"IF2\n";
			enque(q,t1->rchild);
		}
	}
}
void levelorder1(btptr t)
{
	//cout<<"CALLING\n";
	queue q;btptr t1;int i=0,j=0;
	q.size=50;
q.rear=-1;
q.front=-1;
	enque(q,t);
	while(!empty(q))
	{//cout<"WHILe\n";
	i++;j++;
 		t1=deque(q);
 		//if(t1!=null)
 		//enque(q,null);
 		//if(t1==null)
 		//{
 		//	cout<<endl;
 			//continue;
	//	 }
		//cout<<"t1"<<t1<<endl;
	//	if(t1!=null)

		cout<<t1->data<<" ";
			if(j==int (pow(2,i))-1)
	cout<<endl;
		if(t1!=null&&t1->lchild!=null)
		{//cout<<"IF1\n";
			enque(q,t1->lchild);j++;
		}
		if(t1!=null&&t1->rchild!=null)
		{//cout<<"IF2\n";
			enque(q,t1->rchild);j++;
		}
	}
}
void ldr(btptr t)
{
   // cout<<"CALLING\n";
	if(t!=null)
	{
		ldr(t->lchild);
		cout<<t->data<<"   ";
		ldr(t->rchild);
	}
}
void dlr(btptr t,int i)
{
   static int a[30];
   // cout<<"CALLING\n";
	if(t!=null)
	{  a[i]=t->data;
	i++;
	    //cout<<t->data<<"   ";
		dlr(t->lchild,i);
		if(t->lchild==null&&t->rchild==null)
        {
		for( int j=0;j<i;j++)
		{
		   cout<<a[j]<<"  ";
		}
		}
		cout<<endl;
		dlr(t->rchild,i);
	}
}
void lrd(btptr t)
{
   // cout<<"CALLING\n";
	if(t!=null)
	{		
		lrd(t->lchild);
		lrd(t->rchild);
		cout<<t->data<<"   ";

	}
}
void create(btptr &t)
{

	btptr t1,t2;
	int  ch;
	cout<<"Enter the character to input or '-11' to return \n";
	cin>>ch;
	if(ch==-1)
	return;
	else if(t==null)
	{
		t=new btnode;
		t->data=ch;
		t->lchild=null;
		t->rchild=null;
	}

	create(t->lchild);
	cout<<"t->data  after calling left   "<<t->data<<endl;
	create(t->rchild);
	cout<<"t->data  after calling right   "<<t->data<<endl;
}

int main()
{
	btptr t=null;
	create(t);
	int i=0;
	cout<<"PREORDER TRAVERSAL OF TREE IS: \n";
	dlr(t,i);
	cout<<endl;
		cout<<"POSTORDER TRAVERSAL OF TREE IS: \n";
	lrd(t);cout<<endl;
		cout<<"INORDER TRAVERSAL OF TREE IS: \n";

	ldr(t);cout<<endl;
	cout<<"LEVELORDER TRAVERSAL OF THE TREE IS\n";
	levelorder(t);
	cout<<endl;
	//cout<<"LEVELORDER TRAVERSAL OF  SECOND TYPE IN THE TREE IS\n";
	//levelorder1(t);
	return 0;
}
