#include<iostream>
#define null NULL
using namespace std;
int k;
union u
{
	int a;
	char b;
};
struct st
{
	union u un;
	int tag=0;
};
typedef
struct kdnode
{
	kdnode *lchild;
	kdnode *rchild;
	st s[10];	
}*kdptr;

bool search(kdptr t,int mod,st s[])
{
	if(t==null)
	return 0;
	if(t->s[mod%k].tag==0)
	{
		if(t->s[mod%k].un.a==s[mod%k].un.a)
		{
			return 1;
		}
		else if(t->s[mod%k].un.a>s[mod%k].un.a)
		{
			return search(t->lchild,mod+1,s);
		}
		else
		{
			return search(t->rchild,mod+1,s);
		}
	}
	else 
	{
		if(t->s[mod%k].un.b=s[mod%k].un.b)
		{
			return 1;
		}
		else if(t->s[mod%k].un.b>s[mod%k].un.b)
		{
			return search(t->lchild,mod+1,s);
		}
		else
		{
			return search(t->rchild,mod+1,s);
		}
	}
}
void print(kdptr t)
{
	if(t==null)
	return;
	cout<<"( ";
	for(int i=0;i<k;i++)
	{
		
		if(t->s[i].tag==0)
		{
			cout<<t->s[i].un.a<<"  ";
		}
		else
		{
			cout<<t->s[i].un.b<<"  ";
		}
		
	}
	cout<<" )";
	print(t->lchild);
	print(t->rchild);
}
void insert(kdptr &t,st s[],int mod)
{
	if(t==null)
	{
		t=new kdnode;
		for(int i=0;i<k;i++)
		{
			t->s[i]=s[i];
		}
		t->lchild=null;
		t->rchild=null;
	}
	else if(t->s[mod%k].tag==1)
	{
		if(t->s[mod%k].un.b>s[mod%k].un.b)
		{
			insert(t->lchild,s,mod+1);
		}
		else
		{
			insert(t->rchild,s,mod+1);
		}
	}
	else if(t->s[mod%k].tag==0)
	{
		if(t->s[mod%k].un.a>s[mod%k].un.a)
		{
			insert(t->lchild,s,mod+1);
		}
		else
		{
			insert(t->rchild,s,mod+1);
		}
	}
}

int main()
{
	kdptr t;
	cout<<"Entert the number of data \n";
	cin>>k;
	int choice;
	st s[k];
	while(1)
	{
	cout<<"Enter 1 for continue insertion otherwise -1\n";
	cin>>choice;
	if(choice==-1)
	break;	
	for(int i=0;i<k;i++)
	{
		cout<<"enter 1 for char and 0 for int \n";
		cin>>s[i].tag;
		if(s[i].tag==1)
		{
			cout<<"Enter character \n";
			cin>>s[i].un.b;
		}
		else
		{
			cout<<"Enter Integer \n";
			cin>>s[i].un.a;
		}
	}
	insert(t,s,0);
	}
}
