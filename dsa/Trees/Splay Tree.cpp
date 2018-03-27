#include<iostream>
#define null NULL
using namespace std;
typedef
struct spnode
{
	int data;
	spnode *lchild;
	spnode *rchild;
} *sptr;
void initialise(sptr &t)
{
	t=new spnode;
	t->lchild=NULL;
	t->rchild=NULL;
	t->data=0;
}
void insert(sptr &t,int d)
{
	if(t==null)
	{
	t=new spnode;
	t->lchild=NULL;
	t->rchild=NULL;
	t->data=d;
	}
	else if(t->data>d)
	{
		insert(t->lchild,d);
	}
	else if(t->data<d)
	{
		insert(t->rchild,d);
	}
}
void ldr(sptr t)
{
	if(t!=null)
	{
		ldr(t->lchild);
		cout<<t->data<<"  ";
		ldr(t->rchild);
	}
}
void ldr1(sptr t)
{
	if(t!=null)
	{
		cout<<t->data<<"  ";
		ldr1(t->lchild);
		ldr1(t->rchild);
	}
}
void rotateleft(sptr &k2)
{cout<<"14\n";
    sptr k1;
	k1=k2->rchild;
	k2->rchild=k1->lchild;
	k1->lchild=k2;
	k2=k1;	
}
void rotateright(sptr &k2)
{
	sptr k1;
	k1=k2->lchild;
	k2->lchild=k1->rchild;
	k1->rchild=k2;
	k2=k1;
}
void zigzigr(sptr &k3)
{//cout<<"10\n";
	rotateleft(k3->rchild);
	rotateleft(k3);
}
void zigzigl(sptr &k3)
{//cout<<"11\n";
	 rotateright(k3->lchild);
	  rotateright(k3);
}

void zigzagl(sptr &k3)
{//cout<<"12\n";
	rotateleft(k3->lchild);
	rotateright(k3);
}
void zigzagr(sptr &k3)
{
	rotateright(k3->rchild);
	rotateleft(k3);
}
int  search(sptr &t,int k)
{
    if(t==null)
	return 0;
	else if(t->lchild!=null&&t->lchild->data==k)
	{
		rotateright(t);
		return 0;
	}
	else if(t->rchild!=null&&t->rchild->data==k)
	{
		rotateleft(t);
		return 0;
	}
	else if(t->rchild!=null&&t->rchild->rchild!=null&&t->rchild->rchild->data==k)
	{
		zigzigr(t);//cout<<"1\n";
		return 0;
	}
	else if(t->lchild!=null&&t->lchild->lchild!=null&&t->lchild->lchild->data==k)
	{
		zigzigl(t);//cout<<"2\n";
		return 0;
	}
	else if(t->rchild!=null&&t->rchild->lchild!=null&&t->rchild->lchild->data==k)
	{
		zigzagr(t);//cout<<"3\n";
		return 0;
	}
	else if(t->lchild!=null&&t->lchild->rchild!=null&&t->lchild->rchild->data==k)
	{
		zigzagl(t);//cout<<"4\n";
		return 0;
	}
	else if(t->data>k)
	{
		search(t->lchild,k);//cout<<"7\n";
	}
	else if(t->data<k)
	{
		search(t->rchild,k);//cout<<"8\n";
	}
}
int main()
{
	sptr t=null;int d,k;
	while(d!=-1)
	{
		cout<<"Enter the data else -1   :  ";
		cin>>d;
		if(d!=-1)
		{
			insert(t,d);
		}
	}
	 ldr(t);
	 cout<<endl;
	 ldr1(t);
	cout<<"Enter the data to be searched\n";
	cin>>k;
     while(t->data!=k)
	 {
	 	search(t,k);
	 }
	 cout<<" ans=  "<<t->data<<"  ";
	 cout<<endl;ldr(t);	
	 cout<<endl;
	 ldr1(t);
}
