#include<iostream>
#define null NULL
using namespace std;
int m;
typedef
struct gnode
{
	int data;
	gnode *par;
	gnode **next;
	int count;
} *gptr;
typedef 
struct btnode
{
	int data;
	btnode *lchild;
	btnode *rchild;
}*btptr;
void insertbt(btptr &t1,gptr t2,int p)
{
	cout<<"Create1 of binary\n";
	if(t1==null)
	{
		t1=new btnode;
		t1->data=t2->data;
		t1->lchild=null;
		t1->rchild=null;
	
	}
	else if(t1->data==t2->par->data)
	{
	if(p%2==0)
		{
		t1->lchild=new btnode;
		t1=t1->lchild;
		t1->data=t2->data;
		t1->lchild=null;
		t1->rchild=null;
	   }
	   else
	   {
	   	t1->rchild=new btnode;
		t1=t1->rchild;
		t1->data=t2->data;
		t1->lchild=null;
		t1->rchild=null;
	   }	
	}
	else 
	{
	insertbt(t1->lchild,t2,p);
	insertbt(t1->rchild,t2,p);
}
}
void create(gptr &g,gptr pa)
{
	int c,i,d,j,k;
	cout<<"\nEnter the data otherwise -1\n";
	cin>>d;
	if(d==-1)
	{
		return ;
	}
	cout<<"\nEnter the number of nodes\n";
	cin>>c;
	if(g==null)
	{
		g=new gnode;
		g->data=d;
		g->count=c;
		g->par=pa;
		g->next=new gnode*[(g->count)];
        for(int h=0;h<g->count;h++)
        {
        g->next[h]=null;
        }
	} 
		for(int f=0;f<g->count;f++)
		{
			create(g->next[f],g);
			cout<<"\nYour Current location is \n  "<<g->data;
        }
}
int  check(gptr t)
{
	cout<<"CHeck\n";
	int j=0;
	for(int i=0;i<=t->count;i++)
	{
		if(t->next[i]!=null)
		{
			 j=1;
		}
	}
	if(j==0)
	return 1;
	else 
	return 0;
}
int find(gptr t)
{ 
    int i;
	for(i=0;i<3;i++)
	{
	cout<<"Kk= "<<t->count<<"\n";	
	
	}
}
void transverse(gptr &g,btptr &t2,int in)
{	
	gptr t=g;int m;
    int k=0;int che;
    if(g!=null)
    {
    m=find(g);
	for(int y=m;y<t->count;y++)
	{
		if(t->count==0)
		{
	if(g!=null)
	{k++;
	if(k<=2)
	{cout<<"FOR\n";
	insertbt(t2,g,y);	
    che =check(g);
	 if(che==1)
	 {cout<<"CHe\n";
	 	if(g->par!=null)
	 	g->par->next[in]==null;
	     else
	     g=null;
	 }
	if(g->count>y)
	{ cout<<"Again\n";
	transverse(t->next[y],t2,y);
    }  
     }
   } 
}
}
}
}
void ldr(gptr t)
{
	if(t!=null)
	{
		if(t->count==0)
		{
			ldr(t->next[0]);
		}
		cout<<t->data<<"  ";
		if(t->count>=1)
		ldr(t->next[1]);
	}
}
void ldr(btptr t)
{
	if(t!=null)
	{
		ldr(t->lchild);
		cout<<t->data<<"  ";
		ldr(t->rchild);
	}
}
int main()
{
	gptr g=null;btptr t2=null;
	cout<<"Enter the maximumno of paths \n";
	cin>>m;
	create(g,null);
	int i=0;
	while(g!=null)
	{t2=null;
	transverse(g,t2,0);
      ldr(t2);
	}
	
}

