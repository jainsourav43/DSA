#include<iostream>
#define null NULL
using namespace std;
typedef 
struct trnode
{
	int data;
	char key;
	trnode *lchild;
	trnode *rchild;
}*TRPTR;
void dlr(TRPTR t)
{	
     if(t!=NULL)
	{
			cout<<"(";
		cout<<t->key<<"  ";
		cout<<t->data<<"  ";
		
		cout<<")";
		dlr(t->lchild);
	
		dlr(t->rchild);
	}
}
void ldr(TRPTR t)
{
	if(t!=NULL)
	{
		
		ldr(t->lchild);
		cout<<"(";
		cout<<t->key<<"  ";
		cout<<t->data<<"  ";
		
		cout<<")";
		ldr(t->rchild);
	}
}
void rotateleft(TRPTR &k2)
{
    TRPTR k1;
	k1=k2->rchild;
	k2->rchild=k1->lchild;
	k1->lchild=k2;
	k2=k1;	
}
void rotateright(TRPTR &k2)
{
	TRPTR k1;
	k1=k2->lchild;
	k2->lchild=k1->rchild;
	k1->rchild=k2;
	k2=k1;
}
void insert(TRPTR  &t,int d,char c)
{
	if(t==NULL)
	{
	t=new trnode;
	t->lchild=NULL;
	t->rchild=NULL;
	t->data=d;
	t->key=c;
	}
	else if(t->key>c)
	{
		insert(t->lchild,d,c);
		if(t->rchild!=NULL&&t->data>t->rchild->data)
		{
			rotateleft(t);
		}
		else if(t->lchild!=NULL&&t->data>t->lchild->data)
		{
		rotateright(t);
		}
	}
	else if(t->key<c)
	{
		insert(t->rchild,d,c);
		if(t->rchild!=NULL&&t->data>t->rchild->data)
		{
		rotateleft(t);
		}
		else if(t->lchild!=NULL&&t->data>t->lchild->data)
		{
			rotateright(t);
		}
	}
}
void deletenode(TRPTR &t,char c)
{
	
}
int main()
{
	TRPTR t=NULL;
	int d;
	char c='a';
	while(c!='.')
	{
		cout<<"Enter the character   else '.'  :   ";
		cin>>c;if(c=='.')break;
		cout<<"Enter the data                  :   ";
		cin>>d;
		if(c!='.')
		{
			insert(t,d,c);
		}
	}
		ldr(t);
		cout<<endl;
		dlr(t);
	return 0;
}
