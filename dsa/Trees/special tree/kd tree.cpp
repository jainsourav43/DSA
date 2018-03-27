#include<iostream>
#define null NULL
using namespace std;
int s,j;
union u 
{
	int a;
	char b;
};
typedef
struct kdnode
{
	kdnode *lchild;
	int data[10];
	kdnode *rchild;
} *kdptr;
void insert(kdptr &t,int d[],int n)
{
	if(t==null)
	{
		t=new kdnode;
		for(int j=0;j<n;j++)
		{
			t->data[j]=d[j];
		}
		t->lchild=null;
		t->rchild=null;
	}
	else if(t->data[s]>d[s])
	{
		s=(s+1)%n;
		insert(t->lchild,d,n);
	}
	else if(t->data[s]<d[s])
	{
		s=(s+1)%n;
		insert(t->rchild,d,n);
	}
}
int  search(kdptr t,int d[],int n)
{
	if(t==null)
	return 0;
	else if(t->data[s]>d[s])
	{
		s=(s+1)%n;
		return search(t->lchild,d,n);
	}
	else if(t->data[s]<d[s])
	{
		s=(s+1)%n;
		return search(t->rchild,d,n);	
	}
	else
	{
		return 1;
	}
}
int main()
{
	kdptr t=null;
	int n=1,i;
		
	cout<<"enter the no. of elements else -1\n";
	cin>>n;
	int d[n],k[n];
	d[0]=1;
	while(d[0]!=-1)
	{
	if(n!=-1)
	{cout<<"Enter the elements else -1\n";
		for(i=0;i<n;i++)
		{
			cin>>d[i];
		}
		s=0;
		insert(t,d,n);
	}
    }
    s=0;
    cout<<"Enter the key  no. to be searched\n";
    for(i=0;i<n;i++)
     cin>>k[i];
    int ans=search(t,k,n);
    if(ans)
    {
    	cout<<"THE KEY IS PRESENT IN THE TREE \n";
	}
	else
	{
		cout<<"THE KEY IS NOT PRESENT IN THE TREE \n";
	}
	return 0;
}

