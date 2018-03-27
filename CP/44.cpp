//program to create binary search tree iteratively
#include<iostream>
#include<vector>
#define null NULL
using namespace std;
typedef
struct bstnode
{
	bstnode *lchild;
	int data ;
	bstnode *rchild;
} *bstptr;
vector <int> a;
void ldr(bstptr t,int i)
{
	if(t!=null)
	{
		ldr(t->lchild,i);
		//cout<<t->data<<"   ";
		a.push_back(t->data);
		ldr(t->rchild,i);
	}
}
bool check(vector<int> a)
     {cout<<"Calling 2\n";
     for(int i=0;i<a.size();i++)
{        for(int j=i+1;j<a.size();j++)
    if(a[i]<a[j])
    {
    continue;
}
 else
     {return 0;}
     }
     return 1;
}
void checkbst(bstptr t)
{cout<<"Calling\n";
	ldr(t,0);
	int k=check(a);
	if(k)
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"no\n";
	}
}
void findmin(bstptr t)
{
	while(t->lchild!=null)
	{
		t=t->lchild;
	}
	cout<<"minimum no."<<t->data<<endl;
}
void findmax(bstptr t)
{	
	while(t->rchild!=null)
	{
		t=t->rchild;
	}
	cout<<"maximum no."<<t->data<<endl;
}
void create1(bstptr t)
{
	bstptr t1,t2;int d=1;int k1,k2;
	 //cout<<"Enter the data or -1 to exit\n";
       //  cin>>d;
      
         while(d!=-1)
         {
          t1=t;t2=t;
          cout<<"Enter the data or -1 to exit\n";
          cin>>d;
          if(d!=-1)
          {
		  while(t2!=null)
		  {k1=0;k2=0;
		  	if(t1->data>d)
		  	{k1=1;
		  	if(t1->lchild!=null)
		  	t1=t1->lchild;	
		  	t2=t2->lchild;
			  }
			  else
			  {k2=1;
			    if(t1->rchild!=null)
			  	t1=t1->rchild;
			  	t2=t2->rchild;
			  }
			  
	      }
		  if(k1==1)
		  {	
		  t1->lchild=new bstnode;
	      t1=t1->lchild;
          t1->data=d;
       	  t1->lchild=null;
     	  t1->rchild=null;
	      }
	      else
	      {
	      	 t1->rchild=new bstnode;
	      t1=t1->rchild;
          t1->data=d;
       	  t1->lchild=null;
     	  t1->rchild=null;
		  }
		  	 
		}
}
}
void insert(bstptr &t,int k)
{
	if(t==null)
	{
	
		t=new bstnode;
		t->data=k;
		t->lchild=null;
		t->rchild=null;
	}
	else if(k<t->data)
	{
		insert(t->lchild,k);
	}
	else
	{
		insert(t->rchild,k);
	}
}
int main()
{   
    int d=1;
	bstptr t=new bstnode;
	
	cout<<"Enter the data\n";
    cin>>d;
	t->data=d;
	t->lchild=null;
	t->rchild=null;
	create1(t);
/*	while(d!=-1)
	{
		cout<<"ENter the data\n";
		cin>>d;
		if(d!=-1)
		insert(t,d);
	}*/
	//ldr(t);
	checkbst(t);
	cout<<endl;
	findmax(t);
	findmin(t);
	return 0;
}
