#include<iostream>
#define null NULL
#include<queue>
using namespace std;
typedef
struct tonode 
{
	tonode *lchild;
	int data;
	tonode *rchild;
}*toptr;
int n;
void create(toptr &t1)
{

	cout<<"ENter the no. of elements\n";
	cin>>n;
	int i,j;
	toptr t[2*n+1],a;
	queue<toptr> q;
	cout<<"ENter the Scores\n";
	for(i=0;i<n;i++)
	{
		int a;
		cin>>a;
		t[i]=new tonode;
		t[i]->data=a;
		t[i]->lchild=null;
		t[i]->rchild=null;
		q.push(t[i]);
	}
	j=n;
	toptr temp1,temp2;
	while(j<2*n-1)
	{
		temp1=q.front();
		q.pop();
		temp2=q.front();
		q.pop();
		t[j]=new tonode;
		t[j]->data=max(temp1->data,temp2->data);
		cout<<"T->data= "<<t[j]->data<<endl;
		t[j]->lchild=temp1;
		t[j]->rchild=temp2;
		q.push(t[j]);
		j++;
	}
	t1=t[2*n-2];
	
	
}
void restore(toptr t,int key)
{
	if(t==null)
	return ;
	if(t->data==key)
	{
		if(t->lchild==null&&t->rchild==null)
		{
			t->data=-1;
		}
		else if(t->lchild->data==key)
		{
			restore(t->lchild,key);
			t->data=max(t->lchild->data,t->rchild->data);
		}
		else
		{
			restore(t->rchild,key);
			t->data=max(t->lchild->data,t->rchild->data);
		}		
	}
	
}
void sorting(toptr t,int n)
{
	int i=0;
	while(i<n)
	{
		cout<<t->data<<endl;
		restore(t,t->data);
		i++;
	}
	
}
int main()
{
	toptr t=null;
	create(t);
	sorting(t,n);
}
