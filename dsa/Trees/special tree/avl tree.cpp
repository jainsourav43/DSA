#include<iostream>
using namespace std;
typedef
struct avlnode
{
	int data;
	avlnode *lchild;
	int bal;
	avlnode *rchild;
} *avlptr;
void insert(avlptr t,int d)
{
	if(t==null)
	{
		t=new avlnode;
		t->data=d;
		t->bal=0;
		t->lchild=null;
		t->rchild=null;
		k3=t;
	}
	else if(t->data>d)
	{  
	k1=t;
		t=t->lchild;
	}
	else
	if(t->data<k)
	{
		k2=t;
		t=t->rchild;
	}
}
int main()
{
	avlptr t=null;int d;
	cout<<"Enter the data\n";
	cin>d;
	insert(t,d);
}
