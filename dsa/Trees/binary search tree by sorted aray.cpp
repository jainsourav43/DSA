//program to create binary search tree from a sorted array by recursion
#include<iostream>
#include<cmath>
#define null NULL
int hi;
using namespace std;
typedef
struct bstnode
{
	bstnode *lchild;
	int data ;
	bstnode *rchild;
} *bstptr;
void ldr(bstptr t)
{
	if(t!=null)
	{
		ldr(t->lchild);
		cout<<t->data<<"   ";
		ldr(t->rchild);
	}
}
void dlr(bstptr t)
{
   // cout<<"CALLING\n";
	if(t!=null)
	{		cout<<t->data<<"   ";

		dlr(t->lchild);
		dlr(t->rchild);
	}
}
void lrd(bstptr t)
{
   // cout<<"CALLING\n";
	if(t!=null)
	{		
		lrd(t->lchild);
		lrd(t->rchild);
		cout<<t->data<<"   ";

	}
}
/*void create(bstptr t1,int s,int e,int a[])
{ cout<<"CALLING\n";hi--;
 bstptr t,t2;t=t1;int k1=0,k2=0;
if(s<=e)
{
    int mid=s+(e-s)/2;
    if(t==null)
    {
    	t=new bstnode;
    	t->data=a[mid];
    	t->lchild=null;
    	t->rchild=null;ldr(t);
	}
	else
	{t2=t;
	while(t2!=null)
	{cout<<"WHILE\n";
		if(a[s+(e-s)/2]<t->data)
		{cout<<"IF\n";k1=1;
		if(t->lchild!=null)
			t=t->lchild;
			t2=t2->lchild;
		}
		else
		{cout<<"ELSE\n";k2=1;
		if(t->rchild!=null)
			t=t->rchild;
			t2=t2->rchild;
		}ldr(t);
	}
	 if(k1==1)
		  {	
		  t->lchild=new bstnode;
	      t=t->lchild;
          t->data=a[mid];
       	  t->lchild=null;
     	  t->rchild=null;//create(t,s,mid-1,a);

	      }
	      else
	      {
	      t->rchild=new bstnode;
	      t=t->rchild;
          t->data=a[mid];
       	  t->lchild=null;
     	  t->rchild=null;//create(t,mid+1,e,a);

		  }
		  
	ldr(t);
}hi--;
if(hi)
{

    create(t,s,mid-1,a);
     create(t,mid+1,e,a);
}
}
}*/
void create1(bstptr &t,int s,int e,int a[])
{
	  int mid=s+(e-s)/2;
	if(s<=e)
	{
	if(t==null)
	{
		t=new bstnode;
		t->data=a[mid];
    	t->lchild=null;
    	t->rchild=null;
	}
		create1(t->lchild,s,mid-1,a);
		create1(t->rchild,mid+1,e,a);
    }
}
int in=0,size;
void create2(bstptr &t,int s,int e,int a[])
{
	if(s<=e)
	{
		if(t==null)
		{
		//	cout<<"s,e ,in= "<<s<<"  "<<e<<" "<<in<<endl;
		//	cout<<"a = "<<a[in]<<endl;
			t=new bstnode;
			t->data=a[in++];
			t->lchild=null;
			t->rchild=null;
			
		}
		int i1=in;
		while(a[in-1]>a[i1])
		{
			i1++;
		}
	//	cout<<"in,i1,e ="<<in<<" "<<i1<<" "<<e<<endl;
		if(in<=e)
		create2(t->lchild,in,i1-1,a);
		create2(t->rchild,i1,e,a);
	}
}
int main()
{   
   int n,i,j,k;
	bstptr t=null;
	cout<<"Enter the no.of elements in the array\n";
	cin>>n;int a[n];
	hi=log2(n);
	cout<<"Enter the array in sorted aray\n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	create2(t,0,n-1,a);
	cout<<"INORDER TRAVERSAL OF THE TREE IS\n";
	ldr(t);
	cout<<endl<<endl;
		cout<<"PREORDER TRAVERSAL OF THE TREE IS\n";
	dlr(t);
	
		cout<<endl<<endl;
		cout<<"POSTORDER TRAVERSAL OF THE TREE IS\n";
		lrd(t);
return 0;
}
