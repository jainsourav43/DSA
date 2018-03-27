#include<iostream>
#define null NULL
#include<algorithm>
using namespace std;
typedef struct bstnode 
{
	int data;
	bstnode *rchild;
	bstnode *lchild;
}*bstptr;
void iterative(bstptr &t,int key)
{
	bstptr t1=t,t2=t;int flag=0;
	while(t2!=null)
	{
	//	cout<<"t2- >data ,t1->data =  "<<t2->data<<"  "<<t1->data<<endl;
		
		if(t1->data>key)
		{
			flag=0;
			t2=t1->lchild;
			if(t2)
			t1=t1->lchild;
		}
		else if(t1->data<key)
		{
			flag=1;
			t2=t1->rchild;
			if(t2)
			t1=t1->rchild;
		}
	}
	if(flag==0)
	{
		t1->lchild=new bstnode;
		t1=t1->lchild;
		t1->data=key;
		t1->lchild=null;
		t1->rchild=null;
	}
	else
	{
		t1->rchild=new bstnode;
		t1=t1->rchild;
		t1->data=key;
		t1->lchild=null;
		t1->rchild=null;		
	}	
}
	int a[40];

void create(bstptr &t,int low,int high)
{
	if(low<=high)
	{
		
	int	mid=(low+high)/2;
	if(t==null)
	{
		t=new bstnode;
		t->data=a[mid];
		t->lchild=null;
		t->rchild=null;
	}
	create(t->lchild,low,mid-1);
	create(t->rchild,mid+1,high);
	}
}
//void insert(bstptr &t,int key)
//{
//	if(t==null)
//	{
//		t=new bstnode;
//		t->data=key;
//		t->lchild=null;
//		t->rchild=null;
//	}
//	else if(key<t->data)
//	{
//		insert(t->lchild,key);
//	}
//	else
//	{
//		insert(t->rchild,key);
//	}
//}
//void create(bstptr &t)
//{
//	int temp=1;
//	if(t==null)
//	{
//		t=new bstnode;
//		cout<<"Enter the data to insert\n";
//		cin>>t->data;
//		t->lchild=null;
//		t->rchild=null;
//	}
////	bstptr t1=t;
//	while(temp!=-1)
//	{
//		cout<<"Enter the data to insert else -1\n";
//		cin>>temp;
//		if(temp!=-1)
//		{
//			iterative(t,temp);
//		}
//	}
//}

void inorder(bstptr t)
{
	if(t!=null)
	{
	inorder(t->lchild);
	cout<<t->data<<" ";
	inorder(t->rchild);
	}	
}
int main()
{
	bstptr t=null;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	create(t,0,n-1);
	inorder(t);
}
