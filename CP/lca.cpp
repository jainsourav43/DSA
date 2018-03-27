#include<iostream>
#include<vector>
#define null NULL
#include<cmath>
using namespace std;
vector <int> b,c;int k2=0;
int d[1000];
typedef
struct btnode
{
	btnode *lchild;
	int data ;
	btnode *rchild;
} *btptr;
struct queue1

{
	int size;
    btptr element[50];
	int front;
	int rear;
};
/*bool empty(queue q)
{
	if(q.front==-1)
	return 1;
	else
	return 0;
}
void enque(queue &q,btptr x)
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
btptr deque(queue &q)
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
void levelorder(btptr t)
{
	cout<<"CALLING\n";
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
{	queue q;btptr t1;int i=0,j=1;	//cout<<"CALLING\n";
	q.size=50;
    q.rear=-1;
    q.front=-1;
	enque(q,t);
	while(!empty(q))
	{
	    i++;
 		t1=deque(q);
 		if(i==1)
 		enque(q,null);
 		if(t1==null&&i>=pow(2,j)-1)
 		{j++;
 		enque(q,null);
 	     }
 		if(t1==null)
 			cout<<endl;
 		//	continue;
		//cout<<"t1"<<t1<<endl;
		if(t1==null)
		i+=2;
		if(t1!=null)
       { 
		cout<<t1->data<<" ";
		
		//	if(j==int (pow(2,i))-1)
	//cout<<endl;
		if(t1!=null&&t1->lchild!=null)
		{//cout<<"IF1\n";
			enque(q,t1->lchild);i++;
		}
		if(t1!=null&&t1->rchild!=null)
		{//cout<<"IF2\n";
			enque(q,t1->rchild);i++;
		}
	 }  
	}
}
/*void ldr(btptr t)
{
   // cout<<"CALLING\n";
	if(t!=null)
	{
		ldr(t->lchild);
		cout<<t->data<<"   ";
		ldr(t->rchild);
	}
}*/
/*void dlr(btptr t)
{
   // cout<<"CALLING\n";
	if(t!=null)
	{		cout<<t->data<<"   ";

		dlr(t->lchild);
		dlr(t->rchild);
	}
}*/
/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

btptr  ldr(btptr t,int y)
{
    cout<<"CALLING 3\n";
	if(t!=null)
	{
		ldr(t->lchild,y);
		//cout<<t->data<<"   ";
        if(t->data==y)
            {
return t;
}
		ldr(t->rchild,y);
	}if(k2==1)
    return null;
}
void dlr(btptr  t,int i,int v1,int v2)
{
cout<<"CALLING 1 \n";
static int a[30];
	if(t!=null)
	{  a[i]=t->data;
	   i++;
		dlr(t->lchild,i,v1,v2);
		if(t->data==v1)
        {cout<<"@@@@\n";
		for( int j=0;j<i;j++)
		{
            b.push_back(a[j]);
		   cout<<a[j]<<"  ";
		}
		}
     if(t->data==v2)
         {cout<<"####\n";
      for(int j=0;j<i;j++)
          {cout<<"W   ";
          	cout<<a[j]<<"   ";
      c.push_back(a[j]);
      }
     }
		dlr(t->rchild,i,v1,v2);
	}
}  
void  lca(btptr t, int v1,int v2)
{
	cout<<"Calling \n";int d;
   dlr(t,0,v1,v2);
   int j=0,i;
   for(i=0;i<b.size();i++)
   {
       for(int k=0;k<c.size();k++)
       {
       {
       if(b[i]==c[k])
           {
        ///d[j]=b[j];
           //j++;
           cout<<"Ans   "<<b[i];
           d=b[i];cout<<"d  "<<d;break;
       }
       if(b[i]==c[k])
       {
       	break;
	   }
}
   }
}
cout<<"D  "<<d;
   // sort(d,d+j);
    btptr p=ldr(t,d);
    cout<<p->data<<"  ";
   //return p;
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
	cout<<"Enter the character to input or '-1' to return \n";
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
/*	cout<<"PREORDER TRAVERSAL OF TREE IS: \n";
	dlr(t);
	cout<<endl;
		cout<<"POSTORDER TRAVERSAL OF TREE IS: \n";
	lrd(t);cout<<endl;
		cout<<"INORDER TRAVERSAL OF TREE IS: \n";

	ldr(t);cout<<endl;
//	cout<<"LEVELORDER TRAVERSAL OF THE TREE IS\n";
//	levelorder(t);
	cout<<endl;
	cout<<"LEVELORDER TRAVERSAL OF  SECOND TYPE IN THE TREE IS\n";
	levelorder1(t);*/
	cout<<"Enter the v1 na dv2\n";
	int v1,v2;
	cin>>v1>>v2;
	lca(t,v1,v2);
	return 0;
}
