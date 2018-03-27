#include<iostream>
#include<algorithm>
#define null NULL
#define ll long long 
using namespace std;
typedef
struct avlnode
{
	int data;
	avlnode *lchild;
	int height;
	avlnode *rchild;
} *avlptr;
int Height(avlptr t)
{
	if(t==null)
	{
		return -1;
	}
	else
	{
		return t->height;
	}
}
void rotateright(avlptr &k2)
{
//	cout<<"Rotate right\n";
	avlptr k1;
	k1=k2->lchild;
	k2->lchild=k1->rchild;
	k1->rchild=k2;//cout<<"k2->lchild "<<k2->rchild<<"  ";
	k2->height=max(Height(k2->lchild),Height(k2->rchild))+1;
	k1->height=max(Height(k1->lchild),Height(k2))+1;
	k2=k1;
}
void rotateleft(avlptr &k2)
{
	//cout<<"Rotate left\n";//cout<<"K2->data   "<<k2->data<<"   ";
	avlptr k1;
	k1=k2->rchild;
	//cout<<"k1->lchild  "<<k1->lchild<<"  ";
	k2->rchild=k1->lchild;
    k1->lchild=k2;//cout<<" k2->lchild  "<<k2->lchild<<"  ";cout<<" k2->rchild  "<<k2->rchild<<"  ";
    k2->height=max(Height(k2->lchild),Height(k2->rchild))+1;//cout<<"k2->height  "<<k2->height<<"  ";
    k1->height=max(Height(k1->rchild),Height(k2))+1;//cout<<"k1->height  "<<k1->height<<"  ";
    k2=k1;
}
void doubleright(avlptr &k3)
{
	//cout<<"Rotate double right\n";
	rotateleft(k3->lchild);
	rotateright(k3);
}
void doubleleft(avlptr &k3)
{
	//cout<<"Rotate double left\n";
	rotateright(k3->rchild);
	rotateleft(k3);
}
void insert(avlptr &t,int d)
{
	if(t==null)
	{
		t=new avlnode;
		t->data=d;
		//t->height=0;
		t->lchild=null;
		t->rchild=null;
	}
	else if(t->data>d)
	{  
	insert(t->lchild,d);
	if(Height(t->lchild)-Height(t->rchild)==2)
	{
		if(d<t->lchild->data)
		{
			rotateright(t);
		}
		else
		{
			doubleright(t);
		}
	}
	
	}
	else if(t->data<d)
	{
		insert(t->rchild,d);
		if(Height(t->rchild)-Height(t->lchild)==2)
		{//cout<<"if\n";
			if(d>t->rchild->data)
			{
			   // cout<<"if 2\n";
				rotateleft(t);
			}
			else
			{
			   // cout<<"else 1";
				doubleleft(t);
			}
		}
	}
	t->height=max(Height(t->lchild),Height(t->rchild))+1;
}
int search(avlptr t,int k)
{
	if(t==null)
	{
		return 0;
	}
	else if(t->data>k)
	{
		search(t->lchild,k);
	}
	else if (t->data<k)
	{
		search(t->rchild,k);
	}
	else
	{
		return 1;
	}
}
int main()
{
	ll n,q;
	avlptr t=null;
	cin>>n>>q;
	ll i,j,a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	ll t1[q];
	for(i=0;i<q;i++)
	{
		cin>>t1[i];
		if(t1[i]<=a[n-1]&&t1[i]>=a[0])
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
	
	return 0;
	
}
