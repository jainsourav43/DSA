#include<iostream>
#include<bitset>
#include<string.h>
#define null NULL
using namespace std;
int i=0,size;
typedef
struct dtnode
{
	dtnode *lchild;
	char data[10];
	dtnode *rchild;
} *dtptr;
void ldr(dtptr t)
{
	if(t!=null)
	{
		ldr(t->lchild);
		cout<<t->data<<"   ";
		ldr(t->rchild);
	}
}
void dlr(dtptr t)
{
	if(t!=null)
	{
		cout<<t->data<<"   ";
		dlr(t->lchild);
		dlr(t->rchild);
	}
}
void insert(dtptr &t,char d[])
{
	if(t==null)
	{
		t=new dtnode;
		strcpy(t->data,d);
		t->lchild=null;
		t->rchild=null;
	}
	else 
	{
		while(t->data[i]==d[i])
		i++;
		if(t->data[i]>d[i])
		{
			i=(i+1)%size;
		    insert(t->lchild,d);
	    }
		else
		{
			i=(i+1)%size;
		    insert(t->rchild,d);
		}   
	}
}
int main()
{
	dtptr t=null;
	char d[10]; 
	cout<<"Enter the string else '.'\n";
    cin>>d;
    while(strcmp(d,"end")!=0)
    { 
	i=0;
    size=strlen(d);
    insert(t,d);
    cout<<"Enter the string else 'end'\n";
    cin>>d;
    }
    ldr(t);
    cout<<endl;
    dlr(t);
}
