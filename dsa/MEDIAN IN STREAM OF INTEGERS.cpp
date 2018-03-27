#include <iostream>
using namespace std;
#define null NULL
typedef
struct avlnode
{
	int data;
	avlnode *lchild;
	int height;
	avlnode *rchild;
	int lcount;
}*avlptr;
struct mytree
{
	avlptr l;
	avlptr r;
	int data;
};
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
	//cout<<"Rotate right\n";
	avlptr k1;
	k1=k2->lchild;
	k2->lchild=k1->rchild;
	k1->rchild=k2;
	k2->height=max(Height(k2->lchild),Height(k2->rchild))+1;
	k1->height=max(Height(k1->lchild),Height(k2))+1;
	k2=k1;
}
void rotateleft(avlptr &k2)
{
	//cout<<"Rotate left\n";//cout<<"K2->data   "<<k2->data<<"   ";
	avlptr k1;
	k1=k2->rchild;
	k2->rchild=k1->lchild;
    k1->lchild=k2;//cout<<" k2->lchild  "<<k2->lchild<<"  ";cout<<" k2->rchild  "<<k2->rchild<<"  ";
    k2->height=max(Height(k2->lchild),Height(k2->rchild))+1;//cout<<"k2->height  "<<k2->height<<"  ";
    k1->height=max(Height(k1->rchild),Height(k2))+1;//cout<<"k1->height  "<<k1->height<<"  ";
    k2=k1;
}
void doubleright(avlptr &k3)
{
//	cout<<"Rotate double right\n";
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
		{
		   // cout<<"if\n";
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
int count1=0,count2=0;
void findright(avlptr t)
{
    if(t==null)
    return ;
    count1++;
    findright(t->lchild);
    findright(t->rchild);
}
void findleft(avlptr t)
{
    if(t==null)
    return ;
    count2++;
    findright(t->lchild);
    findright(t->rchild);
}
int main() {
	//code
	
	int n;
	cin>>n;
//	avlptr t=null;
	mytree *my;
	my=new mytree;
	my->l=null;
	my->r=null;
	int a[n+1],i,j;
	cin>>a[1];
	cout<<a[1]<<endl;
	insert(my->l,a[1]);
	 my->data=a[i];
	 count2=1;count1=0;
	for(i=2;i<=n;i++)
	{
	    cin>>a[i];
	    if(a[i]>my->data)
	    {
	    insert(my->r,a[i]);
	    count1++;
	   	}
	   	else
	   	{
	   	insert(my->l,a[i]);
	   	count2++;
		}
		if(count1==count2)
		{
			my->data=(my->l->data+my->r->data)/2;
		}
		else if(count1>count2)
		{
			my->data=my->l->data;
		}
		else
		{
			my->data=my->r->data;
		}
	    
	}
	
	
	
	
	return 0;
}
