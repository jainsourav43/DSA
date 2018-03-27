#include<iostream>
#define null NULL
using namespace std;
typedef 
struct trnode
{
	int priority;
	char val;
	trnode *lchild;
	trnode *rchild;
}*trptr;
void dlr(trptr t)
{	
     if(t!=null)
	{
			cout<<"(";
		cout<<t->val<<"  ";
		cout<<t->priority<<"  ";
		
		cout<<")";
		dlr(t->lchild);
	
		dlr(t->rchild);
	}
}
void ldr(trptr t)
{
	if(t!=null)
	{
		
		ldr(t->lchild);
		cout<<"(";
		cout<<t->val<<"  ";
		cout<<t->priority<<"  ";
		
		cout<<")";
		ldr(t->rchild);
	}
}
void rotateleft(trptr &k2)
{
    trptr k1;
	k1=k2->rchild;
	k2->rchild=k1->lchild;
	k1->lchild=k2;
	k2=k1;	
}
void rotateright(trptr &k2)
{
	trptr k1;
	k1=k2->lchild;
	k2->lchild=k1->rchild;
	k1->rchild=k2;
	k2=k1;
}
void insert(trptr  &t,int d,char c)
{
	if(t==null)
	{
	t=new trnode;
	t->lchild=NULL;
	t->rchild=NULL;
	t->priority=d;
	t->val=c;
	}
	else if(t->val>c)
	{
		insert(t->lchild,d,c);
		if(t->rchild!=null&&t->priority>t->rchild->priority)
		{
			rotateleft(t);
		}
		else if(t->lchild!=null&&t->priority>t->rchild->priority)
		{
		   rotateright(t);
		}
	}
	else if(t->val<c)
	{
		insert(t->rchild,d,c);
		if(t->rchild!=null&&t->priority>t->rchild->priority)
		{
		rotateleft(t);
		}
		else if(t->lchild!=null&&t->priority>t->lchild->priority)
		{
			rotateright(t);
		}
	}
}
void deletenode(trptr &t,char c,int d)
{
	if(t->priority==d&&t->val==c)
	{	
	if(t->lchild!=null&&t->rchild!=null)
	{
			if(t->lchild->priority>t->rchild->priority)
			{
				rotateleft(t);
			}
			else
			{
				rotateright(t);	
			}
		
	}
	    else if(t->lchild==null&&t->rchild!=null)
		{
				rotateleft(t);	
		}
		else if(t->lchild!=null&&t->rchild==null)
		{
			rotateright(t);
		}
		if(t->lchild||t->rchild)
		{   
		    //cout<<"7\n";
		    if(t->lchild!=null&&t->lchild->val==c)
			deletenode(t->lchild,c,d);
			else if(t->rchild!=null&&t->rchild->val==c)
			{
				deletenode(t->rchild,c,d);
			}
		}
		else 
	   {//cout<<"8\n";
	   	t=null;
	   }
	}
	else if(t->val>c)
	{   cout<<"9\n";
		deletenode(t->lchild,c,d);
	}
	else if(t->val<c)
	{cout<<"10\n";
		deletenode(t->rchild,c,d);
	}
}
int main()
{
	trptr t=null;
	int d;
	char c='a';
	while(c!='.')
	{
		cout<<"Enter the character   else '.'  :   ";
		cin>>c;if(c=='.')break;
		cout<<"Enter the priority                  :   ";
		cin>>d;
		if(c!='.')
		{
			insert(t,d,c);
		}
	}
		ldr(t);
		cout<<endl;
		dlr(t);
		cout<<"Enter the val to delete  :   ";
		cin>>c;
		cout<<"Enter the priority to delete   :   ";
		cin>>d;
		deletenode(t,c,d);
		ldr(t);
		cout<<endl;
		dlr(t);
	return 0;
}
